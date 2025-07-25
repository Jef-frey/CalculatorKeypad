#include "LinkedList.h"

// constructor function, creates a node that points to NULL, LinkedList head 
// and tail both point to that node
LinkedList::LinkedList () {
  tail = head;
}


// first node will be set, else a node will be created and add to the LinkedList
void LinkedList::enterNode(long double operand_in, char operator_in) {
  Node * newNode = new Node();
  newNode->operand = operand_in;
  newNode->operator_type = operator_in;
  newNode->next = NULL;
  
  // have the last node points to new node and make the new node the last node
  if (head == NULL) {
    head = newNode;
  } else {
    tail->next = newNode;
  }
  tail = newNode;
}

// member function to edit operator_type
void LinkedList::setOperator(char operator_in) {
  tail->operator_type = operator_in;
}

/* iterate through LinkedList to compute the formula
 *  1. get the operator of the first node
 *  2. perform the corresponding operation between the first and second node
 *  3. delete first node
 *  4. repeat until the end with second node, third node, etc.
 */
 
long double LinkedList::computeFormula() {
  long double result;
  
  /*
   * Iterate through the list, if * or / is found, perform the operation and store the result
   * in the operand of the node that the current node points to. Delete current node and have
   * the previous node points to the next node, if previous node does not exist, set head to
   * point to next node instead, then have the current node points to the next node. Keep moving
   * through the list until the end
   */
  Node* cur_node = head;
  Node* prev_node = head;
  
  while (cur_node != tail) {
    if (cur_node->operator_type == '*') {
      cur_node->next->operand = cur_node->operand * cur_node->next->operand;
      if (prev_node == cur_node) {
        head = cur_node->next;
      }
      else {
        prev_node->next = cur_node->next;
      }
      cur_node = deleteNode(cur_node);
    }
    else if (cur_node->operator_type == '/') {
      cur_node->next->operand = cur_node->operand / cur_node->next->operand;
      if (prev_node == cur_node) {
        head = cur_node->next;
      }
      else {
        prev_node->next = cur_node->next;
      }
      cur_node = deleteNode(cur_node);
    }
    else {
      prev_node = cur_node;
      cur_node = cur_node->next;
    }
  }
  
  result = head->operand;
  while (head != tail) {
    result = head->operand;

    if (head->operator_type == '+') {
      result = result + head->next->operand;
    }
    else if (head->operator_type == '-') {
      result = result - head->next->operand;
    }
    head->next->operand = result;

    deleteHead();
  }

  Node* temp = head;
  delete temp;
  
  return result;
}

// delete input node and return whatever the input node points to
Node * LinkedList::deleteNode(Node * cur_node) {
  Node* temp = cur_node;
  cur_node = cur_node -> next;
  delete temp;
  return cur_node;
}

// remove the first node from LinkedList
void LinkedList::deleteHead() {
  Node* temp = head;
  head = head -> next;
  delete temp;
}

// check if the LinkedList has at least one node
bool LinkedList::isEmpty(){
  if (head == NULL){
    return true;
  } else {
    return false;
  }
}
