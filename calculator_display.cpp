#include "calculator_display.h"
#include <cstdio>

display_buf::display_buf() {
  strcpy(top_display,     "                    ");
  top_index = ARR_SIZE - 1;
  strcpy(bottom_display,  "                   0");
  bottom_index = ARR_SIZE - 2;
}

void display_buf::hello_world() {
  strcpy(top_display,     "HELLO WORLD!!!      ");
  strcpy(bottom_display,  "     /*-+9876543210.");
}

void display_buf::shift_bottom_display(char new_char){
  if (bottom_display == "                   0" && new_char != '.') {
//    calculator's first entry (not a '.'), insert the char into the right side
    bottom_display[ARR_SIZE-2] = new_char;
  } else {
//    shift in the next entry
    bottom_index = this->shift_in(new_char, bottom_index, bottom_display);
  }
}

void display_buf::update_top_display(char new_oper){
  
  for (int i = bottom_index; i < ARR_SIZE-1; i++) {
    this->shift_in(bottom_display[i], top_index, top_display);
  }
  
  this->shift_in(new_oper, top_index, top_display);
  
}

void display_buf::print_result(long double result){
  snprintf(top_display, ARR_SIZE, "%20.10g", result);
}

void display_buf::clear_bottom_display(){
  strcpy(bottom_display,  "                   0");
  bottom_index = ARR_SIZE - 2;
}

void display_buf::edit_last_operator(char new_operator){
  top_display[ARR_SIZE-2] = new_operator;
}


int display_buf::shift_in(char input_char, int index, char * display_addr) {

// makes sure it wouldn't shift pass array[0]
  int i_start = (index-1 < 0) ? 0 : index-1;
  
  for (int i = i_start; i < ARR_SIZE - 2; i++) {
    display_addr[i] = display_addr[i+1];
  }
  display_addr[ARR_SIZE-2] = input_char;

  if (index != 0) {
    index--;
  }

  return index;
}
