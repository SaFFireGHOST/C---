#ifndef INTERPRETER_H
#define INTERPRETER_H

struct Variables{
    char var_name[10];
    int value;
};

extern struct Variables var[];
extern int count;
void execute_c_minus_minus(char * code);


#endif /* INTERPRETER_H */
