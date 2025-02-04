// Working on a football assignment
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "playerType.h"

using namespace std;
const int SIZE =  10 ;

void readData (playerType list []);
int lookUpPlayer (playerType list []);

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
		cout << "Data found\n";
	}

	else
	{
		cout << "Data not found\n";	
	}
		
        break;
        
        case 2:
        cout << "Edit a player\n";
        break;
        
        case 3:
        cout << "Print Team Roster\n";
        break;
        
        case 4:
        cout << "Quitted\n";
      }
          
  }

  while ( input != 4);

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

int lookUpPlayer (playerType list [])
{
	string toSearch;
	int index = 0; 
	cout << "Search : ";
	getline (cin, toSearch );

	// Attempting to find the partial string in data.
	while (index < 0 )
	{
		// best case: string found
		if (list[index].name.find (toSearch) != string::npos )
		{
			return index;
		}
		index++;
	}

	// worst case: string not found
	return -1;
	
}
