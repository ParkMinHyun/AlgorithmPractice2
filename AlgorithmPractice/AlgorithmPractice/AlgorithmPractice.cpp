#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
};

Node *head, *tail;

void init() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}

Node* makeNode(int data) {
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

void push_back(int data) {
	Node *newNode = makeNode(data);

	/*순서 완전 중요*/
	tail->prev->next = newNode;
	newNode->prev = tail->prev;

	tail->prev = newNode;
	newNode->next = tail;
}

void print(Node *n)
{
	if (n == tail) {
		cout << endl;
		return;
	}

	cout << n->data << ' ';
	print(n->next);
}

void remove_data(int data) {
	Node *p = head->next;

	while (p != tail) {
		if (p->data == data) {
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free(p);
			return;
		}
		p = p->next;
	}
	cout << "지울게 없는데?" << '\n';
}
int main()
{
	init();
	push_back(3);
	push_back(4);
	push_back(5);
	push_back(6);
	push_back(7);
	print(head->next);
	remove_data(6);
	print(head->next);

}