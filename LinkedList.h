#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
  long double operand;
  char        operator_type;
  Node *      next;
};

class LinkedList {
  Node *  head;
  Node *  tail;
  public:
    LinkedList();

//    this function add another node to the linked list
    void appendList(long double operand_in, char operator_in);

    void setFirstNode(long double operand_in, char operator_in);

    void enterNode(long double operand_in, char operator_in, int entry_flag);

    void setOperator(char operator_in);

    long double computeFormula();

    void deleteHead();

    Node * deleteNode(Node * ptr);
};

#endif
