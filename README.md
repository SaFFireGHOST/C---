CMinus- Interpreter Project

CMinus- Interpreter is a simple interpreter for a custom programming language called CMinus-. This interpreter can execute CMinus- code which consists of  arithmetic operations, variable declarations, conditional statements and print statements.

The source files - "main.c","interpreter.c","arithmetic.c","print.c","condition.c","variable.c", are present in the src folder.

The header files - "interpreter.h","arithmetic.h","print.h","condition.h","variable.h", are present in the include folder.

The code in CMinus- langauage is written in main.c inside the code[].

The project as of now supports '+','-','*','/' arithmetic operators.
The datatype supported as of now is only int.

The line terminating symbol is ';' .

The syntax for :
a.) Variable Declaration - int a = 100;
b.) Printing variables - print a;
                    *  output - 100
* Everytime we print something, it automatically goes to the nextline.
d.) If block - 		 if ( a < 50 ) {;
                            print 50;
                            };
                         
* Only single if block is supported 

e.) Arithmetic Operations - int a = 10 + 2;

To run the CMinus- Interpreter,
Step-1:Download the folder 'IMT2022570'.
Step-2:Open Terminal in your system and go the IMT2022570 directory
STep-3:Enter the command "make"
Step-4:Enter the command-"./IMT2022570"
* You get all the object files in an obj folder(which is created if it isn't already created).
