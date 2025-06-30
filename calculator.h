//'calculator' will have code directly related to parsing keyboard input, calculation, and output to calculator_display 

/*
 * calculator has four states: idle, integer, decminal, and operating
 * input can be separated into four types: number, radix, operator, enter, result
 * 
 *  state-transition table
 *  INPUT    | STATE     | STATE_NEXT | ACTION
 *  number   | idle      | integer    | shift_bottom_display (insert number to bottom display)
 *  radix    | idle      | decminal   | shift_bottom_display (shift '.' to bottom display)
 *  number   | integer   | integer    | shift_bottom_display (shift number to bottom display)
 *  radix    | integer   | decminal   | shift_bottom_display (shift '.' to bottom display)
 *  operator | integer   | operating  | update_top_display, clear_bottom_display (append bottom string to top display, reset bottom display)
 *                                      appendList (create a node with the operand and operator, then add node to the list)
 *  enter    | integer   | result     | update_top_display, print_result (print the result to bottom display, append bottom string to top display)
 *                                      computeFormula (get the result and clear the LinkedList in the process)
 *  number   | decminal  | decminal   | shift_bottom_display (insert number to bottom display)
 *  operator | decminal  | operating  | update_top_display, clear_bottom_display (append bottom string to top display, reset bottom display)
 *                                      appendList (create a node with the operand and operator, then add node to the list)
 *  enter    | decminal  | result     | update_top_display, print_result (print the result to bottom display, append bottom string to top display)
 *                                      computeFormula (get the result and clear the LinkedList in the process)
 *  number   | operating | integer    | shift_bottom_display (insert number to bottom display)
 *  radix    | operating | decminal   | shift_bottom_display (shift '.' to bottom display)
 *  operator | operating | operating  | edit_last_operator (correct the operator entered)
 *                                      setOperator (change the operator on the last node)
 *                                      
 *  enter    | operating | result     | update_top_display, print_result (print the result to bottom display, append bottom string to top display)
 *                                      computeFormula (get the result with last_result as the last operand and clear the LinkedList in the process)
 *                                      
 *  number   | result    | integer    | result_top_display, clear_bottom_display, shift_bottom_display (put result to top display, clear and shift in bottom dipslay)
 *  radix    | result    | decminal   | result_top_display, clear_bottom_display, shift_bottom_display (put result to top display, clear and shift in bottom dipslay)
 *  operator | result    | operating  | update_top_display, clear_bottom_display (append bottom string to top display, reset bottom display)
 *                                      appendList (create a node with the last_result as the operand, then add node to the list)
 *                                      
 *  
 *  *if input is enter but there is only one node on LinkedList, do nothing
 */

//when it goes from result->dec/int->operating, the previous result needs to be deleted 

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "LinkedList.h"
#include "calculator_display.h"

enum calculator_state {
  idle,
  integer,
  decminal,
  operating,
  result
};

class calculator {
  public:
    long double       last_result;
    calculator_state  state;
    LinkedList        formula;
    display_buf       calculator_display;

    // constructor
    calculator();

    void operate_input(char input_char);

    //used to print whatever is on the calculator when the device first enters calculator_mode
    void calculator_on();
};

#endif
