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

#include "ofUtils.h"

#include <set>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>


//--------------------------------------------------------------
// ofUtils.h string supplements.
//--------------------------------------------------------------

// see implementation file


//--------------------------------------------------------------
// Comparator aliases.  Duplicates existing stl function, but it
// seems that there is no good way to do typedefs on templated
// functions in standard c++.
//--------------------------------------------------------------

// an alias for "std::less<T>()"
template <class T>
struct ofxOrderAscending : public binary_function<T, T, bool> {
bool operator()(const T& x, const T& y) const
    { return x < y; }
};

// an alias for "std::greater<T>()"
template <class T>
struct ofxOrderDescending : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const
    { return x > y; }
};

// an alias for "std::equal<T>()"
template <class T>
struct ofxIsEqual : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const
    { return x == y; }
};

//--------------------------------------------------------------
// Wrapping.
//--------------------------------------------------------------

template <class T>
inline void ofxAdd(vector<T>& values, const T& target) {
    values.push_back(target);
}

// special to avoid string literal problems
inline void ofxAdd(vector<string>& values, const string& target) {
    values.push_back(target);
}


//--------------------------------------------------------------
// The following operations are useful for simulating std::set
// and std::multiset operations using a vector.  Any normal 
// vector can be turned into a sorted set using ofSort.
// 
// Defaults use an ascending order like ofxOrderAscending<T>() 
// or std::less<T>().

//--------------------------------------------------------------

//--------------------------------------------------------------
// Remove duplicates and sort the array.
//--------------------------------------------------------------
template<class T, class CompareFunction, class EqualityFunction>
void ofxRemoveDuplicatesAndSort(vector<T>& unsortedValues, CompareFunction compare, EqualityFunction equality) {
    ofSort(unsortedValues, compare); // sort it
    unsortedValues.erase( std::unique(unsortedValues.begin(), unsortedValues.end(), equality), unsortedValues.end());
}

template<class T>
void ofxRemoveDuplicatesAndSort(vector<T>& unsortedValues) {
    ofxRemoveDuplicatesAndSort(unsortedValues, ofxOrderAscending<T>(), ofxIsEqual<T>());
}

//--------------------------------------------------------------
// Remove duplicates without altering the order.
//--------------------------------------------------------------
template<class T>
void ofxRemoveDuplicates(vector<T>& unsortedValues) {
    // perhaps a way to do this using refs w/o copying?
    // http://stackoverflow.com/questions/4877504/how-can-i-remove-duplicate-values-from-a-list-in-c
    typename std::set<T> found;
    typename vector<T>::iterator i = unsortedValues.begin();
    for (; i != unsortedValues.end();) {
        if (!found.insert(*i).second) {
            i = unsortedValues.erase(i);
        }
        else {
            ++i;
        }
    }
}


//--------------------------------------------------------------
// Sort the items in descending order.
//--------------------------------------------------------------
template<class T>
void ofxSortDescending(vector<T>& unsortedValues) {
    ofSort(unsortedValues, ofxOrderDescending<T>());
}

//--------------------------------------------------------------
// Union
//--------------------------------------------------------------
template<class T, class CompareFunction>
void ofxUnion(vector<T>& sortedValues_0, vector<T>& sortedValues_1, vector<T>& sortedUnion, CompareFunction compare) {
    sortedUnion.resize(sortedValues_0.size() + sortedValues_1.size()); // the max size
    typename std::vector<T>::iterator i = std::set_union(sortedValues_0.begin(), 
                                                         sortedValues_0.end(), 
                                                         sortedValues_1.begin(),
                                                         sortedValues_1.end(),
                                                         sortedUnion.begin(),
                                                         compare);
    sortedUnion.resize(std::distance(sortedUnion.begin(),i));
}

template<class T>
void ofxUnion(vector<T>& sortedValues_0, vector<T>& sortedValues_1, vector<T>& sortedUnion) {
    ofxUnion(sortedValues_0, sortedValues_1, sortedUnion, ofxOrderAscending<T>());
}

//--------------------------------------------------------------
// Intersection
//--------------------------------------------------------------
template<class T, class CompareFunction>
void ofxIntersection(vector<T>& sortedValues_0, vector<T>& sortedValues_1, vector<T>& sortedIntersection, CompareFunction compare) {
    // TODO -- all of this resizing shoudl be replaced with intserters or back_inserters.  But doing so creates compile problems
    // http://stackoverflow.com/questions/4775927/set-intersection
    sortedIntersection.resize(sortedValues_0.size() + sortedValues_1.size()); // the max size
    typename std::vector<T>::iterator i = std::set_intersection(sortedValues_0.begin(), 
                                                         sortedValues_0.end(), 
                                                         sortedValues_1.begin(),
                                                         sortedValues_1.end(),
                                                         sortedIntersection.begin(),
                                                         compare);
    sortedIntersection.resize(std::distance(sortedIntersection.begin(),i)); // the actual size
}

