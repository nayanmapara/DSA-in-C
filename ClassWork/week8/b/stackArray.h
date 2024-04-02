// array implementation of a stack data structure
#include <stdio.h>
#include <stdlib.h>
#define MaxStack 10
#define EmptyValue -9999
// structure definition
typedef struct stackType{
   int top;
   int store[MaxStack];
} StackType, *StackTypePtr;

// function prototypes 
StackTypePtr initStack();
int isEmpty (StackTypePtr stackPtr);
int isFull (StackTypePtr stackPtr);
void push (StackTypePtr stackPtr, int value);
int pop (StackTypePtr stackPtr);
void top(StackTypePtr stackPtr);
void bottom(StackTypePtr stackPtr);
/*......Function Definitions..........*/
StackTypePtr initStack()
{
   // Initialise pointer to Stack, stackPtr
   StackTypePtr stackPtr;
   // Create memory for Stack
   stackPtr = (StackTypePtr)malloc(sizeof(StackType));
   // Initialise Stack;
   if (stackPtr != NULL){ stackPtr->top = -1;} 
   else { printf("Memory Issues... Stack could not be created\n");}
   // return pointer to Stack
   return stackPtr;
}
int isEmpty (StackTypePtr stackPtr)
{ // return true if top value == -1
   return (stackPtr->top == -1);}
int isFull (StackTypePtr stackPtr)
{ // return true if top value == MaxStack - 1
   return (stackPtr->top == MaxStack - 1);}
void push (StackTypePtr stackPtr, int value)
{
  if (isFull(stackPtr)/*check if stack is full*/)
  {// inform user of "Stack Overflow"
     puts("Stack Overflow");}
  else{ /* Add code to insert value at the top-of-stack*/
        // increment top value
        ++(stackPtr->top);     
        // Place value at store[top]
        stackPtr->store[stackPtr->top] = value;}
}
int pop (StackTypePtr stackPtr) 
{// initialise variable to store popValue
   int popValue = 0;
   if(isEmpty(stackPtr)/*check if stack is empty before popping*/){// inform user "Stack is Empty"
      puts("Stack is Empty");
      // return empty value;
      return EmptyValue;}
   else{ /* Add code to remove value from the top-of-stack */
         // preserve value at the top-of-stack store[top];
         popValue = stackPtr->store[stackPtr->top];
         // decrement top
         --(stackPtr->top);
         // return value that was popped;
         return popValue;}   
}
void top(StackTypePtr stackPtr)
{ if (isEmpty(stackPtr)){ puts("Stack is Empty");}
   else{printf("The top of the stack is %d\n", stackPtr->store[stackPtr->top]);}
}
void bottom(StackTypePtr stackPtr)
{ if (isEmpty(stackPtr)){ puts("Stack is Empty");}
   else{printf("The bottom of the stack is %d\n", stackPtr->store[0]);}
}