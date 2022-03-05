//
// Created by dude on 2/28/22.
//

#include "Index.h"
#include "LinkedList.h"
#include "HashFunction.h"
#include "HashTable.h"

Index::Index() = default;

Index::~Index() = default;

void Index::Insert(std::shared_ptr<std::string> &key, int val) {
    table_.Insert(key, val);
}

void Index::Remove(std::shared_ptr<std::string> &key) {
    table_.Remove(key);
}

int Index::Find(std::shared_ptr<std::string> &key) {
    return table_.getVal(key);
}

void Index::printTable() {
    table_.printTable();
}

void Index::printHistogram() {
    table_.printHistogram();
}



