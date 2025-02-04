// Working on a football assignment
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>        // To clear the screen
#include <algorithm>      // To make strings uppercase version
#include "playerType.h"

using namespace std;
const int SIZE =  10 ;

void readData (playerType list []);
int lookUpPlayer (const playerType list []);
void editPlayer (playerType list []);

int main (){
  	int input;
	playerType teamPlayers[10];
	int foundPosition;
	
	// Read players data from the txt file
	readData (teamPlayers);

	// Start displaying menu
  do {
	  
    cout << "\n********************************************\n";
    cout << "Assignment A5 : Structs                    *\n";
    cout << "*                                          *\n";
    cout << "* <1> Look Up a Player                     *\n";
    cout << "* <2> Edit a Player                        *\n";
    cout << "* <3> Print Team Roster                    *\n";
    cout << "* <4> To Quit                              *\n";
    cout << "********************************************\n";
    cout << "* Choice (1-4) : ";
    cin >> input;
    cin.ignore();

	  
    switch (input)
      {
        case 1:
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
        
        case 2:
	// Edit a player
		editPlayer (teamPlayers);
        break;
        
        case 3:
        cout << "Print Team Roster\n";
        break;
        
        case 4:
        cout << "Quitted\n";
      }
          
  }

  while ( input != 4 );

}


void readData (playerType list[])
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
	int index;

	// Call look up function to get the index
	index = lookUpPlayer (teamPlayers);

	if (index != - 1);
	{
		cout << list[index].name << endl;	
		cout << list[index].position << endl;	
		cout << list[index].numTouchDowns << endl;	
		cout << list[index].numCatches << endl;	
		cout << list[index].numPassing << endl;	
		cout << list[index].numReceiving << endl;
		cout << list[index].numRushing << endl;
	
	}
	
}
