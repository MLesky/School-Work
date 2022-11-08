#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for holding a node's data'
struct node_structure{
    int id;
    char data[20];
    struct node_structure *next;	// pointer for next node
};

struct node_structure *init_list(struct node_structure *list, char data[20]){
    list = (struct node_structure *)malloc(sizeof(struct node_structure));	// creating new list
    // filling the new list
    strcpy(list->data, data);
    list->id = 1;
    list->next = NULL;
    printf("List Initialised\n");
    return list;
}
int list_len(struct node_structure *head){
    int i = 0;
    struct node_structure *node = head;
    while (node != NULL){
        // increments i until the node is NULL. i.e the end
        i++;
        node = node->next; // move to the next node
    }
    return i;
}
void print_list(struct node_structure *head){
    if (head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct node_structure *node = head;
    while (node != NULL){
        // print node data while node isn't NULL (hasn't reach the end)
        printf("No: %.2d\n", node->id);
        printf("data: %s\n", node->data);
        printf("Next\n");
        printf("    |\n");
        printf("    v\n");
        node = node->next;
    }
    printf(" NULL\t\t");
    printf("No of Nodes: %d\n\n",list_len(head));
}
void insert_head(struct node_structure *head, char data[20]){
    if (head == NULL){
        head = init_list(head, data);	// initialises list if it is empty
        return;
    }
    struct node_structure *node = (struct node_structure *)malloc(sizeof(struct node_structure));
    // copying data of head to node.
    strcpy(node->data, head->data);
    node->id = head->id;
    node->next = head->next;
    // copying passed data to head.
    strcpy(head->data, data);
    head->next = node;		// pointing head to node
    // head id equals length of list (number of nodes) during time of creation/insertion.
    // this makes each node have a unique id
    head->id = list_len(head);
    printf("Node (%s) added at head\n", data);
}
void insert_end(struct node_structure *head, char data[20]){
    if (head == NULL){
        head = init_list(head, data);	// initialise list if it is empty
        return;
    }
    struct node_structure *node = head;
    // looping to the last node
    while (node->next != NULL){
        node = node->next;
    }
    node->next = (struct node_structure *)malloc(sizeof(struct node_structure)); // allocating memory for the new node which is the next of the last node
	//copying data to the next of ther last node
    strcpy(node->next->data, data);
    node->next->next = NULL;
    node->next->id = list_len(head);
    printf("Node (%s) added at head\n", data);
}
void insert_index(struct node_structure *head, char data[20], int index){
    struct node_structure *newnode;
    int i = 0;
    if (index == 0){
        // inserts node at head if index is 0
        insert_head(head, data);
    }
    else if (index == list_len(head)){
        // insert node at end if index equals the length of the list
        insert_end(head, data);
    }
    else if (index > 0 && index < list_len(head)){
        // looping to the specified index
        struct node_structure *node = head;
        while (i < index - 1){
            node = node->next;	// going to the next node
            i++;
        }
        // creating the new node
        newnode = (struct node_structure *)malloc(sizeof(struct node_structure));
        strcpy(newnode->data, data);
        // inserting new node
        newnode->next = node->next;
        node->next = newnode;
        newnode->id = list_len(head);
        printf("Node (%s) added at [%d]\n", data, index);
    }
    else{
        printf("Error inserting %s node, index out of range\n", data);
    }
}
void insert_after_id(struct node_structure *head, char data[20], int after_id){
    struct node_structure *newnode;
    struct node_structure *node = head;
    newnode = (struct node_structure *)malloc(sizeof(struct node_structure));
    while (node->id != after_id){
        // searching for specified id
        if (node->next == NULL){
            printf("Node not found\n");
            return;
        }
        node = node->next;
    }
	// copying data to the newnode
    strcpy(newnode->data, data);
    // inserting newnode to list
    newnode->next = node->next;
    node->next = newnode;
    newnode->id = list_len(head);
    printf("Node (%s) added after (%d)\n", data, after_id);
}
void delete_head(struct node_structure *head){
    struct node_structure *oldhead = head;
    printf("Node (%s) deleted\n", head->data);
    *head = *head->next;	// setting new head to the next node of the old head
    oldhead = NULL;		// freeing the old head
}
void delete_end(struct node_structure *head){
    struct node_structure *node = head;
    // looping to node before the last node
    while(node->next->next != NULL){
        node = node->next;
    }
    printf("Node (%s) deleted\n", node->next->data);
    node->next = NULL; // setting last node to NULL;
}
void delete_id(struct node_structure *head, int id){
    struct node_structure *deletenode, *node = head;
    while (node->next->id != id){
        // searching for specified id
        if (node->next == NULL){
            printf("Node not found\n");
            return;
        }
        node = node->next;
    }
    deletenode = node->next;
    node->next = node->next->next;
    printf("Node (%s) deleted\n", deletenode->data);
    free(deletenode);	// freeing node
}
void delete_index(struct node_structure *head, int index){
    struct node_structure *node = head;
    int i = 0;
    while (node != NULL){
        if (i == index-1){
            struct node_structure *deletenode;
            deletenode = node->next;	// holds the node to be deleted
            node->next = node->next->next; // sets the leftnode to point to the next of the node
            printf("Node (%s) deleted\n", deletenode->data);
            free(deletenode);
        }
        node = node->next;
        i++;
    }
}
int search_id(struct node_structure *head, int id){
    struct node_structure *node = head;
    int i;
    while(node!= NULL){
        if (node->id == id){
            return i+1;
        }
        node = node->next;
        i++;
    }
    return -1;
}
void print_node_index(struct node_structure *head, int index){
    // looping to the specified index
    if (index >= 0 && index < list_len(head)){
        struct node_structure *node = head;
        int i = 0;
        while (i < index){
            node = node->next;	// going to the next node
            i++;
        }
        printf("No: %.2d\n", node->id);
        printf("data: %s\n\n", node->data);
    }
    else{
        printf("Index out of range\n");
    }
}
struct node_structure *sort_list(struct node_structure *head){
	struct node_structure *node, *current = head;
	char temp_data[20];
	int temp_id;
	// swapping nodes based on id
	// bubble sort
	while (current != NULL){
		node = current->next;
		while (node != NULL){
			if (current->id > node->id){
				// swapping data
				strcpy(temp_data, current->data);
				strcpy(current->data, node->data);
				strcpy(node->data, temp_data);
				// swapping ids
				temp_id = current->id;
				current->id  = node->id;
				node->id = temp_id;
			}
			node = node->next; // moving to next node
		}
		current = current->next;
	}
	puts("List Sorted");
	return head;
}
struct node_structure *reverse_list(struct node_structure *head){
	struct node_structure *newlist = (struct node_structure *)malloc(sizeof(struct node_structure));
	// initialising newlist head with list head
	strcpy(newlist->data, head->data);
	newlist->id = head->id;
	newlist->next = NULL;
	struct node_structure *node = head->next;
	// insert head nodes to the head of newlist while looping through head.
	while(node != NULL){
		insert_head(newlist, node->data);
		newlist->id = node->id;
		node = node->next;
	}
	puts("List Reversed");
	return newlist;
}

int main(){
    struct node_structure *myList = NULL;
    int option, id, index, pos;
    char choice, item[20];
    do{
        puts("*****LIST OPERATIONS*****");
        puts("     ===============\n");
        puts("1.  Create Linked list");
        puts("2.  Display link list\n");
        puts("**** INSERTING ****");
        puts("3.  Insert at head");
        puts("4.  Insert at end");
        puts("5.  Insert at index");
        puts("6.  Insert after an ID\n");
        puts("**** DELETING ****");
        puts("7.  Delete head");
        puts("8.  Delete end");
        puts("9. Delete index");
        puts("10. Delete ID\n");
        puts("11. Search node(ID)");
        puts("12. Display node(Index)");
        puts("13. Display node(ID)");
        puts("14. Sort List(ID)");
        puts("15. Reverse List\n");
        printf("Enter option: ");
        scanf("%d",&option);
        getchar();
        puts("\n");
        switch(option){
        case 1:
            puts("CREATING LINK LIST\n");
            printf("Enter Item to initialise list with: ");
            gets(item);
            myList = init_list(myList, item);	// function call
            print_list(myList);
            break;
        case 2:
            print_list(myList);	// function call
            break;
        case 3:
            printf("Enter node's data: ");
            gets(item);
            insert_head(myList, item);	// function call
            print_list(myList);
            break;
        case 4:
            printf("Enter node's data: ");
            gets(item);
            insert_end(myList, item);	// function call
            print_list(myList);
            break;
        case 5:
            printf("Enter node's data: ");
            gets(item);
            printf("Enter index: ");
            scanf("%d", &index);
            insert_index(myList, item, index);	// function call
            print_list(myList);
            break;
        case 6:
            printf("Enter node's data: ");
            gets(item);
            printf("Enter ID to insert after: ");
            scanf("%d", &id);
            insert_after_id(myList, item, id);	// function call
            print_list(myList);
            break;
        case 7:
            delete_head(myList);	// function call
            print_list(myList);
            break;
        case 8:
            delete_end(myList);		// function call
            print_list(myList);
            break;
        case 9:
            printf("Enter index: ");
            scanf("%d",&index);
            delete_index(myList, index);	// function call
            print_list(myList);
            break;
        case 10:
            printf("Enter ID: ");
            scanf("%d",&id);
            delete_id(myList, id);	// function call
            print_list(myList);
            break;
        case 11:
            printf("Enter node id: ");
            scanf("%d",&id);
            pos = search_id(myList, id);	// function call
            if (pos == -1)  puts("Node not found\n");
            else printf("Node found at pos [%d]\n", pos);
            break;
        case 12:
            printf("Enter Index: ");
            scanf("%d",&index);
            print_node_index(myList, index);	// function call
            print_list(myList);
            break;
        case 13:
            printf("Enter ID: ");
            scanf("%d",&id);
            pos = search_id(myList, id);	// function call
            print_node_index(myList, pos-1);	// function call
            print_list(myList);
            break;
        case 14:
        	myList = sort_list(myList);	// function call
        	print_list(myList);
            break;
        case 15:
            myList = reverse_list(myList);	// function call
            print_list(myList);
            break;
        default:
            puts("Invalid option\n");
        }

        getchar();
        printf("Do you want to continue(y or n): ");
        choice = getchar();
        system("cls");
    }
    while(choice == 'y' || choice == 'y');
    return 0;
}
