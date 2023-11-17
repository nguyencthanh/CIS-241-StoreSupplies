#include <stdio.h>
#include <stdlib.h>

#ifndef project2_H
#define project2_H

struct node{
	char name[50];
	char unit[50];
	int price;
	int quantity;
	struct node *next;
};

struct node *emptyList(); //Creates an Empty List 

struct node *insert(struct node *head, char name[], char unit[], int price, int quantity); // Add a product

void delete(struct node *head, char name[]); //delete a product

void deleteAll(struct node *head); //delete all products

void search(struct node *head, char name[]); //search for an wanted product

void displayList(struct node *head); //display all current products 

void purchase(struct node *head, char name[]); //increase quantity of product by one

void sell(struct node *head, char name[]); //decrease quantity of product by one

void save(struct node *head); //save all products to a file

#endif
