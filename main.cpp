// Working on a football assignment


#include <iostream>
#include <fstream>
#include "playerType.h"

using namespace std;
const int SIZE =  10 ;

void readData (playerType list []);

int main (){

  int input;
	playerType teamPlayers[10];

	// Read players data from the txt file
	readData (teamPlayers);

	// Start displaying menu
  do {

    cout << "********************************************\n";
    cout << "Assignment A5 : Structs                    *\n";
    cout << "*                                          *\n";
    cout << "* <1> Look Up a Player                     *\n";
    cout << "* <2> Edit a Player                        *\n";
    cout << "* <3> Print Team Roster                    *\n";
    cout << "* <4> To Quit                              *\n";
    cout << "********************************************\n";
    cout << "* Choice (1-4) : ";
    cin >> input;

    switch (input)
      {
        case 1:
        // Look up for player
        cout << "Look up a player\n";
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
	int index = 0;
	while (index < SIZE && getline (inData, list[i].name)
		{
			getline (inData, list[i].position);
			inData >> list[index].numTouchDowns;
			inData >> list[index].numCatches;
			inData >> list[index].numPassing;
			inData >> list[index].numReceiving;
			inData >> list[index].numRushing;

			cout << list[index].name << endl; 

		}
}
