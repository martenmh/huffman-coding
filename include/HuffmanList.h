//
// Created by marten on 26-09-19.
//
#ifndef HUFFMAN_HUFFMANLIST_H
#define HUFFMAN_HUFFMANLIST_H

#include <vector>

struct treeChar {
    // character can be empty, then it is a sum with 2 pointers
    char character;
    unsigned int frequency;
    // traverse by 0 and 1 in the bitset
    treeChar *leftItem;
    treeChar *rightItem;
};

// Extends std::vector with an order and find method
class HuffmanList : public std::vector<treeChar> {
public:
    HuffmanList();
    ~HuffmanList();
    void order();
    // Return the element location if the char exists in the list
    int find(char);
private:
    static bool sorter(treeChar &lhs, treeChar &rhs);

};


#endif //HUFFMAN_HUFFMANLIST_H
