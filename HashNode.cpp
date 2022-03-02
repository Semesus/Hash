//
// Created by dude on 3/1/22.
//

#include "HashNode.h"

#include <utility>

HashNode::HashNode() = default;

HashNode::HashNode(std::shared_ptr<std::string> key, int val) : key_(std::move(key)), val_(val) {}

HashNode::HashNode(std::shared_ptr<std::string> key, int val, std::shared_ptr<HashNode> next) :
    key_(std::move(key)), val_(val), next_(next) {}

HashNode::~HashNode() = default;

void HashNode::setNext(std::shared_ptr<HashNode> next) {
    next_ = next;
}

std::shared_ptr<HashNode> HashNode::getNext() const {
    return next_;
}


