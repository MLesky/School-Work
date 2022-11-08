#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud{
	char fullname[255];
	float marks;
	char gender[10];
}student;

struct node{
	student stud;
	struct node *next;
};

int main(){
	struct node *list = NULL, *head = NULL, *next = NULL;
	int i, opt, num;
	char name[255], choice;
	
	while(1){
		puts("1. Insert at end");
		puts("2. Delete at end");
		puts("3. Display All");
		puts("4. Display Student");
		puts("5. Sum marks");
		printf("Select option: ");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: 
				printf("\nHow many students do you want to add: ");
				scanf("%d", &num);
				i = 0;
				if (list == NULL){
					list = (struct node *)malloc(sizeof(struct node));
					printf("\nEnter First students name, marks and gender: ");
					scanf("%s", list->stud.fullname);
					scanf("%f", &list->stud.marks);
					scanf("%s", list->stud.gender);
					getchar();
					list->next = NULL;
					i = 1;
				}
				
				for (; i < num; i++){
					head = list;
					next = list;
					while(next != NULL){
						next = next->next;
					}
					next = (struct node *)malloc(sizeof(struct node));
					printf("\nEnter students name, marks and gender: ");
					scanf("%s", next->stud.fullname);
					scanf("%f", &next->stud.marks);
					scanf("%s", next->stud.gender);
					next->next = NULL;
				}
				break;
			
			case 2:
				printf("\nHow many students do you want to delete: ");
				scanf("%d", &num);
				for (i = 0; i < num; i++){
					head = list;
					next = head;
					if (head == NULL){
						printf("List is Empty");
						break;
					}
					while(next->next != NULL){
						next = next->next;
					}
					next = NULL;
				}
				break;
			
			case 3:
				head = list;
				next = list;
				while(next != NULL){
					printf("\nName:\t%s\nGender:\t%s\nMark:\t%.2f\n\n",next->stud.fullname, next->stud.gender, next->stud.marks);
					next = next->next;
				}
				break;
				
			case 4:
				printf("Enter Name to display: ");
				scanf("%s", name);
				getchar();
				head = list;
				next = list;
				while(next != NULL){
					if(strcmp(next->stud.fullname, name)){
						printf("\nName:\t%s\nGender:\t%s\nMark:\t%.2f\n\n",next->stud.fullname, next->stud.gender, next->stud.marks);
						break;
					}
					next = next->next;
				}
				if (next == NULL){
					puts("Student not found");
				}
				break;
				
			case 5:
				head = list;
				next = head;
				float sum = 0;
				while(next != NULL){
					sum += next->stud.marks;		
				}
				printf("\nSum is: %.2f\n", sum);
				break;
		}
		
		getchar();
		printf("Do you want to continue (y or n): ");
		choice = getchar();
		if (choice != 'y' && choice != 'Y'){
			break;
		}
	};
	
	return 0;
}
