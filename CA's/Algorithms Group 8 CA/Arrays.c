#include <stdio.h>
#include <stdlib.h>
// Functions
void swap(int *num1, int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void printArray(int array[], int size){
	if (size == 0){
		printf("Empty Array\n");
		return;
	}
	int i;
	printf("|");
	for (i = 0; i < size; i++){
		printf(" %d |", array[i]);	// printing array elements
	}
	printf("\tSize:\t%d\n",size);
}
void insertFront(int *array, int *size, int element){
	int i;
	if (*size == 0){	// assigning element to array if it is empty
		*array = element;
		(*size)++;
		return;
	}
	(*size)++;		// incrementing the size by one
	array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating increased space to the array
	for (i = (*size) - 1; i > 0; i--){
	 	array[i] = array[i-1]; 			// shifting elements
	}
	array[0] = element;
}
void insertEnd(int *array, int *size, int element){
	if (*size == 0){
		*array = element;
		(*size)++;
		return;
	}
	(*size)++;
	array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating increased space to the array
	if (*size > 0){
		array[(*size)-1] = element;
	}
	else	array[0] = element;
}
void insertPos(int *array, int *size, int index, int element){
	int i;
	if (index < 0 || index > *size){	// can't insert if the index passed in is negative or greater than size
		printf("Index out of range\n");
		return;
	}
	(*size)++;
	array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating increased space to the array
	if(*size == 1){
		array[0] = element;
		return;
	}
	for (i = (*size)-1; i >= 0; i--){
		if (i >= index){				// shifting elements until the index is reached
	 		array[i+1] = array[i];
		}
		if (i == index){		// inserts element when index is reached
			array[i] = element;
		}
	}
}
void deleteFront(int *array, int *size){
	int i;
	if(*size == 0){
		printf("Array is Empty\n");
		return;
	}
	(*size)--;	// decrementing the size
	for (i = 0; i < *size; i++){
		array[i] = array[i+1];		// shifting elements to the left
	}
	if (*size == 0)	free(array);	// free memory if array is empty
	else array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating reduced space to the array
}
void deleteEnd(int *array, int *size){
	if(*size == 0){
		printf("Array is Empty\n");
		return;
	}
	(*size)--;
	if (*size == 0)	free(array);	// free memory if array is empty
	else array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating reduced space to the array
}
void deletePos(int *array, int *size, int index){
	int i;
	if(*size == 0){
		printf("Array is Empty\n");
		return;
	}
	if (index < 0 || index > (*size)-1){	// can't insert if the index passed in is negative or greater than size-1
		printf("Index out of range\n");
		return;
	}
	(*size)--;
	for (i = index; i < (*size); i++){
			array[i] = array[i+1];		// shifting elements to the left once the index is reached
	}
	if (*size == 0)	free(array);	// free memory if array is empty
	else array = (int *)realloc(array, sizeof(int) * (*size));	// reallocating reduced space to the array
}
int searchElem(int array[], int size, int element){
	int i;
	for (i = 0; i < size; i++){
		if (array[i] == element)	return i+1;
	}
	return -1;
}
void sortArray(int *array, int size, int order){
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size-1; j++){
			if (order == 0){	// swap in accending order if order is 0
				if (array[j] > array[j+1])  swap(&array[j], &array[j+1]);
			}	// else swap in descending order.
			else if (array[j] < array[j+1])	swap(&array[j], &array[j+1]);
		}
	}
}
int *reverseArray(int *array, int size){
	int i;
	// creating a new dynamic array and allocatng space to it
	int *new_array = (int *)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++){
		// copying elements to new array from the last to first
		new_array[i] = array[size-i-1];
	}
	return new_array;
}

int main(){
    int size, i, option, data, index;
    char choice;
    int *myArray;   // creating a dynamic array using pointer notation
    printf("How many items do you want to initialise your array with: ");
    scanf("%d",&size);
//  allocating memory to myArray.
    myArray = (int *)malloc(sizeof(int) * size);
    printf("Enter array elements:\n");
    for (i = 0; i<size; i++){
        printf("Elem %d:\t",i+1);
        scanf("%d",&myArray[i]);	// getting each element of the array
    }
    printf("Array successfully created: ");
    printArray(myArray, size);		// function call to print array
    do{		// array operations
    printf("\nOPERATIONS\n============\n\n");
    printf("1. Display array\n\n");
    printf("INSERTION OPERATIONS\n");
    printf("2. Insert element at beginning\n");
    printf("3. Insert element at end\n");
    printf("4. Insert element at given index\n\n");
    printf("DELETION OPERATIONS\n");
    printf("5. Delete first element\n");
    printf("6. Delete last element\n");
    printf("7. Delete element at given index\n\n");
    printf("8. Search an element\n");
    printf("9. Sort array\n");
    printf("10.Reverse array\n\n");
    printf("Select an option: ");
    scanf("%d", &option);
    switch(option){
    	case 1: printf("Array: ");
    			printArray(myArray, size);
    			break;
    	case 2:	printf("Enter data to be inserted: ");
    			scanf("%d", &data);
    			insertFront(myArray, &size, data);	// insertFront function call
    			printf("Array: ");
    			printArray(myArray, size);
    			break;
		case 3:	printf("Enter data to be inserted: ");
    			scanf("%d", &data);
    			insertEnd(myArray, &size, data);	// insertEnd function call
    			printf("Array: ");
    			printArray(myArray, size);
    			break;
		case 4:	printf("Enter data to be inserted: ");
    			scanf("%d", &data);
    			printf("Enter index (should be from 0 to size): ");	// insertPos function call
					scanf("%d", &index);
					insertPos(myArray, &size, index, data);
					printf("Array: ");
    			printArray(myArray, size);
    			break;
		case 5:	deleteFront(myArray, &size);	// Function call
				printf("Array: ");
    			printArray(myArray, size);
				break;
		case 6: deleteEnd(myArray, &size);	// Function call
				printf("Array: ");
    			printArray(myArray, size);
				break;
		case 7: printf("Enter index: ");
						scanf("%d", &index);
						deletePos(myArray, &size, index);	// Function Call
						printf("Array: ");
    				printArray(myArray, size);
    				break;
		case 8: printf("Enter element: ");
						scanf("%d",&data);
						int pos = searchElem(myArray, size, data);	// Function Call
						if (pos == -1)	printf("Element is not found\n");
						else printf("Element found at position %d\n", pos);
						printf("Array: ");
    				printArray(myArray, size);
    				break;
		case 9: printf("Enter order (0 for ascend and 1 for descend): ");
						scanf("%d", &data);
						sortArray(myArray, size, data);
						printf("Array sorted: ");
						printArray(myArray, size);
						break;
		case 10:myArray = reverseArray(myArray, size);
						printf("Array: ");
    				printArray(myArray, size);
						break;
		default:printf("Invalid Option\n");
	}
	getchar();
	printf("\nDo you want to continue? (y or n): ");
	choice = getchar();		// getting user's choice to continue
	system("cls");		// clears the screen . use sytem("clear"), sytem("cls) or clrscr()
    } while(choice == 'y' || choice == 'Y');	// loop continues if the choice is 'y' (yes)
    return 0;
}
