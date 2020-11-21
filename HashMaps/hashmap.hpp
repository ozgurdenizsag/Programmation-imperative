#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstddef>
using namespace std;

template<class K, class V> class HashNode {
    private:
    K _key;
    V _value;
    HashNode *_next;
    public:
    HashNode(const K &key, const V &value) : _key(key), _value(value), _next(NULL){}

    K getKey() const{
        return _key;
    }

    V getValue() const{
        return _value;
    }

    void setValue(V value){
        _value = value;
    }

    HashNode *getNext() const{
        return _next;
    }

    void setNext(HashNode *next) {
        _next = next;
    }

        
};
#endif
