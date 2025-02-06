// Working on a football assignment
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>        // To clear the screen
#include <algorithm>      // To make strings uppercase version
#include <iomanip>        // formatting output
#include "playerType.h"

using namespace std;
const int SIZE =  10 ;

void readFile (playerType list []);
int lookUpPlayer (const playerType list []);
void editPlayer (playerType list []);
void printTeam (const playerType list []);
void printPlayer (const string name, const char pos[], const int TDs, const int catches, const int passYds, const int recvYads, const int rushYds);
void writeFile (playerType list []);

int main (){
  	char input;
	playerType teamPlayers[10];
	int foundPosition;
	
	// Read players data from the txt file
	readFile (teamPlayers);

	// Start displaying menu
  do {
    system("clear");
	  
    cout << "\n********************************************\n";
    cout << "Assignment A5 : Structs                    *\n";
    cout << "*                                          *\n";
    cout << "* <1> Look Up a Player                     *\n";
    cout << "* <2> Edit a Player                        *\n";
    cout << "* <3> Print Team Roster                    *\n";
    cout << "* <4> To Quit                              *\n";
    cout << "********************************************\n";
    cout << "* Choice (1-4) : ";
    cin.get (input);
    cin.ignore ();
	  
	// handle input validation
	  while (input < 49 || input > 52 )
		  {
			  cout << input << " is an invalid choice. Only enter Choice (1-4) : ";
			  cin.get (input);
			  cin.ignore ();
		  }
	  
    switch (input)
      {
        case '1':
        // Look up for player
	foundPosition = lookUpPlayer (teamPlayers);
        if (foundPosition != -1)
	{
		cout << "***********************\n";
		cout << "Data found\n";
		cout << "***********************\n";
	}

	else
	{
		cout << "***********************\n";
		cout << "Data not found\n";	
		cout << "***********************\n";
	}
		
        break;
        
        case '2':
	// Edit a player
		editPlayer (teamPlayers);
        break;
        
        case '3':
        printTeam (teamPlayers);
        break;
        
        case '4':
        cout << "Quitted\n";
      }

	cout << "\nPress any key to continue\n";
	cin.ignore();
  }

  	while ( input != 4 );

	// write the data on the file
	writeFile (teamPlayers);
	return 0;
}


void readFile (playerType list[])
{
	ifstream inData;
	
	inData.open ("input.txt");
	int i = 0;
	while (i < SIZE && getline (inData, list[i].name))
		{
			inData.get(list[i].position, 3);
			inData >> list[i].numTouchDowns;
			inData >> list[i].numCatches;
			inData >> list[i].numPassing;
			inData >> list[i].numReceiving;
			inData >> list[i].numRushing;
			inData.ignore();         // Remove newline left in buffer for next getline

			i++;
		}
	
	inData.close();
	
	return;
}

int lookUpPlayer (const playerType list [])
{
	string toSearch;
	int index = 0; 
	string uppercasePlayers;          // hold temporary strings of uppercase data names
	string uppercaseToSearch;         // hold temporary strings of uppercase search name

	
	cout << "Search : ";
	getline (cin, toSearch );

	// Attempting to find the partial string in data.
	while (index < SIZE )
	{
		// make a copy of strings name and to search
		uppercasePlayers = list[index].name;
		uppercaseToSearch = toSearch;
		
		// convert both strings to uppercase.
		transform(uppercasePlayers.begin(), uppercasePlayers.end(), uppercasePlayers.begin(), ::toupper);
    		transform(uppercaseToSearch.begin(), uppercaseToSearch.end(), uppercaseToSearch.begin(), ::toupper);
		
		// best case: string found
		if (uppercasePlayers.find (uppercaseToSearch) != string::npos )
		{
			return index;
		}
		
		index++;
	}

	// worst case: string not found
	return -1;
}

