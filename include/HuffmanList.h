//
// Created by marten on 26-09-19.
//
#ifndef HUFFMAN_HUFFMANLIST_H
#define HUFFMAN_HUFFMANLIST_H

#include <vector>

struct treeChar {
    // character can be empty, than it is a sum with 2 pointers
    char character;
    unsigned int frequency;
    // traverse by 0 and 1 in the bitset
    treeChar *nextItems[];
};


class HuffmanList : public std::vector<treeChar> {
public:
    HuffmanList();
    ~HuffmanList();
    void order();
    treeChar *find(char);
private:
    bool sorter(treeChar const& lhs, treeChar const& rhs);

};


#endif //HUFFMAN_HUFFMANLIST_H
