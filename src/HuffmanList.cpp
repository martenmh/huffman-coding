//
// Created by marten on 26-09-19.
//

#include "../include/HuffmanList.h"
#include <algorithm>

HuffmanList::HuffmanList(): std::list<treeChar>{}{
}

HuffmanList::~HuffmanList(){

}

void HuffmanList::order() {
    std::sort(this->begin(), this->end(), &HuffmanList::sorter);
}

treeChar *HuffmanList::find(char c) {
    for(auto item : *this){
        if(item.character == c)
            return &item;
    }
    return nullptr;
}

bool HuffmanList::sorter(treeChar const &lhs, treeChar const &rhs) {
    return lhs.frequency < rhs.frequency;
}


// QuickSort algorithm
// pivot
// 1. correct position in final sorted array
// 2. item to the left are smaller
// 3. items to the right are larger
// take an item as pivot and move it to the end
// item from left is larger than pivot item and item from right is smaller
// get item from left item from right of the pivot and swap them
// if item from left is smaller than item from right pivot
// swap itemfrom left and pivot
// pivot is now in correct spot
// do recursive with partition

// chosing pivot:
// median of three:
// look at first middle and last element
// sort them properly and choose middle as pivot
//void HuffmanList::swap(treeChar &itemFromLeft, treeChar &itemFromRight) {
//    treeChar swap = itemFromLeft;
//    itemFromLeft = itemFromRight;
//    itemFromRight = swap;
//}
//
//void HuffmanList::quickSort(std::vector<treeChar> &A, int low, int high) {
//    if(A.at(low).frequency < A.at(high).frequency) {
//        int pivotLocation = partition(A, low, high);
//        quickSort(A, low, pivotLocation);
//        quickSort(A, pivotLocation + 1, high);
//    }
//}
//
//// Watch computerphile
//int HuffmanList::partition(std::vector<treeChar> &A, int low, int high) {
//    treeChar pivot = A.at(low);
//    int leftWall = low;
//
//    for(int i = low + 1; i < high; ++i){
//        if(A.at(i).frequency < pivot.frequency){
//            swap(A.at(i), A.at(leftWall));
//            leftWall = leftWall + 1;
//        }
//    }
//
//}
//
//void HuffmanList::orderPivot(std::vector<treeChar> &A, int low, int high) {
//
//}

