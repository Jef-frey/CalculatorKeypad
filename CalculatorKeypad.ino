#include "oled.h"
#include "calculator.h"
#include "calculator_display.h"
#include "keyboard.h"
#include "LinkedList.h"

// characters to be displayed
display_buf cal_display;
LinkedList cal_formula;

char read_switch;

void setup() {
  // initialization
//  keyboard_initialize();
  oled_initialize();

  // display the screen as initial state
  cal_display.hello_world();
  print_calculator(cal_display);

}

void loop() {

/*  1. constantly poll and wait for switch press
 *  2. once a press is detected, debounce for 5 ms
 *  3. read in pressed character
 *  4. wait for user 'unpress', debounce for 5 ms
 */
//  read_switch = get_pressed_switch();
//  if (read_switch != ' ') {
//    switch_debounce();
//    
//    if (state == operand_1) {
//        if (isdigit(read_switch) && read_switch != '0') {
//            if (entry_flag == 0) {
//              display_formula.reset_buf();
//              if (display_answer_on_formula == 1){
//                display_formula.display_write(display_operand);
//                display_answer_on_formula = 2;
//              }
//              display_operand.reset_buf();
//            }
//            display_operand.insert_to_end(read_switch);
//            state = operand_2;
//        } else if (read_switch == '.') {
//            if (entry_flag == 0) {
//              display_formula.reset_buf();
//              if (display_answer_on_formula == 1){
//                display_formula.display_write(display_operand);
//                display_answer_on_formula = 2;
//              }
//              display_operand.reset_buf();
//            }
//            display_operand.shift_in(read_switch);
//            state = operand_2;
//        } else if (isoperator(read_switch) && entry_flag != 0) {
//        //this is for when user misclicked operator after entry, user can click another operator to change it
//        //needs to check for entry not empty first, else operator switch does nothing
//            cal_formula.setOperator(read_switch);
//            display_formula.insert_to_end(read_switch);
//        }
//    } else if (state == operand_2) {
//        if (isdigit(read_switch)) {
//            display_operand.shift_in(read_switch);
//        } else if (read_switch == '.' && display_operand.is_char_in_array('.') == 0) {
//            display_operand.shift_in(read_switch);
//        } else if (isoperator(read_switch)) {
//            cal_formula.enterNode(atof(display_operand.get_display_arr()), read_switch, entry_flag);
//            
//            entry_flag = 1;
//            if (display_answer_on_formula == 2){
//              display_formula.reset_buf();
//              display_answer_on_formula = 0;
//            }
//            display_formula.shift_in_arr(display_operand, read_switch);
//            display_operand.reset_buf();
//            state = operand_1;
//        } else if (read_switch == 'E') {
//            cal_formula.enterNode(atof(display_operand.get_display_arr()), read_switch, entry_flag);
//
//            entry_flag = 0;
//            display_answer_on_formula = 1;
//            display_formula.shift_in_arr(display_operand, read_switch);
//            snprintf(display_operand.get_display_arr(), ARR_SIZE, "%20.10g", cal_formula.computeFormula());
//            state = operand_1;
//        }
//    }
//    update_formula(display_formula.get_display_arr(), display_operand.get_display_arr()); 
//
//  }

}
