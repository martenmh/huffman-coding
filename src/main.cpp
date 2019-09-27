#include <iostream>

// Huffman coding:
// each character is 8 bit
// 256 possible characters
// count how much each character is used and put it in a list in order
// two least used characters are the base of the Huffman tree
// connect them with the sum of the frequency
// when a single character is used as many times as the sum of the lower frequency connect them with the sum all three 1 1 > 2 - 2 2 > 4

// navigating the tree:
// each time you take the left side put a 0
// each time you take the right side put a 1
// save it as the stream of bits

// when uncompressing do the same

#include "HuffmanTree.h"
#include "HuffmanList.h"
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    // TODO: RAII class
    std::ifstream myfile;

    myfile.open (argv[1]);

    std::string str((std::istreambuf_iterator<char>(myfile)),
                    std::istreambuf_iterator<char>());
    myfile.close();
    HuffmanTree tree = HuffmanTree(str);
    return 0;
}