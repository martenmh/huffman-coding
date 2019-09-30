#include <string>
#include <bitset>
#include <vector>
#include "HuffmanList.h"
#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

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
    // Variable bitset (for initialization at runtime) as is necessary for each character in the tree
    std::vector<bool> find(char);
    //std::string getText(std::bitset<size>);
    void compress(std::string);
    std::string uncompress(std::vector<bool> bitset);

    //Returns the bitset for the huffman so that it saves the tree with the compressed
    std::vector<bool> saveTree();
private:
    std::vector<tableReturn> lookupTable;
    // Recursive functions
    void createSavedTree(treeChar *pt, std::vector<bool> *bitset);
    void loadSavedTree(std::vector<bool>*);
    void createLookupTable(treeChar*, std::vector<bool>);
    //Create itemList from bits, when the tree is made put the rest of the bits in compressedText
    void loadTree(std::vector<bool> *);

    char readTree(treeChar *pt, std::vector<bool> *bitset);
    // Ordered by frequency
    HuffmanList itemList;
    std::vector<bool> compressedText;


};


#endif //HUFFMAN_HUFFMANTREE_H
