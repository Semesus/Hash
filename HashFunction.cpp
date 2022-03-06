//
// Created by dude on 2/28/22.
//

#include "HashFunction.h"
#include <memory>
#include <string>

HashFunction::HashFunction() = default;

HashFunction::~HashFunction() = default;

int HashFunction::Hash(const std::shared_ptr<std::string> &key, int length) {
    int result = 0;
    //for(int i = 0; i < key.length(); i++) {
    //    result += key[i];
    //}
    for(char i : *key) {
        result += i;
    }
    return (result * key->length()) % length;
    //return result % length;

}


