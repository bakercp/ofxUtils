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

template <typename K, typename V> class ofxSimpleMap {
public:
    ofxSimpleMap();
    virtual ~ofxSimpleMap();
//    bool    contains(T item) const;
//    //bool    hasLike(T item) const;
//    //bool    replaceAll(T item, T with);
//    
//    bool    has(T item) const;
//    bool    add(T item);
//    bool    remove(T item);
//    typename set<T>::iterator find(T item) const;
//    typename set<T>::iterator begin() const;
//    typename set<T>::iterator end() const;
//    size_t size() const;
//    bool   isEmpty() const;
//    vector<T> toArray() const;
//    vector<T> toArrayReverse() const;
//    set<T>& getItems();
//    void clear();
    
private:
    map<T,V> items;
    typename map<K,V>::iterator it;
};

template <class T> ofxSimpleSet<T>::ofxSimpleSet()  {}
template <class T> ofxSimpleSet<T>::~ofxSimpleSet() {}
//template <class T> bool ofxSimpleSet<T>::contains(T item) const {return find(item) != items.end();}
//template <class T> bool ofxSimpleSet<T>::has(T item)      const {return find(item) != items.end();}
//template <class T> bool ofxSimpleSet<T>::add(T item) {return (items.insert(item)).second;}
//template <class T> bool ofxSimpleSet<T>::remove(T item) {
//    it = find(item);
//    if(it != items.end()) {
//        items.erase(it); // erase it
//        return true;
//    } else {
//        return false;
//    }
//}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::find(T item) const {return items.find(item);}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::begin() const {return items.begin();}
//template <class T> typename set<T>::iterator ofxSimpleSet<T>::end() const {return items.end();}
//
//template <class T> size_t ofxSimpleSet<T>::size() const { return items.size();}
//template <class T> bool ofxSimpleSet<T>::isEmpty() const { return items.size() <= 0;}
//template <class T> vector<T> ofxSimpleSet<T>::toArray() const {
//    return std::vector<T>(items.begin(), items.end());
//}
//template <class T> vector<T> ofxSimpleSet<T>::toArrayReverse() const {
//    std::vector<T> array(items.begin(), items.end());
//    std::reverse(array.begin(),array.end());
//    return array;
//}
//template <class T> set<T>& ofxSimpleSet<T>::getItems() {return items;}
//template <class T> void ofxSimpleSet<T>::clear() {items.clear();}
//
//// some defs
//typedef ofxSimpleSet<int>    ofxSimpleIntSet;
//typedef ofxSimpleSet<float>  ofxSimpleFloatSet;
//typedef ofxSimpleSet<string> ofxSimpleStringSet;
