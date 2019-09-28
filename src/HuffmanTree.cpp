//
// Created by marten on 26-09-19.
//
#include <iterator>
#include <iostream>
#include "../include/HuffmanTree.h"
#include "HuffmanList.h"

HuffmanTree::HuffmanTree(std::string text) {
    compress(text);
}

HuffmanTree::HuffmanTree(char ** text) {
    compress(reinterpret_cast<const char *>(text));
}

HuffmanTree::~HuffmanTree() = default;


treeChar HuffmanTree::left() {

}
treeChar HuffmanTree::right() {

}
// when you reach a letter go to the next bits
std::string HuffmanTree::uncompress(std::bitset<2> bits) {
    std::string text;
    for(int i = 0; i <= bits.size(); ++i){
        if(!bits[i]) text.push_back(this->left().character);
        if(bits[i]) text.push_back(this->right().character);
    }
    return text;
}

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
        i -= 2;

        // Insert the itemList and order the list
        itemList.push_back(*sum);
        itemList.order();
        i++;
    }


    std::cout << "h" << std::endl;
    //return std::bitset<2>{true, false};

}

