//
// Created by dude on 3/1/22.
//

#ifndef HW5_ENTRY_H
#define HW5_ENTRY_H
#include <string>
#include <memory>

class Entry {
private:
    std::shared_ptr<std::string> key_;
    int val_;
public:
    Entry(std::shared_ptr<std::string>, int);
    Entry();
    ~Entry();

    int compare(const std::shared_ptr<Entry>&);
    int compare(const std::shared_ptr<std::string>&);
    std::shared_ptr<std::string> getKey();
    int getVal();
    void setVal(int);
};


#endif //HW5_ENTRY_H
