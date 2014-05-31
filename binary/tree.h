//
//  tree.h
//  binary
//
//  Created by Ben Peloquin on 5/28/14.
//  Copyright (c) 2014 B. Peloquin. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <vector>
#include <iterator>
#include "b_treeNode.h"
using std::cout;

template <typename T>
class Tree {

public:
    Tree();
    Tree(T n);
    //Tree (T std::vector<T>::iterator); //pointer to an array
    void add(T n);
    T b_search(T n);
    int getNumElements();
    void updateVec(T n);
    void printVec();
    void pre_order();
    void post_order();
    void in_order();
    ~Tree();
    
private:
    /***Helpers***/
    void add(b_treeNode<T>*& link, T n);
    void pre_order(b_treeNode<T>* link);
    void post_order(b_treeNode<T>* link);
    void in_order(b_treeNode<T>* link);
    
    b_treeNode<T>* h_ptr;
    b_treeNode<T>* m_ptr;
    
    std::vector<T> vec;
    int numElements;
};

template <typename T>
Tree<T>::Tree() {
    h_ptr = NULL;
    m_ptr = NULL;
}

template <typename T>
Tree<T>::Tree(T n) {
    h_ptr = NULL;
    m_ptr = h_ptr;
    add(h_ptr, n);
    ++numElements;
}

template <typename T>
void Tree<T>::add(T n) {
    add(h_ptr, n);
    ++numElements;
}

template <typename T>
void Tree<T>::add(b_treeNode<T>*& link, T n) {
    if (link == NULL) {
        link = new b_treeNode<T>;
        link -> data = n;
        link -> r_link = NULL;
        link -> l_link = NULL;
        
        updateVec(n);
    } else {
        if (link -> data > n)
            add(link -> l_link, n);
        else
            add(link -> r_link, n);
    }
}

template <typename T>
int Tree<T>::getNumElements() {
    return numElements;
}

template <typename T>
void Tree<T>::updateVec(T n) {
    vec.push_back(n);
    std::sort(vec.begin(), vec.end());
}

template <typename T>
void Tree<T>::printVec() {

    typename std::vector<T>::iterator it = vec.begin();

    while (it != vec.end()) {
        cout << *it << ' ';
        ++it;
    }

}

template <typename T>
void Tree<T>::pre_order() {
    pre_order(h_ptr);
}

template <typename T>
void Tree<T>::post_order() {
    post_order(h_ptr);
}

template <typename T>
void Tree<T>::in_order() {
    in_order(h_ptr);
}

template <typename T>
void Tree<T>::pre_order(b_treeNode<T>* link) {
    if (link == NULL)
        return;
    else {
        cout << link -> data << ' ';
        pre_order(link -> l_link);
        pre_order(link -> r_link);
    }

}

template <typename T>
void Tree<T>::post_order(b_treeNode<T>* link) {
    if (link == NULL)
        return;
    else {
        post_order(link -> l_link);
        post_order(link -> r_link);
        cout << link -> data << ' ';
    }
    
}

template <typename T>
void Tree<T>::in_order(b_treeNode<T>* link) {
    if (link == NULL)
        return;
    else {
        in_order(link -> l_link);
        cout << link -> data << ' ';
        in_order(link -> r_link);
    }
}

template <typename T>
Tree<T>::~Tree() {
    delete h_ptr;
    h_ptr = NULL;
}

#endif