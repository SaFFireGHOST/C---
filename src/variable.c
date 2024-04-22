
#include <stdio.h>
#include <string.h>
#include "../include/variable.h"
#include "../include/interpreter.h"

// Function to assign a value to a variable in the 'var' array
void assign_variable(int value){
  // Accessing the 'count' index of the 'var' array and assigning the input 'value'
  var[count++].value = value;
}

// Function to create a new variable with a given 'token' and 'value'
void create_variable(char *token, int value){
  // Copying the input 'token' to the 'var_name' field of the 'var' array at index 'count'
  strcpy(var[count].var_name, token);
  // Calling the 'assign_variable' function to set the value for the newly created variable
  assign_variable(value);
}

// Function to get the value of a variable with a given 'token'
int get_variable_value(char * token){
  // Looping through the 'var' array to find the variable with the matching 'token'
  for (int i = 0; i < 10; i++)
  {
    // Comparing the 'var_name' of the current index with the input 'token'
    if(strcmp(var[i].var_name, token) == 0){
      // Returning the value of the variable if found
      return var[i].value;
    }
  }
  // Returning 0 if the variable with the given 'token' is not found
  return 0;
}
