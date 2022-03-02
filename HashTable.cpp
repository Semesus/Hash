//
// Created by dude on 2/28/22.
//

#include "HashTable.h"
#include "HashNode.h"


HashTable::HashTable(int length) {
    //vect_.reserve(length);
    length_ = length;
    //headPtrs_ = new HashNode* [length];
}

HashTable::~HashTable() = default;

int HashTable::hash(const std::shared_ptr<std::string>& key) const {
    int result = 0;
    //for(int i = 0; i < key.length(); i++) {
    //    result += key[i];
    //}
    for(char i : *key) {
        result += i;
    }
    return (result * key->length()) % length_;
}

void HashTable::Insert(const std::shared_ptr<std::string>& key, int val) {
    int index = hash(key);
    std::shared_ptr<HashNode> newNode = std::make_shared<HashNode>(key, val);
    vect_.at(index)->setNext(newNode);
}

bool HashTable::Contains(std::shared_ptr<std::string>) {
    return false;
}

int HashTable::Get(std::shared_ptr<std::string>) {
    return 0;
}

bool HashTable::remove(std::shared_ptr<std::string>) {
    return false;
}

void HashTable::printTable() {

}

void HashTable::printHistogram() {

}

void HashTable::setLength(int len) {
    length_ = len;
}

int HashTable::getLength() {
    return length_;
}

#include <utility>

HashNode::HashNode() = default;

HashNode::HashNode(std::shared_ptr<std::string> key, int val) : key_(std::move(key)), val_(val) {}

HashNode::HashNode(std::shared_ptr<std::string> key, int val, std::shared_ptr<HashNode> next) :
        key_(std::move(key)), val_(val), next_(std::move(next)) {}

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
