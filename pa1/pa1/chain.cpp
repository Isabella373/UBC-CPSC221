#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
/* YOUR CODE HERE */
clear();
delete head_;
head_ = NULL;
length_ = 0;
height_ = 0;
width_ = 0;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
/* YOUR CODE HERE */

Node * newNode = new Node(ndata);
newNode->next = head_;
if(head_->next == NULL){
    head_->next = newNode;
}
Node * temp = head_;
while(temp->next != head_){
    temp = temp->next;
}

temp->next = newNode;

length_ = length_ +1;
height_ = ndata.height();
width_ = ndata.width();

}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
/* YOUR CODE HERE */

Node * temp1 = head_;
Node * temp2 = head_;
while(i != 1){
    i = i-1;
    temp1 = temp1->next;

}
Node * node1 = temp1->next;
while(j != 1){
    j = j-1;
    temp2 = temp1->next;

}
Node * node2 = temp2->next;

temp1->next = node2;
Node * node2_next = node2->next;

node2->next = node1->next;
temp2->next = node1;
node1->next = node2_next;
return;
}



/**
 * Reverses the chain
 */
void Chain::reverse()
{
/* YOUR CODE HERE */
if(head_ ->next == NULL){
    return;
}
    vector<Node*> vec;
    vec.resize(length_);
    Node *curr = head_->next;
    for(int i= 0; i<length_; i++){
        vec[i] = curr;
        curr = curr->next;
    }
    curr = head_;
    for(int i =length_ -1; i>=0; i--){
        curr->next = vec[i];
        curr = curr->next;
    }
    curr->next = head_;

    
}


/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
/* YOUR CODE HERE */
if(length_ == 0 || k<=1 || k>length_){
    return;
}
else{
    int change = 1;
    while(change+k-1<= length_){
        Node* first = walk(head_, change);
        Node* last = walk(head_, change+k-1);
        Node* first_pre = walk(head_, change-1);
        first_pre->next = first->next;
        first->next = last->next;
        last->next = first;
        change = change + k;
    }
   
}
}

/**
 * Destroys ALL dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
/* YOUR CODE HERE */
int i = length_;
while(i >0){
    Node* temp = walk(head_, i);
    delete temp;
    temp = NULL;
    i = i-1;
}


}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* YOUR CODE HERE */
head_ = new Node();
height_ = other.height_;
width_ = other.width_;
Node* curr = this->head_;
Node* other_node = other.head_->next;
while(other_node != other.head_){
    Node* newNode = new Node(other_node->data);
    curr->next = newNode;
    curr = curr->next;
    other_node = other_node->next;
    
}
curr->next = this->head_;
length_ = other.length_;
}
