//
// Created by dude on 2/28/22.
//

#include "HashFunction.h"
#include <memory>
#include <string>
#include <cmath>

HashFunction::HashFunction() = default;

HashFunction::~HashFunction() = default;
/*
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
/*
int HashFunction::Hash(const std::shared_ptr<std::string> &key, int length) {
    int hash = 6199;
    std::string str = *key;
    //for(int i = 0; i < str.length(); i++) {
    for(char & i : str) {
        hash = (((hash << 5) + hash) + i) % length;
    }
    return hash;
}*/
int HashFunction::Hash(const std::shared_ptr<std::string> &key, int length) {
    int p = 37;
    int hash = 0;
    std::string str = *key;
    for(int i = str.length() - 1; i>= 0; i--) {
        hash = p * hash + str[i];
    }
    return std::abs(hash % length);
}

