//
// Created by marten on 26-09-19.
//

#include "../include/HuffmanList.h"
#include <algorithm>

HuffmanList::HuffmanList(): std::vector<treeChar>{}{
}

HuffmanList::~HuffmanList()= default;

void HuffmanList::order() {
    std::sort(this->begin(), this->end(), sorter);
}

int HuffmanList::find(char c) {
    for(int i = 0; i < this->size(); ++i){
        if(this->at(i).character == c)
            return i;
    }
    return -1;
}

bool HuffmanList::sorter(treeChar &lhs, treeChar &rhs) {
    return (lhs.frequency > rhs.frequency);
}
