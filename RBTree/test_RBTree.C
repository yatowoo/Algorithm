// Test File for RBTree
// ROOT Macro on root_v6

#include "RBTree.hpp"

RBTree* rb; // for ROOT CINT use

void RandomInsert(RBTree* rb, int num){
    Node_t* node = NULL;
    for(int i = 0 ; i < num ; i ++){
        node = new Node_t(
            (int)gRandom->Uniform(0,50),
            'b'+i);
        rb->Insert(node);
    }    
}

int test_RBTree(){

    Node_t* node = new Node_t(50,'a');
    rb = new RBTree(node);

    rb->Insert(new Node_t(30,'b'));
    rb->Insert(new Node_t(34,'c'));

    rb->TraverseMid(rb->fRoot);

    return 0;
}