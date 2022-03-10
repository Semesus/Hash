//
// Created by dude on 3/2/22.
//

#ifndef HW5_LINKEDLIST_H
#define HW5_LINKEDLIST_H
#include <string>
#include <memory>

struct Item {
    friend class LinkedList;
private:
    int val_;
    std::shared_ptr<std::string> key_;
    std::shared_ptr<Item> next_;
public:
    Item();
    Item(std::shared_ptr<std::string>, int);
    int compare(const std::shared_ptr<Item>&);
    int compare(const std::shared_ptr<std::string>&);
    std::shared_ptr<std::string> getKey();
    // std::shared_ptr<std::string> getKey();
    int getVal() const;
    void setVal(int val);
    void setKey(std::shared_ptr<std::string> key);
    void clear();
};

class LinkedList {
private:
    std::shared_ptr<Item> headPtr_;
    // num of nodes
    int nodeLength_;

public:
    LinkedList();
    //LinkedList(std::shared_ptr<std::string>, int);

    //LinkedList(std::shared_ptr<std::string>, int, std::shared_ptr<LinkedList>);

    ~LinkedList();

    void insert(std::shared_ptr<Item>);

    bool remove(const std::shared_ptr<std::string>&);

    bool getKey(const std::shared_ptr<std::string>&);

    int getValue(const std::shared_ptr<std::string>& entry);

    int getLength() const;

    void printList();
};



#endif //HW5_LINKEDLIST_H
