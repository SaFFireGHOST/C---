#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"../include/arithmetic.h"
#include"../include/interpreter.h"
#include"../include/variable.h"
#include"../include/print.h"
#include"../include/condition.h"

int count = 0;
struct Variables var[10];


// Function to execute C-- code
void execute_c_minus_minus(char *code) {
  // Array to store individual commands
  char commands[20][40];

  // Tokenize the input code into individual commands
  char *token = strtok(code, ";");
  int commandIndex = 0;

  // Store commands in the array
  while (token != NULL) {
    strcpy(commands[commandIndex++], token);
    token = strtok(NULL, ";");
  }

  // Variables for arithmetic operations
  int operand1, operand2;

  // Loop through each command and execute
  for (int commandIdx = 0; commandIdx < commandIndex; commandIdx++) {
    // Check if the command is a variable declaration or assignment
    if (strncmp(commands[commandIdx], "int", 3) == 0 || strncmp(commands[commandIdx], "    int", 7) == 0) {
      // Parsing left and right parts of the command
      char *leftPart = strtok(commands[commandIdx], "=");
      char *rightPart = strtok(NULL, ";");
      char *variable = strtok(leftPart, " ");
      variable = strtok(NULL, " ");
      char *term1, *term2, *operator;

      // Parsing right-hand side of the assignment
      term1 = strtok(rightPart, " ");
      operator = strtok(NULL, " ");
      term2 = strtok(NULL, " ");

      // If the term is a number, assign it to operand1
      if (sscanf(term1, "%d", &operand1) == 1) {
      } else {
        operand1 = get_variable_value(term1);
      }

      // If there is a second term, assign it to operand2
      if (term2 != NULL) {
        if (sscanf(term2, "%d", &operand2) == 1) {
        } else {
          operand2 = get_variable_value(term2);
        }
      }

      // If no operator, create a variable; otherwise, perform arithmetic and create variable
      if (operator == NULL)
        create_variable(variable, operand1);
      else {
        create_variable(variable, perform_arithmetic(operand1, operator, operand2));
      }
    }
    // Check if the command is a print statement
    else if ((strncmp(commands[commandIdx], "print", 5) == 0) || strncmp(commands[commandIdx], "    print", 9) == 0) {
      // Get the variable name to print
      token = strtok(commands[commandIdx], " ");
      token = strtok(NULL, " ");
      // Print the variable
      print_variable(token);
    }
    // Check if the command is an if statement
    else if (strncmp(commands[commandIdx], "if", 2) == 0) {
      // Parsing the condition within the if statement
      token = strtok(commands[commandIdx], "(");
      token = strtok(NULL, ")");
      int leftOperand, rightOperand;

      // Parsing left-hand side of the condition
      char *leftHandSide = strtok(token, " ");
      // If the term is a number, assign it to leftOperand
      if (sscanf(leftHandSide, "%d", &leftOperand) == 1) {
      } else {
        leftOperand = get_variable_value(leftHandSide);
      }

      // Parsing comparison operator and right-hand side of the condition
      char *comparisonOperator = strtok(NULL, " ");
      char *rightHandSide = strtok(NULL, " ");
      // If the term is a number, assign it to rightOperand
      if (sscanf(rightHandSide, "%d", &rightOperand) == 1) {
      } else {
        rightOperand = get_variable_value(rightHandSide);
      }

      // Evaluate the condition; if false, skip to the end of the if block
      if (!evaluate_condition(leftOperand, comparisonOperator, rightOperand)) {
        int nextCommandIndex = commandIdx + 1;
        while (strncmp(commands[nextCommandIndex], "}", 1) != 0) {
          nextCommandIndex++;
        }
        commandIdx = nextCommandIndex + 1;
      }
    }
  }
}


