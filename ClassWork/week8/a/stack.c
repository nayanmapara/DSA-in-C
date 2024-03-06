
// include stack header-file
#include "stack.h"

int main(void) {
	
	// create stack pointer
	StackNodePtr stackPtr;
	stackPtr = NULL;
	
	int choice;
	int value;
	
	instructions();
	printf("? ");
	scanf("%d", &choice);
	
	while(choice != 7) {
	   switch(choice) {
		case 1:
			printf("Enter an integer: ");
			scanf("%d", &value);
			//push node onto stack
			stackPtr = push(stackPtr, value);
			printStack(stackPtr); //print the stack nodes
			break;
		case 2:
			if(!isEmpty(stackPtr)) {
			//	pop node from stack
			stackPtr = pop(stackPtr);
			}
			//print the current stack nodes
			printStack(stackPtr);
			break;

        case 3: 
            if(!isEmpty(stackPtr)) {
			//	print node at the top of the stack
			topOfStack(stackPtr);
			}
            else{
				puts("The Stack is Empty");
            }
            break;
		case 4:
			bottomOfStack(stackPtr);
			break;
		case 5:
			printf("Enter an integer: ");
			scanf("%d", &value);
			searchStack(stackPtr, value);
			break;
		case 6:
			printStack(stackPtr);
			break;
		default:
			printf("Invalid choice.\n\n");
			break;
		}
		instructions();
	        printf("? ");
		scanf("%d", &choice);
	}
	
	printf("End of run.\n");
	
}





