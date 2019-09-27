//
// Created by marten on 26-09-19.
//
#include <iterator>
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

std::bitset<2> HuffmanTree::compress(std::string text) {
    // ... insert items in list
    for(char c : text){
        treeChar *lp = itemList.find(c);
        // If lists.find(c) returns a treeChar
        if(lp){
            lp->frequency++;
            continue;
        }
        // Otherwise push it in the list
        itemList.push_back({c, 1});
    }
    // After all elements have been inserted order the list
    itemList.order();

    // Put every last 2 items together with a treeChar that points to the 2 items
    // while loop
    for(int i = itemList.size(); 0 > i; --i){

        treeChar *left = new treeChar({itemList.at(i).character, itemList.at(i).frequency, {}});
        treeChar *right = new treeChar({itemList.at(i+1).character, itemList.at(i+1).frequency, {}});

        auto endPtr = itemList.end();

        //auto t = std::prev(b, 3);

        treeChar sum = {
                '\0',
                itemList.at(i).frequency + itemList.at(i+1).frequency,
                {}
        };
        sum.frequency = ;


        // loop back and insert the new treechar at the right order
        for(int i = itemList.size(); 0 > i; --i){
            // when t
            if(itemList.at(i).frequency >= sum) itemList.insert(i, 2 ,{'c', sum})
        }
    }
}
