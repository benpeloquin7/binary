//
//  main.cpp
//  binary
//
//  Created by Ben Peloquin on 5/28/14.
//  Copyright (c) 2014 B. Peloquin. All rights reserved.
//

#include <iostream>
#include "tree.h"
#include "b_treeNode.h"
using namespace std;

int main() {

    Tree<int> bTree(8);
    bTree.add(12);
    bTree.add(13);
    bTree.add(213);
    bTree.add(312);
    bTree.add(1);
    
    /*
    cout << "Pre-Order: ";
    bTree.pre_order();
    
    cout << "\nPost-Order: ";
    bTree.post_order();
    
    cout << "\nIn_Order: ";
    bTree.in_order();
    */
    cout << "\nBalancing tree..." << endl;
    bTree.balance();
    
    Tree<int> cTree(bTree);
    /*
    cout << "Printing vector...";
    bTree.printVec();
    
    cout << "\nBalanced Pre-Order: ";
    bTree.pre_order();
    
    cout << "\nBalanced Post-Order: ";
    bTree.post_order();
    
    cout << "\nBalanced In_Order: ";
    bTree.in_order();
    */
    
    cout << "\nPrinting bTree in_order: ";
    bTree.in_order();
    
    cout << "\nPrinting cTree in-order: ";
    cTree.in_order();
    
     
    return 0;
}

