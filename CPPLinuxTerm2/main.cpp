#include <iostream>
#include <string>
#include "optional.h"
using namespace std;

int main() {
	dir* in = new dir();

//user inputs
	string input, restGiven;
//prompt for user
	string start = "cameron~ $";
//print prompt and take user input
	cout << start << input << restGiven;

	while (true) {
		cin >> input;
		getline(cin, restGiven);

//go to this directory
		if (input == "cd") {
			in->chDir();
		}

//show path function call
		else if (input == "ls") {
			in->showPath();
		}

//make dir function call
		else if (input == "mkdir") {
			in->mkdir(in, restGiven);
		}

//make file function call
		else if (input == "touch") {
			in->mkfile();
		}

//exit program
		else if (input == "exit") {
			exit(0);
		}

//anything else, restart
		else {
			cout << "Not an option" << endl;
		}

		cout << start;
	}

cout << " " << endl;
system("pause");

}