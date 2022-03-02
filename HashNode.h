//
// Created by dude on 3/1/22.
//

#ifndef HW5_HASHNODE_H
#define HW5_HASHNODE_H
#include <string>
#include <memory>

class HashNode {
private:

    int val_{};
    std::shared_ptr<std::string> key_;
    std::shared_ptr<HashNode> next_ = nullptr;

public:
    HashNode();

    HashNode(std::shared_ptr<std::string>, int);

    HashNode(std::shared_ptr<std::string>, int, std::shared_ptr<HashNode>);

    ~HashNode();

    void setKey(std::shared_ptr<std::string>);

    void setVal(int);

    void setNext(std::shared_ptr<HashNode>);

    std::shared_ptr<std::string> getKey();

    int getVal();

    std::shared_ptr<HashNode> getNext() const;

    void print();

};


#endif //HW5_HASHNODE_H
