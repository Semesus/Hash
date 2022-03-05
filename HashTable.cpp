//
// Created by dude on 2/28/22.
//
#include <memory>
#include <utility>
#include <iostream>

#include "HashTable.h"
#include "LinkedList.h"
#include "HashFunction.h"

int LENGTH = 10;

HashTable::HashTable() {
    table_ = new LinkedList[LENGTH];
    length_ = LENGTH;
}

HashTable::HashTable(int length) {
    //vect_.reserve(length);
    //length_ = length;
    table_ = new LinkedList[length];
    length_ = length;
}

HashTable::~HashTable() {
    delete [] table_;
}

void HashTable::Insert(const std::shared_ptr<std::string>& key, int val) {
    int index = HashFunction::Hash(key, length_);
    std::shared_ptr<Item> newItem = std::make_shared<Item>(key, val);
    table_[index].insert(newItem);
    //std::shared_ptr<HashNode> newNode = std::make_shared<HashNode>(key, val);
    //vect_.insert(index, std::list<HashNode>.newNode);
}

bool HashTable::Contains(const std::shared_ptr<std::string>& key) {
    int index = HashFunction::Hash(key, length_);
    if(table_[index].getKey(key)) {
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
    return table_[index].getVal(key);
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

//HashNode::HashNode(std::shared_ptr<std::string> key, int val) : key_(std::move(key)), val_(val) {}

//HashNode::HashNode(std::shared_ptr<std::string> key, int val, std::shared_ptr<HashNode> next) :
//        key_(std::move(key)), val_(val), next_(std::move(next)) {}

void LinkedList::insert(std::shared_ptr<Item> newEntry) {
    if(!headPtr_->next_) {
        headPtr_->next_ = std::move(newEntry);
        nodeLength_++;
        return;
    }
    std::shared_ptr<Item> curr = headPtr_;
    std::shared_ptr<Item> prev = curr;
    while(curr) {
        prev = curr;
        curr = prev->next_;
    }
    prev->next_ = newEntry;
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
        if(curr->key_ == entry) {
            prev->next_ = curr->next_;
            curr.reset();
            nodeLength_--;
            return true;
        }
        prev = curr;
        curr = prev->next_;
    }
    return false;
}

std::shared_ptr<Item> LinkedList::getKey(const std::shared_ptr<std::string>& entry) {
    std::shared_ptr<Item> curr = headPtr_;
    std::shared_ptr<Item> prev = curr;
    while(curr) {
        prev = curr;
        if((prev != headPtr_) && prev->key_ == entry) {
            return prev;
        }
        curr = prev->next_;
    }
    return nullptr;
}

int LinkedList::getVal(const std::shared_ptr<std::string>& entry) {
    std::shared_ptr<Item> curr = headPtr_;
    std::shared_ptr<Item> prev = curr;
    while(curr) {
        prev = curr;
        if((prev != headPtr_) && prev->key_ == entry) {
            return prev->val_;
        }
        curr = prev->next_;
    }
    return -1;
}


void LinkedList::printList() {
    if(nodeLength_ == 0) {
        std::cout << "\n{ }\n";
        return;
    }
    std::shared_ptr<Item> prev = headPtr_;
    std::shared_ptr<Item> curr = headPtr_;
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



/*
HashNode::~HashNode() = default;

void HashNode::setNext(std::shared_ptr<HashNode> next) {
    next_ = std::move(next);
}

std::shared_ptr<HashNode> HashNode::getNext() const {
    return next_;
}

void HashNode::print() {

}

void HashNode::setKey(std::shared_ptr<std::string> key) {
    key_ = std::move(key);
}

void HashNode::setVal(int val) {
    val_ = val;
}

std::shared_ptr<std::string> HashNode::getKey() {
    return key_;
}

int HashNode::getVal() {
    return val_;
}
*/