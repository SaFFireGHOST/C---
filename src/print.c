#include<stdio.h>
#include<string.h>
#include"../include/print.h"
#include"../include/variable.h"
#include "../include/interpreter.h"

// function to print the value of the variable
void print_variable(char *token){
  printf("%d\n",get_variable_value(token));
}