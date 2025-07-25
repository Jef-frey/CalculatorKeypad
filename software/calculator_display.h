//'calculator_display' will have code related to 'calculator' printing onto the OLED display

#ifndef CALCULATOR_DISPLAY_H
#define CALCULATOR_DISPLAY_H

#include <string.h>

// display buf is used to store the char to be displayed on the oled, row1 for the formula and row2 for the operand
const int ARR_SIZE = 21;

class display_buf {
  public:
    char top_display[ARR_SIZE];
    int top_index;
    char bottom_display[ARR_SIZE];
    int bottom_index;

    // constructor
    display_buf();

    // print hello world to display, used for testing
    void hello_world();
    
    // invoked when a button is pressed and need to be added to the bottom row of the display, if it is the first entry, replace the last char, else shift in the char
    void shift_bottom_display(char new_char);
    
    // invoked when a operator is pressed, aka an operand is entered into the formula
    void update_top_display(char new_oper);

    // invoked when 'Enter' is pressed
    void print_result(long double result);
    
    // invoked after an operand is entered into the formula and bottom row is cleared for new entry
    void clear_bottom_display();

    // invoked after top display is updated while previous result is still on top display, prevents previous result from being shifted in
    void clear_top_display();
    
    // invoked when user needs to change the last operator entered after it is entered
    void edit_last_operator(char new_operator);

    // left shift the display_buf and change the index value accordingly
    int shift_in(char input_char, int index, char * display_addr);

    // move bottom display to top display
    void result_top_display();
};

bool isoperator(char char_in);

#endif
