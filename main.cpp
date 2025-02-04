// Working on a football assignment


#include <iostream>

using namespace std;

int main (){
  do {
    int input;
    
    cout << "********************************************\n";
    cout << "Assignment A5 : Structs                    *\n"
    cout << "*                                          *\n;
    cout << "* <1> Look Up a Player                     *\n;
    cout << "* <2> Edit a Player                        *\n;
    cout << "* <3> Print Team Roster                    *\n;
    cout << "* <4> To Quit                              *\n;
    cout << "********************************************\n";
    cout << "* Choice (1-4) : ";
    cin >> input;

    switch (input)
      {
        case 1;
        // Look up for player
        cout << "Look up a player\n";
        break;
        
        case 2;
        cout << "Edit a player\n";
        break;
        
        case 3;
        cout << "Print Team Roster\n";
        break;
        
        case 4;
        cout << "Quitted\n";
      }
          
  }

  while ( input != 4);

}