void editPlayer (playerType list [])
{
	int index;     // index returned if search function found data
	int choice;    // choice for editplayer menu
	// Call look up function to get the index
	index = lookUpPlayer (list);

	if (index != -1)
	{
		cout << "*****************************************\n";
		cout << "* Edit a Player                         *\n";
		cout << "*****************************************" << "CURRENT VALUES\n";
		cout << "* <1> Edit Name                         : " << list[index].name << endl;
		cout << "* <2> Edit Position                     : " << list[index].position << endl;
		cout << "* <3> Edit Number of Touchdowns         : " << list[index].numTouchDowns << endl;
		cout << "* <4> Edit Number of Catches            : " << list[index].numCatches << endl;
		cout << "* <5> Edit Number of Passing Yards      : " << list[index].numPassing << endl;
		cout << "* <6> Edit Number of Receiving Yards    : " << list[index].numReceiving << endl;
		cout << "* <7> Edit Number of Rushing Yards      : " << list[index].numRushing << endl;
		cout << "* <8> Back To Main Menu                 *\n";
		cout << "*****************************************\n";
		cout << "* Choice (1-8) : ";
		cin >> choice;
		cin.ignore();

		// handle input validation
	 	 while (choice < 1 || choice > 8)
		  {
			  cout << "Only enter Choice (1-8) : ";
			  cin >> choice;
    			  cin.ignore();
		  }
		
		switch (choice)
		{
		case 1:
		cout << "Edit *New* Name : ";
		getline (cin, list[index].name );
		break;

		case 2:
		cout << "Edit *New* Position : ";
		cin.get( list[index].position , 3 );
		break;

		case 3:
		cout << "Edit *New* Number of Touchdowns : ";
		cin >> list[index].numTouchDowns;
		break;
		
		case 4:
		cout << "Edit *New* Number of Catches  : ";
		cin >> list[index].numCatches;
		break;

		case 5:
		cout << "Edit *New* Number of Passing Yards : ";
		cin >> list[index].numPassing;
		break;

		case 6:
		cout << "Edit *New* Number of Receiving Yards : ";
		cin >> list[index].numReceiving;
		break;

		case 7:
		cout << "Edit *New* Number of Rushing Yards : ";
		cin >> list[index].numRushing ;
		break;
		
		case 8:
			return;
		break;	
		}
	
	}
	return;
}


void printTeam (const playerType list [])
{
	// Header
	cout << "Team consists of following players\n";
	cout << setw (20) << left << "Name";
	cout << setw (5) << left << "Pos";
	cout << setw (5) << left << "TDs";
	cout << setw (7) << left << "Catches";
	cout << setw (7) << right << "Pass";
	cout << setw (7) << right << "Recv";
	cout << setw (8) << right << "Rush\n";
	cout << setw (44) << right << "Yds";
	cout << setw (7) << right << "Yds";
	cout << setw (8) << right << "Yds";

	// Call print Player function to print it one by one
	for (int i= 0 ; i < SIZE ; i++)
		{
			cout << "\n-----------------------------------------------------------\n";
			printPlayer (list[i].name, list[i].position, list[i].numTouchDowns, list [i].numCatches, list[i]. numPassing,
				list[i].numReceiving, list[i].numRushing);
		}
	cout << "\nPress any key to continue....\n";
	cin.ignore();
	return;
}

void printPlayer (const string name, const char pos[], const int TDs, const int catches, const int passYds, const int recvYads, const int rushYds)
{
	cout << setw (20) << left << name;
	cout << setw (5) << right << pos;
	cout << setw (5) << right << TDs;
	cout << setw (7) << right << catches;
	cout << setw(7) << right << passYds;
	cout << setw(7) << right << recvYads;
	cout << setw(7) << right << rushYds;
}

void writeFile (playerType list [])
{
	ofstream outData;
	outData.open ("output.txt");

	for (int i = 0; i < SIZE ; i++)
		{
			outData << list[i].name << endl;
			outData << list[i].position << endl;
			outData << list[i].numTouchDowns << endl;
			outData << list[i].numCatches << endl;
			outData << list[i].numPassing << endl;
			outData << list[i].numReceiving << endl;
			outData << list[i].numRushing << endl;
		}
	// close the file
	outData.close();
}
