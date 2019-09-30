#include <string>
#include <bitset>
#include <vector>
#include "HuffmanList.h"
#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

struct nodeReturn{
    std::vector<bool> bitset;
    bool found;
};

struct tableReturn{
    std::vector<bool> bitset;
    char c;
};


class HuffmanTree {
public:
    // Generate the huffman tree from a string of text;
    explicit HuffmanTree(std::string);
    explicit HuffmanTree(char **);
    ~HuffmanTree();
    // When bit is 0
    treeChar left();
    // When bit is 1
    treeChar right();
    // Variable bitset (for initialization at runtime) as is necessary for each character in the tree
    std::vector<bool> find(char);
    //std::string getText(std::bitset<size>);
    void compress(std::string);
    std::string uncompress(std::vector<bool> bitset);
    // Prints out the tree in the shape of a... tree

private:
    std::vector<tableReturn> lookupTable;
    // Recursive functions
    void createLookupTable(treeChar*, std::vector<bool>);
    char readTree(treeChar *pt, std::vector<bool> *bitset);
    // Ordered by frequency
    HuffmanList itemList;
    std::vector<bool> compressedText;



};


#endif //HUFFMAN_HUFFMANTREE_H
