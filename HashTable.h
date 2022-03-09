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

struct Item {
    friend class HashTable;
private:
    int val_;
    std::shared_ptr<std::string> key_;
    std::shared_ptr<Item> next_;
public:
    Item();
    Item(std::shared_ptr<std::string>, int);
    int compare(const std::shared_ptr<Item>&);
    int compare(const std::shared_ptr<std::string>&);
    std::shared_ptr<std::string> getKey();
    // std::shared_ptr<std::string> getKey();
    int getVal() const;
    void setVal(int val);
    void setKey(std::shared_ptr<std::string> key);
};

class HashTable {
private:
    // vector of HashNode linked lists
    //std::vector<std::shared_ptr<HashNode>> vect_;
    //std::vector<std::list<HashNode>> vect_;
    LinkedList* table_;
    //std::shared_ptr<LinkedList> table_;
    // size of table
    int length_;
    // return location for given key
    //int hash(const std::shared_ptr<std::string>& key) const;

public:
    // ctor
    explicit HashTable(int);

    HashTable();

    ~HashTable();

    // add entry to table
    virtual void Insert(const std::shared_ptr<std::string>&, int);

    // is entry in table
    virtual bool Contains(const std::shared_ptr<std::string>&);

    // find entry in index
    virtual int Get(const std::shared_ptr<std::string>&) const;

    // remove entry form table by key
    virtual void Remove(const std::shared_ptr<std::string>&);

    virtual int getVal(const std::shared_ptr<std::string>&) const;

    void setLength(int);

    int getLength() const;

    int getNumItems();

    // print table for debugging
    void printTable();

    void printHistogram();

    void printNumItems();

};


#endif //HW5_HASHTABLE_H
