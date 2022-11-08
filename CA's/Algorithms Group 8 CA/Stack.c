#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// stack structure and properties. stack holds string items
struct stack_structure{
  // array of strings can hold maximum of 100 strings each of maximum length 20
    char items[100][20];
    // keeps track of the top-most element i.e the number of elements in the stack
    int pointer;
    int size;
};

void printStack(struct stack_structure stack){
    int i;
    printf("Stack:\n");
    for (i = stack.size - 1; i >= 0; i--){
    	if (i == stack.pointer-1)	printf("  pointer--> ");	// prints an arrow pointer to the top element
    	else printf("             ");
        if (i >= stack.pointer)	printf("\t| (empty)");	// print empty where there's no item
        else printf("\t| %s",stack.items[i]);				// else prints the item
        printf("\n");
    }
    printf("\nSize is %d and pointer is %d\n",stack.size, stack.pointer);
    printf("\n");
}
int isEmpty(struct stack_structure stack){
    if (stack.pointer == 0) return 1;
    else return 0;
}
int isFull(struct stack_structure stack){
    if (stack.pointer == stack.size ) return 1;
    else return 0;
}
char *peek(struct stack_structure *stack){
    if (isEmpty(*stack)) return NULL;	// returns NULL when the stack is empty (pointer is 0)
    return stack->items[stack->pointer - 1];
}
void push(struct stack_structure *stack, char item[10]){
	// the stack gets full when pointer equals stack size
    if (isFull(*stack)){
        printf("Can't push %s. Stack is full\n", item);
    }
    else{
        stack->pointer ++;	// increments pointer before pushing item
        strcpy(stack->items[stack->pointer - 1], item);
    }
}
char *pop(struct stack_structure *stack){
	// stack is empty when pointer equals 0
    if (isEmpty(*stack)) {
        printf("Can't Pop Item. Stack is Empty\n");
        return NULL;
    }
    else {
    	char *item;
    	item = (char *)malloc(sizeof(char)*20);
        item = stack->items[stack->pointer - 1];
        stack->pointer --;		// decrements pointer since top value has been removed
        return item;
    }
}
int main(){
    struct stack_structure myStack; //creating myStack of type, stack_structure
    int option, num, i;
    char choice, *data = (char *)malloc(sizeof(char)*20);
    printf("Enter stack size: ");
    scanf("%d",&myStack.size);
    myStack.pointer = 0;		// setting pointer to 0 since stack is empty
    printf("Stack successfully created\n");
    printStack(myStack);
    do{
        printf("STACK OPERTATIONS\n\n");
        printf("1. Push in to stack\n");
        printf("2. Pop out of stack\n");
        printf("3. Peek stack\n");
        printf("4. Check if stack is full\n");
        printf("5. Check if stack is empty\n");
        printf("6. Display stack\n\n");
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option){
            case 1: printf("How many items do you want to push: ");
            		scanf("%d",&num);
            		getchar();
            		for (i = 0; i < num; i++){
            			if (isFull(myStack)){
            				printf("Stack is already full, can't push again\n");
            				break;
						}
						printf("Enter item: ");
                    	gets(data);
                    	push(&myStack, data);       // function call
                    	printf("%s successfully pushed\n\n", data);
                    }
                    printStack(myStack);
                    break;
            case 2: printf("How many items do you want to pop: ");
            		scanf("%d",&num);
            		for (i = 0; i < num; i++){
            			if (isEmpty(myStack)){
            				printf("Stack is already empty, can't pop empty\n");
            				getchar();
            				getchar();
            				break;
						}
                    	data = pop(&myStack);   // function call
                    	printf("%s successfully popped\n", data);
                    }
                    puts("");
         		    printStack(myStack);
                    break;
            case 3: data = peek(&myStack);
                    printf("Top item is %s\n",data);
                    printStack(myStack);
                    break;
            case 4: if (isFull(myStack)) printf("Stack is full\n");
                    else printf("Stack is not full\n");
                    break;
            case 5: if (isEmpty(myStack)) printf("Stack is empty\n");
                    else printf("Stack is not empty\n");
                    break;
            case 6: printStack(myStack);
                    break;
            default:printf("Invalid Option.\n");
        }
        getchar();      // sucks up the enter key pressed during the previous scanf
        printf("Do you want to continue (y or n):");
        choice = getchar();         // gets a character from the keyboard
        system("cls");      // clears the screen.
    }   while(choice == 'y' || choice == 'Y');
    return 0;
}
