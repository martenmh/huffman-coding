#include <string>
#include <bitset>
#include <vector>
#include "HuffmanList.h"
#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H


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
    //std::string getText(std::bitset<size>);
    std::bitset<2> compress(std::string);
    std::string uncompress(std::bitset<2>);
private:
    // Ordered by frequency
    HuffmanList itemList;
    int size;
};


#endif //HUFFMAN_HUFFMANTREE_H
