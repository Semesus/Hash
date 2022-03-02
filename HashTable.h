//
// Created by dude on 2/28/22.
//

#ifndef HW5_HASHTABLE_H
#define HW5_HASHTABLE_H

#include <list>
#include <string>
#include <vector>
#include <memory>
#include "HashNode.h"

//class Entry;
class HashNode;

class HashTable {
private:
    // vector of HashNode linked lists
    std::vector<std::shared_ptr<HashNode>> vect_;
    HashNode** headPtrs_;
    // size of table
    int length_;
    // return location for given key
    int hash(const std::shared_ptr<std::string>& key) const;

public:
    // ctor
    explicit HashTable(int);

    ~HashTable();

    // add entry to table
    void Insert(const std::shared_ptr<std::string>&, int);

    // is entry in table
    bool Contains(std::shared_ptr<std::string>);

    // find entry in index
    int Get(std::shared_ptr<std::string>);

    // remove entry form table by key
    bool remove(std::shared_ptr<std::string>);

    void setLength(int);

    int getLength();

    // print table for debugging
    void printTable();

    void printHistogram();

};


#endif //HW5_HASHTABLE_H