template<class T>
void ofxIntersection(vector<T>& sortedValues_0, vector<T>& sortedValues_1, vector<T>& sortedIntersection) {
    ofxIntersection(sortedValues_0, sortedValues_1, sortedIntersection, ofxOrderAscending<T>());
}

//--------------------------------------------------------------
// Insert in order (like std::multiset)
//--------------------------------------------------------------
template<class T, class CompareFunction>
inline void ofxInsert(vector<T>& sortedValues, const T& value, CompareFunction compare, bool requireUnique = false) {
    typename vector<T>::iterator i = std::lower_bound(sortedValues.begin(), sortedValues.end(), value, compare);
    if (!requireUnique || (i == sortedValues.end() || compare(value, *i))) sortedValues.insert(i, value);    
}

template<class T >
inline void ofxInsert(vector<T>& sortedValues, const T& value) {
    ofxInsert(sortedValues, value, ofxOrderAscending<T>());
}

// special to avoid string literal problems
inline void ofxInsert(vector<string>& sortedValues, const string& value, bool (*compare)(string, string) ) {
    ofxInsert(sortedValues, value, compare);
}

//--------------------------------------------------------------
// Insert unique item in order (like std::set)
//--------------------------------------------------------------
template<class T, class CompareFunction>
inline void ofxInsertUnique(vector<T>& sortedValues, const T& value, CompareFunction compare) {
    ofxInsert(sortedValues, value, compare, true);
}

template<class T>
inline void ofxInsertUnique(vector<T>& sortedValues, const T& value) {
    ofxInsertUnique(sortedValues, value, ofxOrderAscending<T>());
}

// special to avoid string literal problems
inline void ofxInsertUnique(vector<string>& sortedValues, const string& value, bool (*compare)(string, string)) {
    ofxInsert(sortedValues, value, compare);
}

//--------------------------------------------------------------
// Does a sorted array contain a value?
//--------------------------------------------------------------
template <class T, class CompareFunction>
inline bool ofxSortedArrayContains(vector<T>& sortedValues, const T& target, CompareFunction compare) {
    return std::binary_search(sortedValues.begin(), sortedValues.end(), target, compare);
}

template <class T>
inline bool ofxSortedArrayContains(vector<T>& sortedValues, const T& target) {
    return ofxSortedArrayContains(sortedValues, target, ofxOrderAscending<T>());
}

inline bool ofxSortedArrayContains(vector<string>& sortedValues, const string& target, bool (*compare)(string, string)) {
    return ofxSortedArrayContains(sortedValues, target, compare);
}

//--------------------------------------------------------------
// Does a sorted array contain a value?
//--------------------------------------------------------------
template <class T, class CompareFunction>
inline unsigned int ofFindInSorted(const vector<T>& values, const T& target, CompareFunction compare) {
    return std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), target, compare));
}

template <class T>
inline unsigned int ofFindInSorted(const vector<T>& sortedValues, const T& target) {
    return ofFindInSorted(sortedValues, target, ofxOrderAscending<T>());
}

inline unsigned int ofFindInSorted(const vector<string>& sortedValues, const string& target, bool (*compare)(string, string)) {
    return ofFindInSorted(sortedValues, target, compare);
}

//--------------------------------------------------------------
// The following operations are useful for unsorted operations
//--------------------------------------------------------------

template <class T, class CompareFunction>
unsigned int ofxMin(vector<T>& unsortedValues, CompareFunction compare) {
    return std::distance(unsortedValues.begin(), std::min_element(unsortedValues.begin(), unsortedValues.end(), compare));
}

template <class T>
unsigned int ofxMin(vector<T>& unsortedValues) {
    return ofxMin(unsortedValues, ofxOrderAscending<T>());
}

template <class T, class CompareFunction>
unsigned int ofxMax(vector<T>& unsortedValues, CompareFunction compare) {
    return std::distance(unsortedValues.begin(), std::max_element(unsortedValues.begin(), unsortedValues.end(), compare));
}

template <class T>
unsigned int ofxMax(vector<T>& unsortedValues) {
    return ofxMax(unsortedValues, ofxOrderAscending<T>());
}
