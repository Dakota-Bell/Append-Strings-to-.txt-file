/*
Author: Dakota B
Program: Program will ask you if you would like to enter in a game you have platinumed
		 if not then the user will be presented a list of options to choose from and input choice.
		 1. See list of platinumed games
		 2. Add games to wishlist (platinum-style)
		 3. See games on Platinum wishlist (trying to use arrays)
		 4. Exit
*/

// Include f stream so you can append to a file with a list of games I've platinumed or plan to platinum
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// DEFINITIONS
void EnterGame(string gameName, string choice);

// DRIVER
int main(){
	// creates an outfile.txt
	ofstream outfile;
	// open file and check for fail, at end of statement you close the file
	ifstream platfile("platinumgames.txt");
	//check for failure opening the file
	if(platfile.fail()){
		cout << "File not found";
		exit(1);
		platfile.close();
	}
	
	// variable to get input about choice
	string choice;
	cout << "Do you want to enter a game you want to platinum?\n\nType 'yes' or 'no' ";
	cin >> choice;
	cout << endl; 
	
	// var for adding game name
	outfile.open("platinumgames.txt", ios::app);
	string gameName;
	EnterGame(gameName, choice);
	outfile << "\n-" << gameName;
	
	return 0;
}

// DECLARATIONS
void EnterGame(string gameName, string choice){
	if(choice == "yes"){
		cout << "Enter the game you want to add to the list: ";
		string gameName;
		cin.ignore(); // ignores the choice so you can actually enter the 
			      // gameName var that you want
		getline(cin, gameName);
	}
	else if(choice == "no"){
		cout << "Whyyyyyyyyyyyy? ";
	}
}
