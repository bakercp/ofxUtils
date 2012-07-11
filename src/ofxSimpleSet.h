//
//  ofxSimpleSet.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher Baker on 6/4/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include <set>
#include <vector>

template <typename T> class ofxSimpleSet {
public:
    ofxSimpleSet();
    virtual ~ofxSimpleSet();
    bool    contains(T item) const;
    //bool    hasLike(T item) const;
    //bool    replaceAll(T item, T with);
    
    
    bool    has(T item) const;
    bool    add(T item);
    bool    remove(T item);
    typename set<T>::iterator find(T item) const;
    typename set<T>::iterator begin() const;
    typename set<T>::iterator end() const;
    size_t size() const;
    bool   isEmpty() const;
    vector<T> toArray() const;
    set<T>& getItems();
    void clear();
    
private:
    set<T> items;
    typename set<T>::iterator it;
};

template <class T> ofxSimpleSet<T>::ofxSimpleSet()  {}
template <class T> ofxSimpleSet<T>::~ofxSimpleSet() {}
template <class T> bool ofxSimpleSet<T>::contains(T item) const {return find(item) != items.end();}
template <class T> bool ofxSimpleSet<T>::has(T item)      const {return find(item) != items.end();}
template <class T> bool ofxSimpleSet<T>::add(T item) {return (items.insert(item)).second;}
template <class T> bool ofxSimpleSet<T>::remove(T item) {
    it = find(item);
    if(it != items.end()) {
        items.erase(it); // erase it
        return true;
    } else {
        return false;
    }
}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::find(T item) const {return items.find(item);}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::begin() const {return items.begin();}
template <class T> typename set<T>::iterator ofxSimpleSet<T>::end() const {return items.end();}

template <class T> size_t ofxSimpleSet<T>::size() const { return items.size();}
template <class T> bool ofxSimpleSet<T>::isEmpty() const { return items.size() <= 0;}
template <class T> vector<T> ofxSimpleSet<T>::toArray() const {return std::vector<T>(items.begin(), items.end());}
template <class T> set<T>& ofxSimpleSet<T>::getItems() {return items;}
template <class T> void ofxSimpleSet<T>::clear() {items.clear();}

// some defs
typedef ofxSimpleSet<int>    ofxSimpleIntSet;
typedef ofxSimpleSet<float>  ofxSimpleFloatSet;
typedef ofxSimpleSet<string> ofxSimpleStringSet;



