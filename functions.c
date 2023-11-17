#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "project2.h"

//1
struct node *emptyList (){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	printf("Created EmptyList\n");
	return newNode;
}

//2
struct node *insert(struct node *head, char name[], char unit[], int price, int quantity){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return NULL;
	}

	
	if(price <= 0 || quantity <= 0){
		printf("Price or Quantity Contains a negative number or it is a 0\n");
		return NULL;
	}
		
	/*bool isdup = false;
	struct node *size = head;
	int length = 0;	
	while(size != NULL){
		length++;
		size = size -> next; 	
	}
	printf("%d", length);
	if(size != 0){
		char productName[50];
		strcpy(productName, name);
		struct node *temp = head;
		while(temp != NULL){
			if(strcmp(productName, temp -> name) == 0){
				printf("Already Exists");
				isdup = true;
				return NULL;
			}
		}
	}
	
	if(isdup = false){*/
	
	char prodName[50];
	strcpy(prodName, name);
	struct node *test =  head;
	
	while(test != NULL){
		if(strcmp(prodName, test -> name) == 0){
			printf("Name already exists\n");
			return NULL;
		}
		test = test -> next;
	}
	
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		strcpy(newNode -> name, name);
		strcpy(newNode -> unit, unit);
		newNode -> price = price;
		newNode -> quantity = quantity;
		newNode->next = head;
		while(head -> next != NULL){
			head = head -> next;
		}
		head -> next = newNode;
		head -> next -> next = NULL;
		printf("Product Created\n");
		return newNode;
	//}
}

//3
void delete(struct node *head, char name[]){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	char productName[50];
	strcpy(productName, name);
		
	struct node *temp = head;
	
	if(strcmp(productName, head -> name) == 0){
		head = head -> next;
		free(temp);
	}
	else{
		temp = head -> next;
		while(strcmp(productName, temp -> name) != 0){
			temp = temp -> next;
			head = head -> next;
		}
		if(strcmp(productName, temp -> name) == 0){
			head -> next = head -> next -> next;
			free(temp);
			return;
		}
	}
}

//4
void deleteAll(struct node *head){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}

	struct node *temp = head;
	struct node *prev;
	temp = temp -> next;
	while(temp != NULL){
		prev = temp;
		temp = temp -> next;
		free(prev);
	}
	head -> next = NULL;
	printf("Finished Deleting All\n");
}

//5
void search(struct node *head, char name[]){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	else{
		char productName[50];
		strcpy(productName, name);
		struct node *temp = head;
    		while (temp != NULL){
        		if (strcmp(productName, temp -> name) == 0){
            			printf("-------------Found-------------\n");
            			printf("Name: %s Unit: %s Price: %d Quantity: %d\n", temp -> name, temp -> unit, temp -> price, temp -> quantity); 
            			return;
            		}
        		temp = temp->next;
    		}
    	printf("Not Found\n");
    	}
}

//6
void displayList(struct node *head){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	else{
		head = head -> next;
		printf("---------------List---------------\n");
    		while (head != NULL) {
        		printf("Name: %s Unit: %s Price: %d Quantity: %d\n", head -> name, head -> unit, head -> price, head -> quantity);       	
        		head = head->next;
    		}
    	}
}

//7 
void purchase(struct node *head, char name[]){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	else{
		struct node *temp = head;
		while(temp != NULL){
			if(strcmp(temp -> name, name) == 0){
				int purchase = temp -> quantity;
				purchase = purchase + 1;
				temp -> quantity = purchase;
				printf("Purchased\n");
				return;
			}
			else{
			temp = temp -> next;
			}
		}
		printf("Product Not Found\n");
	}
}

//8
void sell(struct node *head, char name[]){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	else{
		struct node *temp = head;
		while(temp != NULL){
			if(strcmp(name, temp -> name) == 0){
				if(temp -> quantity == 1){
					delete(head, name);
					return;
				}
				else{
					int sell = temp -> quantity;
					sell = sell - 1;
					temp -> quantity = sell;
					printf("Sold\n");
					return;
				}
			}
			else{
			temp = temp -> next;
			}
		}
		printf("Product Not Found\n");
	}
}

//9
void save(struct node *head){
	if(head == NULL){
		printf("USE OPTION 1 FIRST\n");
		return;
	}
	else{
		FILE *fout;
		fout = fopen("saveproduct.txt", "w");
		if(fout == NULL){
			printf("File could not be opened!\n");
			exit(1);
		}
		head = head -> next;
		while(head != NULL){
			fprintf(fout, "Name: %s Unit: %s Price: %d Quantity: %d\n", head -> name, head -> unit, head -> price, head -> quantity);
			head = head -> next;
		}
		printf("Finished Saving\n");
		fclose(fout);
	}
}  
