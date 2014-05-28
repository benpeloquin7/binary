//
//  b_treeNode.h
//  binary
//
//  Created by Ben Peloquin on 5/28/14.
//  Copyright (c) 2014 B. Peloquin. All rights reserved.
//

#ifndef binary_b_treeNode_h
#define binary_b_treeNode_h

template <typename T>
struct b_treeNode {
    T data;
    b_treeNode* r_link;
    b_treeNode* l_link;
};

#endif
