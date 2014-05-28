//
//  tree.h
//  binary
//
//  Created by Ben Peloquin on 5/28/14.
//  Copyright (c) 2014 B. Peloquin. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include "b_treeNode.h"

template <typename T>
class Tree {

public:
    Tree();
    Tree(T n);
    void add();
    T b_search(T n);
    void pre_order();
    void post_order();
    void in_order();
    
private:
    b_treeNode<T>* h_ptr;
    b_treeNode<T>* m_ptr;
};

template <typename T>
Tree<T>::Tree() {
    h_ptr = NULL;
    m_ptr = NULL;
}

template <typename T>
Tree<T>::Tree(T n) {
    h_ptr = new b_treeNode<T>;
    h_ptr -> data = n;
    h_ptr -> r_link = NULL;
    h_ptr -> l_link = NULL;
    m_ptr = h_ptr;
}

#endif