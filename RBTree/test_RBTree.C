// Test File for RBTree
// ROOT Macro on root_v6

#include "RBTree.hpp"

RBTree* rb;

int test_RBTree(){

    Node_t* node = new Node_t(50,'a');
    rb = new RBTree(node);

    for(int i = 0 ; i < 10 ; i ++){
        node = new Node_t(
            (int)gRandom->Uniform(0,100),
            'b'+i);
        rb->Insert(node);
    }

    rb->TraverseMid(rb->fRoot);

    return 0;
}