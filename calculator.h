#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string.h>

//// display buf is used to store the char to be displayed on the oled, row1 for the formula and row2 for the operand
//const int ARR_SIZE = 21;

enum operand_state {
  operand_1,
  operand_2
};

enum buf_type {
  formula,
  operand
};

//class display_buf {
//  public:
//    char display_arr[ARR_SIZE];
//    int index;
//    buf_type buffer_type;
//
//    display_buf(buf_type buffer_type_in);
//
//    void hello_world();
//
//    char * get_display_arr();
//
//    void reset_buf();
//
//    void insert_to_end(char input_char);
//
//    void shift_in(char input_char);
//
//    void shift_in_arr(display_buf append_arr, char oper);
//
//    int get_index();
//
//    int is_char_in_array(char in);
//
//    void display_write(display_buf buf_in);
//};

#endif
