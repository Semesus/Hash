//
// Created by dude on 3/1/22.
//

#include "Entry.h"

Entry::Entry(std::shared_ptr<std::string> key, int val) : key_(std::move(key)), val_(val) {}

Entry::Entry() : val_(-1) {}

Entry::~Entry() = default;

int Entry::compare(const std::shared_ptr<Entry>& other) {
    if(other == nullptr || other->getKey() == nullptr) {
        throw "error";
    }
    return key_->compare(*(other->getKey()));
}

int Entry::compare(const std::shared_ptr<std::string>& other) {
    if(other == nullptr) {
        throw "error";
    }
    return key_->compare(*other);
}

std::shared_ptr<std::string> Entry::getKey() {
    return key_;
}

int Entry::getVal() {
    return val_;
}

void Entry::setVal(int val) {
    val_ = val;
}