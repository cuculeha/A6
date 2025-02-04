#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

using namespace std;

struct playerType
{
	string name;
	char position[3];
	int numTouchDowns;
	int numCatches;
	int numPassing; 
	int numReceiving;
	int numRushing;
	
};

#endif
