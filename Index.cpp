//
// Created by dude on 2/28/22.
//

#include "Index.h"
#include "LinkedList.h"
#include "HashFunction.h"
#include "HashTable.h"

Index::Index() {
    HashTable(16);
}

Index::~Index() = default;

void Index::Insert(std::shared_ptr<std::string> &key, int val) {

}

void Index::Remove(std::shared_ptr<std::string> &key) {

}

int Index::Find(std::shared_ptr<std::string> &key) {
    return 0;
}
