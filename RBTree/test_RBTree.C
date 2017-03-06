// Test File for RBTree
// ROOT Macro on root_v6

#include "RBTree.hpp"

RBTree* rb; // for ROOT CINT use

const int KEY[] = {49,8,14,47,11,24,40,37,27,36};

void RandomInsert(RBTree* rb, int num){
    Node_t* node = NULL;
    for(int i = 0 ; i < num ; i ++){
        node = new Node_t(KEY[i],'b'+i);
        rb->Insert(node);
    }    
}

int test_RBTree(){

    Node_t* node = new Node_t(50,'a');
    rb = new RBTree(node);

    //rb->Insert(new Node_t(30,'b'));
    //rb->Insert(new Node_t(34,'c'));
    RandomInsert(rb,10);

    rb->TraverseMid(rb->fRoot);

    return 0;
}