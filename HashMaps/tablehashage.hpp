#ifndef TABLEHASHAGE_HPP
#define TABLEHASHAGE_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstddef>
#include "hashmap.hpp"
using namespace std;

template<class K, class V> class TableHashage {
    private:
    vector< HashNode<K,V>* > table;
    public:
    
    TableHashage();
    ~TableHashage();
    bool get(const K& cle, V& valeur);
    void inserer(const K& cle, const V& valeur);
    void supprimer(const K& cle);
    int fonctionHashage(const K& cle){
        return cle % table.size();
    }  
};
#endif

template<class K, class V> TableHashage<K,V>::TableHashage(){
    table.resize(10);
}

template<class K, class V> TableHashage<K,V>::~TableHashage(){
 // destroy all buckets one by one
    for (size_t i = 0; i < table.size(); ++i) {
        HashNode<K, V> *entry = table[i];
        while (entry != NULL) {
            HashNode<K, V> *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        table[i] = NULL;
    }
}

template<class K, class V> bool TableHashage<K,V>::get(const K& cle, V& valeur){
    unsigned long hashValue = fonctionHashage(cle);
        HashNode<K, V> *entry = table[hashValue];
        while (entry != NULL) {
            if (entry->getKey() == cle) {
                valeur = entry->getValue();
                return true;
            }
            entry = entry->getNext();
        }
    return false;
}

template<class K, class V> void TableHashage<K,V>::inserer(const K& cle, const V& valeur){
    unsigned long hashValue = fonctionHashage(cle);
    HashNode<K, V> *prev = NULL;
    HashNode<K, V> *entry = table[hashValue];
    while (entry != NULL && entry->getKey() != cle) {
        prev = entry;
        entry = entry->getNext();
    }
    if (entry == NULL) {
        entry = new HashNode<K, V>(cle, valeur);
        if (prev == NULL) {
            // insert as first bucket
            table[hashValue] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        // just update the value
        entry->setValue(valeur);
    }
}

template<class K, class V> void TableHashage<K,V>::supprimer(const K& key){
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V> *prev = NULL;
    HashNode<K, V> *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }
    if (entry == NULL) {
        // key not found
        return;
    } else {
        if (prev == NULL) {
            // remove first bucket of the list
            table[hashValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
    delete entry;
    }
}


