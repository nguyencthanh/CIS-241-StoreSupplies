#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"
void menu();

int main(){
	struct node *head;
	int user_input;
	printf("1: Create an empty list   2: Insert a product\n");
	printf("3: Delete a product       4: Delete the entire list\n");
	printf("5: Search a product       6: Display products in the list\n");
	printf("7: Purchase a product     8: Sell a product\n");
	printf("9: Save to File           0: Exit\n");
	scanf("%d", &user_input);
	char name[50];
	char unit[50];
	int price;
	int quantity;
	do{
	switch(user_input){
		case 0:
			exit(1);
			break;
		case 1:
			printf("Creating an Empty List\n");
			head = emptyList();
			menu();
			scanf("%d", &user_input);
			break;
		case 2:
			printf("Creating a Product\n");
			printf("Name:\n");
			scanf("%s", name);
			printf("Unit:\n");
			scanf("%s", unit); 
			printf("Price:\n");
			scanf("%d", &price); 
			printf("Quantity:\n");
			scanf("%d", &quantity); 
			insert(head, name, unit, price, quantity);
			menu();
			scanf("%d", &user_input);
			break;
		case 3:
			printf("Deleting a Product");
			printf("Name:\n");
			scanf("%s", name);
			delete(head, name);
			menu();
			scanf("%d", &user_input);
			break;
		case 4: 
			printf("Deleting Entire List\n");
			deleteAll(head);
			menu();
			scanf("%d", &user_input);
			break;
		case 5:
			printf("Searching For a Product\n");
			printf("Name:\n");
			scanf("%s", name);
			search(head, name);
			menu();
			scanf("%d", &user_input);
			break;
		case 6:
			printf("Displaying Entire List\n");
			displayList(head);
			menu();
			scanf("%d", &user_input);
			break;
		case 7: 
			printf("Buying a Product\n");
			printf("Name:\n");
			scanf("%s", name);
			purchase(head, name);
			menu();
			scanf("%d", &user_input);
			break;
		case 8:
			printf("Selling a Product\n");
			printf("Name:\n");
			scanf("%s", name);
			sell(head, name);
			menu();
			scanf("%d", &user_input);
			break;
		case 9: 
			printf("Saving all Products\n");
			save(head); 
			menu();
			scanf("%d", &user_input);
			break;
		default:
			menu();
			scanf("%d", &user_input);
		}
	} while(user_input != 0);
}

void menu(){
	printf("1: Create an empty list   2: Insert a product\n");
	printf("3: Delete a product       4: Delete the entire list\n");
	printf("5: Search a product       6: Display products in the list\n");
	printf("7: Purchase a product     8: Sell a product\n");
	printf("9: Save to File           0: Exit\n");
}
