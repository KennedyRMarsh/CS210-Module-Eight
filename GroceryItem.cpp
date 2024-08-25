/*
Kennedy Marsh CS 210 Project Three
August 18, 2024

The purpose of this program is to analyze a grocery list of items and list each item along with its frequency
The user can display the data in one of three ways:
	If the uses choses option 1
		The program will prompt for the user to chose an item, and then will list the individual item's frequency
	If the user choses option 2
		The program will list ALL items with corresponding frequencies
	If the user choses option 3
		The program will display a histogram of all items and frequencies
	If the user choses option 4
		The program will create a backup file with all items and frequencies and then will exit

*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>


using namespace std;

//Declare variables
void menuDisplay(); //display menu
int getOption(); //take user menu option (1-4)
int getOption(string); //take user string input (chosen item)


const int EXIT = 4; //set EXIT as a constant input (4)

int main() {

	ifstream inputFile; //set read file as inputFile
	string item; //store data for key
	map<string, int> total; //create map, set string as key, integer as amount of items in list (total)
	int option = 0; //initalize option as 0
	int frequency = 0; //initalize frequency to 0 (all items start with a frequency of 0)

	inputFile.open("inventory.txt"); //open grocery list file

	//print error if file cannot be opened
	if (inputFile.fail()) {
		cout << "Error! Could not open file." << endl;
		return 1; //indicate failed attempt
	}

	//read text file, list all items and record frequency
	while (inputFile >> item) { //read the file to the end of the data

		//Check if an item already exists
		if (total.count(item)) { //if item already exists
			total[item]++; //add +1 to current count
		}
		else { //if item not found, add item to list
			total.emplace(item, 1); //place 1 item into list
			//addItem++; //count total number of items added
		}
	}

	int count = 1; //initialize count/number of items to 1 (count begins at 1)

	//print list of items and count with key
	do { //loop printing menu and saving user input as option
		menuDisplay(); //print menu
		//getOption();
		option = getOption("Enter Option from 1 to " + to_string(EXIT) + ": "); //print options for user input and save input as 'option'

		//PROCESS USER INPUT AND CORRESPONDING ACTIONS
		//Search for individual item frequency
		if (option == 1) {
			cout << "Input item name!" << endl;
			cin >> item; //save user input as item (selected item)
			int frequency = total[item]; //record frequency of item under iteger frequency
			cout << "Frequency of " << item << ": " << frequency << endl; //Print item and corresponding frequency, validate user input

		
		}

		//List ALL item frequencies
		else if (option == 2) {
			for (auto groceries : total) { //loop until whole file is read
				cout << count << " " << groceries.first << " " << groceries.second << endl;
				count++; //add 1 to count each loop
			}
		}

		//Create frequency histogram
		else if (option == 3) {
			
			for (auto groceries : total) {
				cout << groceries.first << " "; //List all item names
				for (int i = 0; i < groceries.second; i++) //for each instance of an item, add one * behind listed item
					cout << "*";
				cout << endl;
			}
		}

		//Exit and create backup file
		else if (option == 4) {
			ofstream outFS; //assign outFS as file the text will be written on

			cout << "Backup file frequency.dat created!" << endl; //Validate user input
			cout << "Now exiting..." << endl;
			cout << "====================================================" << endl;

			outFS.open("frequency.dat"); //name created file frequency.dat
			while (inputFile >> item) { //read the file to the end of the data

				//Check if an item already exists
				if (total.count(item)) { //if item already exists
					total[item]++; //add +1 to current count
				}
				else { //if item not found, add item to list
					total.emplace(item, 1); //place 1 item into list
					//addItem++; //count total number of items added
				}
			}


			//Create an error statement if file is NOT opened
			if (!outFS.is_open()) { //if output file is not opened
				cout << "Error! Could not open file :" << endl; //print error message
				return 1; //return 1 to indicate error
			}

			//Record items and frequencies in output file
			for (auto groceries : total) {
				outFS << " " << groceries.first << " " << groceries.second << endl; //print items and frequencies in output WITHOUT count (item 1, 2 ,3 etc)
				count++; //add 1 frequency count per each loop
			}
			outFS.close(); //close output file frequenct.dat
		}
	} while (option != EXIT); //continue loop as long as user input (option) is NOT 4 (EXIT), if 4, exit

}



void menuDisplay() {
	/*
	Function Purpose: To print a menu displaying user input options
	*/
	cout << "=========================================" << endl;
	cout << "Press 1 to search for an item's frequency" << endl;
	cout << "Press 2 to print all item frequencies" << endl;
	cout << "Press 3 to create a histogram" << endl;
	cout << "Press "<< EXIT << " to exit and create a backup file" << endl; //Print given exit value in place of manually typing number
	cout << "==========================================" << endl;

}

int getOption() { //get user input for menu choice
	
	//create integer for option user chose
	int option = 0; //initialize user option to 0

	cout << "Please select an option "; //prompt user for an option
	cin >> option; //save user input as chosen option
	
	if (option > 4 || option < 1) { //Output error message if input value is not 1, 2, 3, or 4
		cout << "Error! Invalid Input. Select a number 1-4" << endl; //Tell user input is invalid, provide perameters
		
	}
	else {
		cout << "You selected: " << option << endl; //Validate user input
	}
	
	return option; //return input option


}

int getOption(string prompt) //get user input as a string (item name)
{
	//return 0;
	int option = 0; //initialize user option to 0

	cout << prompt; 
	cin >> option; //save user input as chosen option

	if (option > 4 || option < 1) { //Output error message if input value is not 1, 2, 3, or 4
		cout << "Error! Invalid Input. Select a number 1-4" << endl; //Tell user input is invalid, provide perameters
	}
	else {
		cout << "You selected: " << option << endl; //Validate user input
		cout << "==========================================" << endl;
	}

	return option;
}
