#ifndef PA1header
#define PA1header
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//definning struct for game implementation 
typedef struct Node
{
	string command;
	string ans;
	Node *next;
};

//defining struct for profile implementation
typedef struct uProfiles {
	string name;
	int points;
};


class Game {
private:
	//creating head and tail of the list
	Node *head, *tail;
	//creating integer to account for size
	int size;
	//private functions
	void populateList(string c, string n);
	void updateList();
public:
	//constructor
	Game();
	//destructor
	~Game();
	//delete given node based on command
	void delNode();
	//insert node at the end of the list
	void insertNode();
	//get answer for creating question
	string getNodeAns(int position);
	//get command for creating question
	string getNodeCom(int position);
	//play game function (return points)
	int playGame();
};

//functions for the profile struct
void readProfiles(uProfiles arr[], int arrSize);
void updateProfile(uProfiles arr[], int arrSize, int score, string name);
#endif
