#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"../include/condition.h"
#include "../include/interpreter.h"

// function to evaluate conditional expressions
bool evaluate_condition(int x, char *op, int y) {
    if(strcmp(op, "==") == 0){ 
        return (x == y);
    } 
    if(strcmp(op, "!=") == 0){
        return (x != y);
    } 
    if(strcmp(op, ">") == 0){
        return (x > y);
    } 
    if(strcmp(op, "<") == 0){
        return (x < y);
    } 
    if(strcmp(op, ">=") == 0){
        return (x >= y);
    } 
    if(strcmp(op, "<=") == 0){
        return (x <= y);
    }
    return 0;
}

   