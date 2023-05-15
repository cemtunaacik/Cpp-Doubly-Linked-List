#include<iostream>
using namespace std;

struct node{
	node *next;
	node *prev;
	int data;
};

node *head = NULL;

void insert(){
	node *temp = new node;
	int input;
	cout << "\nEnter the value you want to insert -> ";
	cin >> input;
	if (head == NULL){
		temp -> prev = NULL;
		temp -> next = NULL;
		temp -> data = input;
		head = temp;
		cout << endl << head -> data << " has been added to the list\n";
	}
	else{
		node *traveler = head;
		while (traveler -> next != NULL){
			traveler = traveler -> next;
		}
		temp -> prev = traveler;
		temp -> next = NULL;
		temp -> data = input;
		traveler -> next = temp;
		cout << endl << temp -> data << " has been added to the list\n";
	}
}
void remove(){
	node *temp = head;
	if (head == NULL)
		cout <<"\nList is empty\n";
	else if (head -> next == NULL){
		cout << endl << head -> data << " has been deleted\n";
		delete head;
		head = NULL;
	}
	else{
		while (temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> prev -> next = NULL;
		cout << endl << temp -> data << " has been deleted\n";
		delete temp;
	}	
}
void print(){
	if (head != NULL){
		int i = 1;
		node *traveler = head;
		while (traveler != NULL){
			cout << endl << i << ". Element -> " << traveler -> data;
			traveler = traveler -> next;
			i++;
		}
		cout << endl;
	}
	else
		cout << "\nList is empty\n";
}
void find(){
	bool isFound = false;
	int input, i = 1;
	cout << "\nEnter the element you want to find -> ";
	cin >> input;
	node *traveler = head;
	while (traveler != NULL){
		if (traveler -> data == input){
			isFound = true;
			cout << endl << input << " found at " << i << ". node\n";
			break;
		}
		else{
			traveler = traveler -> next;
			i++;
		}
	}
	if (isFound == false)
		cout << endl << input << " not found\n";
}

int main(){
	int menu = 1;
	while (menu){
		cout << "\n0 - Quit\n1 - Insert\n2 - Remove\n3 - Print\n4 - Find\nYour input -> ";
		cin >> menu;
		switch (menu){
			case 0:
				cout << "\nGood bye\n";
				break;
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3:
				print();
				break;
			case 4:
				find();
				break;
			default:
				cout << "\nPlease enter a valid input\n";
		}
	}
}

