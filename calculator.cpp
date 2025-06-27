#include "calculator.h"

//display_buf::display_buf(buf_type buffer_type_in) {
//  buffer_type = buffer_type_in;
//  
//  if (buffer_type == formula) {
//    strcpy(display_arr, "                    ");
//    index = ARR_SIZE - 1;
//  } else {
//    strcpy(display_arr, "                   0");
//    index = ARR_SIZE - 2;
//  }
//}
//
//void display_buf::reset_buf() {
//  if (buffer_type == formula) {
//    strcpy(display_arr, "                    ");
//    index = ARR_SIZE - 1;
//  } else {
//    strcpy(display_arr, "                   0");
//    index = ARR_SIZE - 2;
//  }
//}
//
////this function replace the array with the input array
//void display_buf::display_write(display_buf buf_in) {
//  strcpy(display_arr, buf_in.display_arr);
//}
//
//void display_buf::insert_to_end(char input_char){
//  display_arr[ARR_SIZE-2] = input_char;
//
//}
//
//void display_buf::shift_in(char input_char) {
//
//// makes sure it wouldn't shift pass array[0]
//  int i_start = (index-1 < 0) ? 0 : index-1;
//  
//  for (int i = i_start; i < ARR_SIZE - 2; i++) {
//    display_arr[i] = display_arr[i+1];
//  }
//  display_arr[ARR_SIZE-2] = input_char;
//
//  if (index != 0) {
//    index--;
//  }
//}
//
//// shift the content of append_arr to this arr
//void display_buf::shift_in_arr(display_buf append_buf, char oper) {
//
//  for (int i = append_buf.index; i < ARR_SIZE-1; i++) {
//    this->shift_in(append_buf.display_arr[i]);
//  }
//
//  if (oper != 'E'){
//    this->shift_in(oper);
//  }
//}
//
//char * display_buf::get_display_arr(){
//  return display_arr;
//}
//
//void display_buf::hello_world() {
//  strcpy(display_arr, "HELLO WORLD!!!      ");
//}
//
//int display_buf::get_index() {
//  return index;
//}
//
//// return 1 if char is found in array, else return 0
//int display_buf::is_char_in_array(char in) {
//    for (int i = 0; i < ARR_SIZE - 1; i++) {
//        if (display_arr[i] == in) {
//            return 1;
//        }
//    }
//    return 0;
//}
