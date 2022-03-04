//
// Created by dude on 2/28/22.
//

#ifndef HW5_HASHTABLE_H
#define HW5_HASHTABLE_H

#include <list>
#include <string>
#include <vector>
#include <array>
#include <memory>
//#include "HashNode.h"

//class Entry;
//class HashNode;
class LinkedList;
class HashFunction;

class HashTable {
private:
    // vector of HashNode linked lists
    //std::vector<std::shared_ptr<HashNode>> vect_;
    //std::vector<std::list<HashNode>> vect_;
    LinkedList* table_;
    // size of table
    int length_;
    // return location for given key
    //int hash(const std::shared_ptr<std::string>& key) const;

public:
    // ctor
    explicit HashTable(int);

    ~HashTable();

    // add entry to table
    void Insert(const std::shared_ptr<std::string>&, int);

    // is entry in table
    bool Contains(const std::shared_ptr<std::string>&);

    // find entry in index
    int Get(const std::shared_ptr<std::string>&) const;

    // remove entry form table by key
    void Remove(const std::shared_ptr<std::string>&);

    void setLength(int);

    int getLength() const;

    int getNumItems();

    // print table for debugging
    void printTable();

    void printHistogram();

};


#endif //HW5_HASHTABLE_H
