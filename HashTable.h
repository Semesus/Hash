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

class LinkedList;
class HashFunction;

class HashTable {
private:
    LinkedList* table_;
    //std::vector<std::list<std::shared_ptr<Item>>> table_;
    // size of table
    int length_;

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
