/*
CPSC254
Created by:  Brian Bui
Created on:  12 March 2018
Last edited:  12 March 2018
This program will:
	Handle the calling of functions in the attached header.

*/

#include "Gradebook.h"
#include<iostream>
#include<string>

using namespace std;

int main() {

	BOOK g;
	int a[5] = { 10, 20, 30, 40, 50 };
	
	g.importDB("gradebook.txt");
	//  g.pushDB(a);
	g.display();
	g.exportDB("gradebook.txt");

	cout << "Hello world!" << endl;

	system("pause");
	return 0;
}