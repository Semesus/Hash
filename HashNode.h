//
// Created by dude on 3/1/22.
//

#ifndef HW5_HASHNODE_H
#define HW5_HASHNODE_H
#include <string>
#include <memory>

struct Item {
    int val_;
    std::shared_ptr<std::string> key_;
    std::shared_ptr<Item> next_;
};

class HashNode {
private:
    std::shared_ptr<Item> headPtr_;

    int length_;

public:
    HashNode();

    HashNode(std::shared_ptr<std::string>, int);

    HashNode(std::shared_ptr<std::string>, int, std::shared_ptr<HashNode>);

    ~HashNode();

    void insert(std::shared_ptr<Item>);

    bool remove(std::shared_ptr<std::string>);

    std::shared_ptr<Item> getKey(std::shared_ptr<std::string>);

    void printList();
    /*
    void setKey(std::shared_ptr<std::string>);

    void setVal(int);

    void setNext(std::shared_ptr<HashNode>);

    std::shared_ptr<std::string> getKey();

    int getVal();

    std::shared_ptr<HashNode> getNext() const;

    void print();
    */
};


#endif //HW5_HASHNODE_H
