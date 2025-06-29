#include "calculator.h"
#include "oled.h"

calculator::calculator() {
  state = idle;
//  init linked list
//  calculator_display
}

void calculator::operate_input(char input_char) {

  switch (state){
    
    case idle:
      if (isdigit(input_char)) {
        calculator_display.shift_bottom_display(input_char);
        state = integer;
      } else if (input_char == '.') {
        calculator_display.shift_bottom_display(input_char);
        state = decminal;
      }
      break;
      
    case integer:
      if (isdigit(input_char)) {
        calculator_display.shift_bottom_display(input_char);
        state = integer;
      } else if (input_char == '.') {
        calculator_display.shift_bottom_display(input_char);
        state = decminal;
      } else if (isoperator(input_char)) {        
        calculator_display.update_top_display(input_char);
        calculator_display.clear_bottom_display();
        state = operating;
      } else if (input_char == 'E') {
//        only run if linkedlist has more than one node
        last_result = 0; // calculated by LinkedList
        calculator_display.update_top_display(input_char);
        calculator_display.print_result(last_result);
        state = result;
      }
      break;
      
    case decminal:
      if (isdigit(input_char)) {
        calculator_display.shift_bottom_display(input_char);
        state = decminal;
      } else if (isoperator(input_char)) {
        calculator_display.update_top_display(input_char);
        calculator_display.clear_bottom_display();
        state = operating;
      } else if (input_char == 'E') {
//        only run if linkedlist has more than one node
        last_result = 0; // calculated by LinkedList
        calculator_display.update_top_display(input_char);
        calculator_display.print_result(last_result);
        state = result;
      }
      break;
      
    case operating:
      if (isdigit(input_char)) {
        calculator_display.shift_bottom_display(input_char);
        state = integer;
      } else if (input_char == '.') {
        calculator_display.shift_bottom_display(input_char);
        state = decminal;
      } else if (isoperator(input_char)) {
        calculator_display.edit_last_operator(input_char);
        state = operating;
      } else if (input_char == 'E') {
//        only run if linkedlist has more than one node and last_node is not nan
        calculator_display.update_top_display(input_char);
        calculator_display.print_result(last_result);
        state = result;
      }
      break;

     case result:
      if (isdigit(input_char)) {
        calculator_display.result_top_display();
        calculator_display.clear_bottom_display();
        calculator_display.shift_bottom_display(input_char);
        state = integer;
      } else if (input_char == '.') {
        calculator_display.result_top_display();
        calculator_display.clear_bottom_display();
        calculator_display.shift_bottom_display(input_char);
        state = decminal;
      } else if (isoperator(input_char)) {
        calculator_display.update_top_display(input_char);
        calculator_display.clear_bottom_display();
        state = operating;
      }
      break;

  }
  print_calculator(calculator_display);
  
}

void calculator::calculator_on() {
  print_calculator(calculator_display);
}
