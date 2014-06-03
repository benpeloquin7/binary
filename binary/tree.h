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
    /***Constructors***/
    Tree();
    Tree(T n);
    Tree(Tree<T>& r_side); //Copy constructor
    
    /***Tree***/
    void add(T n);
    void balance();
    T b_search(T n);
    int getNumElements();
    b_treeNode<T>* returnRoot();
    
    /***Vec***/
    void updateVec(T n);
    void printVec();
    
    /***Display tree***/
    void pre_order();
    void post_order();
    void in_order();
    
    ~Tree();
    
private:
    /***Helpers***/
    void remove(b_treeNode<T>*& link);
    void add(b_treeNode<T>*& link, T n);
    void pre_order(b_treeNode<T>* link);
    void post_order(b_treeNode<T>* link);
    void in_order(b_treeNode<T>* link);
    b_treeNode<T>* copy(b_treeNode<T>* cpy);
    b_treeNode<T>* balance(typename std::vector<T>::iterator start,
                              typename std::vector<T>::iterator end);
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

/**NEED TO WORK ON THIS ->
 GET COPY CONSTRUCTOR WORKING
 DO THIS RECURSIVELY**/
template <typename T>
Tree<T>::Tree(Tree<T>& r_side) {
    h_ptr = copy(r_side.returnRoot());
}

template <typename T>
b_treeNode<T>* Tree<T>::copy(b_treeNode<T>* cpy) {
    
    b_treeNode<T>* temp_node = new b_treeNode<T>; //New Root
    
    if (cpy != NULL) {
        temp_node -> data = cpy -> data;
        if (cpy -> l_link != NULL) {
            temp_node -> l_link = new b_treeNode<T>;
            temp_node -> l_link -> data = cpy -> l_link -> data;
            temp_node -> l_link = copy(cpy -> l_link);
        }
        if (cpy -> r_link != NULL) {
            temp_node -> r_link = new b_treeNode<T>;
            temp_node -> r_link -> data = cpy -> r_link -> data;
            temp_node -> r_link = copy(cpy -> r_link);
        }
    } else
        return cpy;
    
    return temp_node;
}

template <typename T>
b_treeNode<T>* Tree<T>::returnRoot() {
    return h_ptr;
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
void Tree<T>::balance() {
    //remove old tree
    remove(h_ptr);
    typename std::vector<T>::iterator it = vec.begin();
    while (it != vec.end()) {
        ++it;
    }
    
    --it;
    h_ptr = balance(vec.begin(), it);
}

template <typename T>
b_treeNode<T>* Tree<T>::balance(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
    
    b_treeNode<T>* newNode = new b_treeNode<T>;
    
    if (start == end) {
        newNode -> data = *start;
        newNode -> l_link = NULL;
        newNode -> r_link = NULL;
        return newNode;
    } else if (start != end) {
        typename std::vector<T>::iterator it = start;
        
        //if there are only two left
        it += 1;
        if (it == end) {
            newNode -> data = *it;
            --it;
            newNode -> l_link = new b_treeNode<T>;
            newNode -> l_link -> data = *it;
            newNode -> l_link -> l_link = NULL;
            newNode -> l_link -> r_link = NULL;
            newNode -> r_link = NULL;
            return newNode;
        } else {
            it = start; //make sure iterator is set to beginning
            //find total length of array passed over
            int count = 0;
            while (it != end) {
                ++it;
                ++count;
            }
            //find midpoint in vec
            int mid = count / 2;

            count = 0; //reset count to 0
            it = start; //reset iterator
            while (count != mid) {
                ++it;
                ++count;
            }
            
            //root
            newNode -> data = *it;
            
            //left side of tree
            --it;
            newNode -> l_link = balance(start, it);
            
            //right side of tree
            it += 2;
            newNode -> r_link = balance(it, end);
        }
    } else
        return NULL;
    
    return newNode;
    
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
void Tree<T>::remove(b_treeNode<T>*& link) {

    if (link -> l_link == NULL && link -> r_link == NULL) {
        delete link;
        link = NULL;
    } else if (link -> l_link != NULL) {
        remove(link -> l_link);
        delete link;
        link = NULL;
    } else if (link -> r_link != NULL) {
        remove(link -> r_link);
        delete link;
        link = NULL;
    } else
        return;
    
}


template <typename T>
Tree<T>::~Tree() {
    remove(h_ptr);
}


#endif