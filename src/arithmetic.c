#include<stdio.h>
#include"../include/interpreter.h"
#include"../include/arithmetic.h"


// function to perform arithmetic operations
int perform_arithmetic(int x, char *op, int y){
  if(op[0] == '+'){
    return (x+y);
  }
  if(op[0] == '-'){
    return (x-y);
  }
  if(op[0] == '*'){
    return (x*y);
  }
  if(op[0] == '/'){
    return (x/y);
  }
  
  return 0;
}