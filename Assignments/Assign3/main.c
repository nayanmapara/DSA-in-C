#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    
    printf("Choose an option:\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("3. Tree\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            system("gcc -o stack_program stack.c");
            system("./stack_program");
            break;
        case 2:
            system("gcc -o queue_program queue.c");
            system("./queue_program");
            break;
        case 3:
            system("gcc -o tree_program tree.c");
            system("./tree_program");
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    
    return 0;
}
