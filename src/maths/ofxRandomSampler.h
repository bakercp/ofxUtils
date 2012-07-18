/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#pragma once

#include "ofMain.h"
#include <set>
#include <vector>

//template <typename T> class ofxSimpleSet {

class ofxRandomSampler {
public: 
    ofxRandomSampler(int n) {
        size = n;
        vals = new int[size];
        reset();        
    }
    
    virtual ~ofxRandomSampler() {
        delete[] vals;
    }
    
    void reset() {
    	for(int i=0;i<size;++i) {
			vals[i] = i;
		}
        
		// shuffle the elements in the array
        // Fisher-Yates shuffle
		for (int i=size;i>0;--i) {
            // 			int rand = cast(int) (drand48() * n);
			int rnd = (int)ofRandom(0, i);
			assert(rnd >=0 && rnd < i);
			swap(vals[i-1], vals[rnd]);
		}
		counter = 0;        
    }
    
    int next() {
		if (counter==size) {
            reset(); // re-init
			return next();
		} else {
			return vals[counter++];
		}
    }
    
private:
    
    int counter;
    int size;
    int* vals;
};

//template <typename T> class ofxSimpleSet {
//public:
//    ofxSimpleSet();
//    virtual ~ofxSimpleSet();
//    bool    contains(T item);
//    bool    add(T item);
//    bool    remove(T item);
//    typename set<T>::iterator find(T item);
//    typename set<T>::iterator begin();
//    typename set<T>::iterator end();
//    size_t size();
//    bool   isEmpty();
//    vector<T> toArray() const;
//    set<T>& getItems();
//    void clear();
//    
//private:
//    set<T> items;
//    typename set<T>::iterator it;
//};
//
//template <class T> ofxSimpleSet<T>::ofxSimpleSet()  {}
//template <class T> ofxSimpleSet<T>::~ofxSimpleSet() {}
//template <class T> bool ofxSimpleSet<T>::contains(T item){return find(item) != items.end();}
//template <class T> bool ofxSimpleSet<T>::add(T item){return (items.insert(item)).second;}
//template <class T> bool ofxSimpleSet<T>::remove(T item) {
//    it = find(item);
//    if(it != items.end()) {
//        items.erase(it); // erase it
//        return true;
//    } else {
//        return false;
//    }
//}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::find(T item){return items.find(item);}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::begin(){return items.begin();}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::end(){return items.end();}
//
//template <class T> size_t ofxSimpleSet<T>::size() { return items.size();}
//template <class T> bool ofxSimpleSet<T>::isEmpty() { return items.size() <= 0;}
//template <class T> vector<T> ofxSimpleSet<T>::toArray() const {return std::vector<T>(items.begin(), items.end());}
//template <class T> set<T>& ofxSimpleSet<T>::getItems() {return items;}
//template <class T> void ofxSimpleSet<T>::clear() {items.clear();}
//
//
//
//// some defs
//typedef ofxSimpleSet<int>    ofxSimpleIntSet;
//typedef ofxSimpleSet<float>  ofxSimpleFloatSet;
//typedef ofxSimpleSet<string> ofxSimpleStringSet;



