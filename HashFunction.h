//
// Created by dude on 2/28/22.
//

#ifndef HW5_HASHFUNCTION_H
#define HW5_HASHFUNCTION_H

#include <memory>

class HashFunction {

public:
    HashFunction();
    ~HashFunction();

// return location for given key
static int Hash(const std::shared_ptr<std::string>& key, int length) ;
};


#endif //HW5_HASHFUNCTION_H
