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
#include <string.h>
#include <string>
#include <fstream>
using namespace std;


// DEFINITIONS
string EnterGame(string gameName, string choice);
void PrintMenu();

// DRIVER
int main(){
		ofstream outfile;// creates an outfile.txt
	ifstream platfile("platinumgames.txt");// open file and check for fail, at end of statement you close the file
	if(platfile.fail()){//check for failure opening the file
		cout << "File not found";
		exit(1);
		platfile.close();
	}
	PrintMenu();
	
	string choice;// variable to get input about choice
	cout << "Do you want to enter a game you want to platinum?\n\nType 'yes' or 'no' ";
	cin >> choice;
	cout << endl; 
	
	int times = 0;
	
	if(choice != "no")
	{
		cout << "How many games would you like to add to the list? " << endl;
		cout << "Number of Games: ";
		cin >> times;
	}
	else
		return 0;
	
	string gameName;
	string game;
	
	// var for adding game name		  ios::app adds your entry instead of overwriting
	outfile.open("platinumgames.txt", ios::app);
	for(int i = times; i > 0; i--){
		// game var set equal to function call 
		game = EnterGame(gameName, choice);
		// call game var so your entry is written in the .txt file
		outfile << "\n-" << game;
	}
	
	return 0;
}

	// DECLARATIONS
	string EnterGame(string gameName, string choice){
	if(choice == "yes"){
		cout << "Enter the game you want to add to the list: ";
		string gameName;
		cin.ignore(); // ignores the choice so you can actually enter the 
			      // gameName var that you want
		getline(cin,gameName);
		return gameName;
	}
	else if(choice == "no"){
		cout << "Whyyyyyyyyyyyy? ";
	}
	return gameName;
}

void PrintMenu(){
	cout << "1. Enter Game name" << endl;
	cout << "2. Veiw Game List" << endl;
	cout << "'Exit' To End the Program" << endl;	
}
