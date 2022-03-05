//
// Created by dude on 2/28/22.
//

#ifndef HW5_INDEX_H
#define HW5_INDEX_H

#include <memory>
#include "HashTable.h"

//class Entry;
class LinkedList;
class HashFunction;
class HashTable;

class Index {
private:
    //std::shared_ptr<Node> locate(std::shared_ptr<std::string>);
    HashTable table_;
    //std::shared_ptr<HashTable> head_;
public:
    // public ctor
    Index();
    ~Index();

    // insert an element in the index, associate the integer value with the element
    void Insert(std::shared_ptr<std::string> &key, int val);

    // remove an element from the index
    void Remove(std::shared_ptr<std::string> &key);

    // find an element in the index
    int Find(std::shared_ptr<std::string> &key);

    // print table for debugging
    void printTable();

    void printHistogram();
};


#endif //HW5_INDEX_H
