//
// Created by dude on 2/28/22.
//
#include <memory>
#include <utility>
#include <iostream>

#include "HashTable.h"
#include "LinkedList.h"
#include "HashFunction.h"

int LENGTH = 9973;

HashTable::HashTable() {
    table_ = new LinkedList[LENGTH];
    length_ = LENGTH;
}

HashTable::HashTable(int length) {
    table_ = new LinkedList[length];
    length_ = length;
}

HashTable::~HashTable() {
    delete [] table_;
}

void HashTable::Insert(const std::shared_ptr<std::string>& key, int val) {
    int index = HashFunction::Hash(key, length_);
    //if(Contains(key)) {
    //    return;
    //}
    std::shared_ptr<Item> newItem = std::make_shared<Item>(key, val);
    table_[index].insert(newItem);
}

bool HashTable::Contains(const std::shared_ptr<std::string>& key) {
    int index = HashFunction::Hash(key, length_);
    if(table_[index].getKey(key)) {
        //TODO: remove before submission
        std::cout << "duplicate caught" << std::endl;
        return true;
    } else {
        return false;
    }
}

// TODO: case where val not in table
int HashTable::Get(const std::shared_ptr<std::string>& key) const {
    int index = HashFunction::Hash(key, length_);
    return index;
    // if contains key
        //return index
    //return table_[index].getKey(key);
}

// TODO: case where val not in table
int HashTable::getVal(const std::shared_ptr<std::string>& key) const{
    int index = HashFunction::Hash(key, length_);
    int result = table_[index].getValue(key);
    return result;
}

void HashTable::Remove(const std::shared_ptr<std::string>& key) {
    int index = HashFunction::Hash(key, length_);
    table_[index].remove(key);
}

void HashTable::printTable() {
    std::cout << "\n\nHash Table:\n";
    for(int i = 0; i < length_; i++) {
        std::cout << "Bucket " << i + 1 << ": ";
        table_[i].printList();
    }
}

void HashTable::printHistogram() {
    std::cout << "\n\nHash Table Contains ";
    std::cout << getNumItems() << " Items total.\n";
    for ( int i = 0; i < length_; i++ )
    {
        std::cout << i + 1 << ":\t";
        for ( int j = 0; j < table_[i].getLength(); j++ )
            std::cout << " X";
        std::cout << "\n";
    }
}

void HashTable::printNumItems() {
    std::cout << "\n\nHash Table Contains ";
    std::cout << getNumItems() << " Items total.\n";
}

void HashTable::setLength(int len) {
    length_ = len;
}

int HashTable::getLength() const {
    return length_;
}

int HashTable::getNumItems() {
    int count = 0;
    for(int i = 0; i < length_; i++) {
        count += table_[i].getLength();
    }
    return count;
}

LinkedList::LinkedList() {
    headPtr_ = std::make_shared<Item>();
    headPtr_->next_ = nullptr;
    nodeLength_ = 0;
}

void LinkedList::insert(std::shared_ptr<Item> newEntry) {
    if(!headPtr_->next_) {
        headPtr_->next_ = std::move(newEntry);
        nodeLength_++;
        return;
    }
    std::shared_ptr<Item> curr = headPtr_;
    std::shared_ptr<Item> prev = curr;
    while(curr->next_) {
        prev = curr;
        curr = curr->next_;
        if((curr != headPtr_) && curr->compare(newEntry->key_) == 0) {
            std::shared_ptr<Item> temp = curr;
            if(curr->next_) {
                prev->next_ = curr->next_;
            }
            curr = curr->next_;
            temp.reset();
            nodeLength_--;
        }
    }
    curr->next_ = newEntry;
    newEntry->next_ = nullptr;
    nodeLength_++;
}

bool LinkedList::remove(const std::shared_ptr<std::string>& entry) {
    if(!headPtr_) {
        return false;
    }
    std::shared_ptr<Item> curr = headPtr_;
    std::shared_ptr<Item> prev = curr;
    while(curr) {
        if((curr != headPtr_) && curr->compare(entry) == 0) {
            if(curr->next_) {
                prev->next_ = curr->next_;
            }
            curr.reset();
            nodeLength_--;
            return true;
        }
        prev = curr;
        curr = curr->next_;
    }
    return false;
}

bool LinkedList::getKey(const std::shared_ptr<std::string>& entry) {
    std::shared_ptr<Item> curr = headPtr_->next_;
    while(curr) {
        if(curr->compare(entry) == 0) {
            return true;
        }
        curr = curr->next_;
    }
    return false;
}

int LinkedList::getValue(const std::shared_ptr<std::string>& entry) {
    std::shared_ptr<Item> curr = headPtr_->next_;
    if(curr == nullptr) {
        return -1;
    }
    while(curr) {
        if(curr->compare(entry) == 0) {
            return curr->val_;
        }
        curr = curr->next_;
    }
    return -1;
}

void LinkedList::printList() {
    if(nodeLength_ == 0) {
        std::cout << "\n{ }\n";
        return;
    }
    std::shared_ptr<Item> prev = headPtr_;
    std::shared_ptr<Item> curr = prev;
    std::cout << "\n{ ";
    while(curr) {
        prev = curr;
        if(prev != headPtr_) {
            std::cout << *(prev->key_);
            if(prev->next_) {
                std::cout << " ";
            }
        }
        curr = prev->next_;
    }
    std::cout << " }\n";
}

int LinkedList::getLength() const {
    return nodeLength_;
}

LinkedList::~LinkedList() = default;

Item::Item() = default;

Item::Item(std::shared_ptr<std::string> key, int val) {
    key_ = std::move(key);
    val_ = val;
}

void Item::setVal(int val) {
    val_ = val;
}

void Item::setKey(std::shared_ptr<std::string> key) {
    key_ = std::move(key);
}

int Item::compare(const std::shared_ptr<Item> &other) {
    if(other == nullptr || other->getKey() == nullptr) {
        throw "error";
    }
    return key_->compare(*(other->getKey()));
}

int Item::compare(const std::shared_ptr<std::string> &other) {
    if(other == nullptr) {
        throw "error";
    }
    return key_->compare(*other);
}

std::shared_ptr<std::string> Item::getKey() {
    return key_;
}

int Item::getVal() const {
    return val_;
}
