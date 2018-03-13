#pragma once
#ifndef GRADEBOOK
#define GRADEBOOK

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class BOOK {
private:  struct Node {
	int scores[5];
	Node *next;
};
		//  pointers to handle traversion of nodes
		  Node *List;
		  Node *p;


public:
	BOOK();
	void display();			//  display the array
	void importDB(string);		//  import database
	void exportDB(string);		//  export database
	void pushDB(int []);

};
BOOK::BOOK() {
	List = NULL;

}

void BOOK::importDB(string filename) {
	fstream f;

	f.open(filename, ios::in);
	List = new Node;
	for (int i = 0; i < 5; i++) {
		f >> List->scores[i];
	}

	p = List;
	while (!f.eof()) {
		p->next = new Node;
		p = p->next;
		for (int i = 0; i < 5; i++) {
			f >> p->scores[i];
		}
	}
	p->next = NULL;
	f.close();		//  ALWAYS CLOSE
}

void BOOK::display() {
	p = List;
	while (p != NULL) {
		for (int i = 0; i < 5; i++) {
			cout << p->scores[i] << "\t";
		}
		cout << endl;
		p = p->next;
	}
}

void BOOK::pushDB(int arr[]) {
	Node  *n;
	n = new Node;
	for (int i = 0; i < 5; i++) {
		n->scores[i] = arr[i];
	}
	n->next = List;
	List = n;
}

void BOOK::exportDB(string filename) {
	fstream f;

	f.open(filename, ios::out);
	// List = new Node;
	// f << List->scores;
	p = List;
	while (p != NULL) {
		for (int i = 0; i < 5; i++) {
			f << p->scores[i] << ' ';
		}
		f << endl;
		p = p->next;
		if (p == NULL)
			break;
	}

	f.close();		//  ALWAYS CLOSE
}

#endif