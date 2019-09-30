//
// Created by marten on 26-09-19.
//
#include <iterator>
#include <iostream>
#include "../include/HuffmanTree.h"
#include "HuffmanList.h"
// For to_ulong && to_string
#include <bitset>

HuffmanTree::HuffmanTree(std::string text) {
    compress(text);
}

HuffmanTree::HuffmanTree(char ** text) {
    compress(reinterpret_cast<const char *>(text));
}

HuffmanTree::~HuffmanTree() = default;

void HuffmanTree::compress(std::string text) {
    // ... insert items in list
    for(char c : text){
        int ei = itemList.find(c);
        // If lists.find(c) returns a treeChar
        if(ei != -1){
            itemList.at(ei).frequency++;
            continue;
        }
            // Otherwise push it in the list
            itemList.push_back({c, 1});

    }

    // After all elements have been inserted order the list
    itemList.order();

    // Put every last 2 items together with a treeChar that points to the 2 items
    // end up with a single item that points to 2 items which point to 2 items etc.
    // After every iteration the size shrinks by 1
    int i = itemList.size()-1;

    while(itemList.size() > 1) {

        // Get data from the last 2 items from the list

        treeChar *left = new treeChar({
            itemList.at(i).character,
            itemList.at(i).frequency,
            itemList.at(i).leftItem,
            itemList.at(i).rightItem
        });
        treeChar *right = new treeChar({
            itemList.at(i - 1).character,
            itemList.at(i - 1).frequency,
            itemList.at(i - 1).leftItem,
            itemList.at(i - 1).rightItem
        });

        // Point to the last 2 items of the list and sum their frequency
        treeChar *sum = new treeChar;
        sum->leftItem = left;
        sum->rightItem = right;
        sum->frequency = left->frequency + right->frequency;
        sum->character = '\0';

        // Remove the last 2 items from the list as they are now pointed to by the sum
        // TODO: check if this erases the right items
        itemList.erase(itemList.end()-2, itemList.end());

        // Insert the itemList and order the list
        itemList.push_back(*sum);
        itemList.order();
        i--;
    }
    std::vector<bool> leftBitset = {false};
    std::vector<bool> rightBitset = {true};

    createLookupTable(itemList[0].rightItem, rightBitset);
    createLookupTable(itemList[0].leftItem, leftBitset);


    for(auto c : text){
        std::vector<bool> b = find(c);
        compressedText.insert(compressedText.end(), b.begin(), b.end());
    }

    for(auto b : compressedText){
        std::cout << b;
    }

    std::cout << '\n' << compressedText.size() << std::endl;
    std::cout << text.length() << std::endl;

    for(auto b : lookupTable){
        std::cout << b.c << " : ";
        for(auto c : b.bitset){
            std::cout << c;
        }
        std::cout << std::endl;
    }

    std::cout << uncompress(compressedText) << std::endl;
}

std::vector<bool> HuffmanTree::find(char c) {
    for(const auto node : lookupTable) {
        if(node.c == c)
            return node.bitset;
    }
    return std::vector<bool>(false);
}

// Traverse the entire tree and insert each found character with the accompanying bitset, which creates a lookupTable.
void HuffmanTree::createLookupTable(treeChar *pt, std::vector<bool> curBitset) {
    if(pt->character == '\0'){
        auto newLeftBitset = curBitset, newRightBitset = curBitset;
        newLeftBitset.push_back(false);
        newRightBitset.push_back(true);
        createLookupTable(pt->leftItem, newLeftBitset);
        createLookupTable(pt->rightItem, newRightBitset);
    }
    else{
        lookupTable.push_back({curBitset, pt->character});
    }
}


// when you reach a letter go to the next bits
std::string HuffmanTree::uncompress(std::vector<bool> bitset) {
    std::string output;
    while(bitset.size() != 0)
        output.push_back( readTree(&itemList[0], &bitset));

    return output;
}

char HuffmanTree::readTree(treeChar *pt, std::vector<bool> *bitset) {
    if(pt->character != '\0'){
        return pt->character;
    }

    bool bit = bitset->at(0);
    bitset->erase(bitset->begin());

    if (bit == 0) {
        return readTree(pt->leftItem, bitset);
    } else {
        return readTree(pt->rightItem, bitset);
    }
}

std::vector<bool> HuffmanTree::saveTree() {
    std::vector<bool> bitset;
    createSavedTree(&itemList[0], &bitset);
    return bitset;
}

void HuffmanTree::loadTree(std::vector<bool> * bitset) {
    loadSavedTree(bitset);
}

void HuffmanTree::createSavedTree(treeChar *pt, std::vector<bool>* bitset){
    // If it is a leaf node: Output 1-bit + N-bit character/byte
    if(pt->character != '\0') {
        bitset->push_back(true);
        std::vector<bool> tempBitset;

        for(int i = 0; i < 8; i++) {
            tempBitset.push_back((pt->character >> i) & 1);
        }
        // push tempBitset to the back of bitset.
        bitset->insert(bitset->end(), tempBitset.begin(), tempBitset.end());

    } else {
        // If not leaf-node, output 0-bit. Then encode both child nodes (first left then right)
        bitset->push_back(false);
        createSavedTree(pt->leftItem, bitset);
        createSavedTree(pt->rightItem, bitset);
    }
}
void HuffmanTree::loadSavedTree(std::vector<bool>* bitset){
    bool bit = bitset->at(0);
    bitset->erase(bitset->begin());
    // If it is not a leaf-node:
    if(bit == false){
        loadSavedTree(bitset);
    }
    else{
        
    }
}