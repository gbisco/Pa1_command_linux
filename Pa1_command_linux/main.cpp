// Gabriel Bisco Reinato
// Cpts223
// PA1

/* ADVANTAGES / DISADVANTAGES LINKED LIST:
1) Using a linked list allows the data to be dynamically allocated without overloading.
2) Linked lists can be "messed up" by accidentally breaking a link in the chain.
*/

/* ADVANTAGES / DISADVANTAGES ARRAY:
1) Using an array of classes allows us to have more control over changes in the array by using private variables and functions.
2) Using an array of classes might require more work and is probably less efficient.
*/

#include "PA1header.h"
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

int main(void) {
	srand(time(0));  // Seed the random number generator

	// Creating integer for menu loop
	int opt = 0;

	// Creating score int for record
	int score = 0;

	// Creating string for name record
	string name;

	// Creating class object
	Game game;

	// Creating array of profiles
	uProfiles arr[100];

	// Reading profiles from file
	readProfiles(arr, 100);

	// System command for clearing check of constructor (Windows-specific)
	// system("pause");  // Avoid using system("pause"); if possible
	// system("cls");    // Avoid using system("cls"); if possible

	// Menu loop
	while (opt != 6) {
		cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit" << endl;
		cin >> opt;

		switch (opt) {
		case 1:
			// Game Rules
			cout << "Match the right answer to the Linux command!\nFor every correct answer you will be awarded 1 point.\nEvery answer you miss you will lose a point.\nHave Fun!" << endl;
			// system("pause");
			// system("cls");
			break;

		case 2:
			// Play Game
			cout << "Welcome! Have fun learning Linux commands!" << endl;
			score += game.playGame();  // Add score from playing game
			cout << "Name: ";
			cin >> name;
			// system("cls");
			break;

		case 3:
			// Load Previous Game
			cout << "Name: " << name << endl;
			cout << "Points: " << score << endl;
			// system("pause");
			// system("cls");
			break;

		case 4:
			// Add Command
			game.insertNode();
			// system("pause");
			// system("cls");
			break;

		case 5:
			// Remove Command
			game.delNode();
			// system("pause");
			// system("cls");
			break;

		case 6:
			// Exit and update profiles
			cout << "Updating list..." << endl;
			// Destructor is automatically called, no need to manually invoke it
			// game.~Game();  // This is unnecessary and should be removed
			cout << "Updating profiles..." << endl;
			updateProfile(arr, 100, score, name);
			cout << "Bye!" << endl;
			break;
		}
	}

	return 0;
}