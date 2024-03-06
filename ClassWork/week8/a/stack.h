#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct stackNode
{
	int data;
	struct stackNode *nextPtr;
};

// Type renaming using typedef
typedef struct stackNode StackNode;
typedef struct stackNode *StackNodePtr;

/* Function Protypes */
StackNodePtr push(StackNodePtr topPtr, int info);
StackNodePtr pop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void topOfStack(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);
void bottomOfStack(StackNodePtr topPtr);
StackNodePtr searchStack(StackNodePtr topPtr , int value);

/*.......Function Definitions .....*/
StackNodePtr push(StackNodePtr topPtr, int info)
{
	StackNodePtr newPtr; // Initialise pointer for new StackNode

	newPtr = (StackNodePtr)malloc(sizeof(StackNode)); // Create memory for new StackNode

	// Push new StackNode onto top-of-stack
	if (newPtr != NULL)
	{
		// add code to push
		newPtr->data = info;
		newPtr->nextPtr = topPtr;
		topPtr = newPtr;
	}
	else
	{
		printf("%d not inserted. No memory available.\n", info);
	}
	return topPtr;
	// return pointer to top-of-stack;
}

StackNodePtr pop(StackNodePtr topPtr)
{
	// Initialise temporary pointer to hold address of StackNode to pop
	StackNodePtr tempPtr;
	/* add code to pop StackNode from the top-of-stack */
	// isolate StackNode to be deleted / popped
	tempPtr = topPtr;
	// inform user of Node to be popped
	printf("%d is being popped.\n", topPtr->data);
	// update topPtr
	topPtr = topPtr->nextPtr;
	// deallocate memory
	free(tempPtr);
	// return pointer to top-of-stack
	return topPtr;
}

void printStack(StackNodePtr topPtr)
{
	StackNodePtr currentPtr = topPtr;
	if (currentPtr == NULL /*stack is empty*/)
	{
		// inform user "The stack is empty"
		puts("The stack is empty.\n\n");
	}
	else
	{
		printf("The stack is:\n");
		while (currentPtr != NULL /*not at the end of stack*/)
		{
			// print current node
			printf("%d --> ", currentPtr->data);
			// move onto the next node
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

int isEmpty(StackNodePtr topPtr)
{
	// return true if topPtr is NULL of False otherwise;
	return (topPtr == NULL);
}

void topOfStack(StackNodePtr topPtr)
{

	// display value at the top-of-stack
	printf("The value at the top of the stack is %d\n\n", topPtr->data);
}

void instructions(void)
{
	printf("Enter choice:\n1 to push a value on the stack\n2 to pop a value off the stack\n3 Top of the stack \n4 Bottom of the stack \n5 Search the stack \n6 Print the stack \n7 to end the program\n");
}

void bottomOfStack(StackNodePtr topPtr)
{
	StackNodePtr previousPtr, currentPtr = topPtr;

	while(currentPtr != NULL)
	{
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	if (previousPtr != NULL)
	{
		printf("The value of the bottom of the stack is %d\n", previousPtr->data);
	}
	else
	{
		puts("The stack is empty");
	}
}


StackNodePtr searchStack(StackNodePtr topPtr , int value)
{
	StackNodePtr currentPtr = topPtr;
	int position = 1;

	if (currentPtr == NULL)
	{
		puts("The stack is empty");
		return NULL;
	}

	while (currentPtr != NULL && value != currentPtr->data)
	{
		currentPtr = currentPtr->nextPtr;
	}

	if (currentPtr != NULL)
	{
		printf("The value %d is at position %d\n", value, position);
		return currentPtr;
	}
	else
	{
		puts("The value is not in the stack");
		return NULL;
	}


}
