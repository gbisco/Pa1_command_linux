#include "PA1header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

void Game::populateList(string c, string n) {
    Node* temp = new Node;
    temp->command = c;
    temp->ans = n;
    temp->next = nullptr;  // Ensure the new node's next is null.

    // Checking empty list case
    if (head == nullptr) {
        head = temp;
        tail = temp;
        cout << "Adding command: " << c << endl;
    }
    else {
        tail->next = temp;
        tail = temp;
        cout << "Adding command: " << c << endl;
    }
}

Game::Game() {
    head = nullptr;
    tail = nullptr;
    size = 0;
    cout << "Constructing Game object..." << endl;

    // String to be passed to populate
    string c, n;
    ifstream ifile("commands.csv");

    // Read the file
    while (getline(ifile, c, ',') && getline(ifile, n)) {
        populateList(c, n);
        size++;
    }
    ifile.close();
}

void Game::delNode() {
    cout << "Warning: Nodes should be deleted before exiting the program!" << endl;
    // Determining command to be deleted
    string delCommand;
    cout << "Command to be deleted: ";
    cin >> delCommand;

    // Traversing list to find and delete node
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (delCommand == temp->command) {
            if (prev != nullptr) {
                prev->next = temp->next;
                if (temp == tail) tail = prev;
            }
            else {
                head = temp->next;
                if (head == nullptr) tail = nullptr;
            }
            delete temp;
            cout << delCommand << " deleted successfully..." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Node not found..." << endl;
}

void Game::insertNode() {
    cout << "Nodes should be added before exiting the program!" << endl;
    // Defining Node to be inserted into the list
    Node* newNode = new Node;

    cout << "Command name: ";
    cin >> newNode->command;
    cout << "\nDescription: ";
    cin >> newNode->ans;
    cout << endl;

    // Appending node
    tail->next = newNode;
    tail = newNode;  // Update tail to point to the new node
    cout << "Node added..." << endl;
}

string Game::getNodeAns(int position) {
    Node* qNode = head;
    for (int count = 0; count < position; count++) {
        qNode = qNode->next;
    }
    return qNode->ans;
}

string Game::getNodeCom(int position) {
    Node* qNode = head;
    for (int count = 0; count < position; count++) {
        qNode = qNode->next;
    }
    return qNode->command;
}

int Game::playGame() {
    srand(time(0));

    string qAns, qCom, rCom;
    int rounds = 0;
    do {
        cout << "\nAmount of questions you wish to practice (3-30): ";
        cin >> rounds;
    } while (rounds > 30 || rounds < 3);

    system("cls");

    int count = 0;
    int score = 0;
    int uAns = 0;
    int random = 0, rand2 = 0;

    for (count = 0; count < rounds; count++) {
        random = rand() % 3 + 1;
        rand2 = rand() % size + 1;
        qAns = getNodeAns(rand2);
        rCom = getNodeCom(rand2);

        // Case 1
        if (random == 1) {
            cout << "Q:\n" << qAns;
            cout << "\n1. " << rCom << endl;
            do {
                qCom = getNodeCom(rand() % size + 1);
            } while (rCom == qCom);
            cout << "2. " << qCom << endl;

            do {
                qCom = getNodeCom(rand() % size + 1);
            } while (rCom == qCom);
            cout << "3. " << qCom << endl;
            cout << "A: ";
            cin >> uAns;

            if (uAns == 1) {
                score++;
                cout << "Good Job!" << endl;
            }
            else {
                score--;
                cout << "Wrong Answer" << endl;
            }
            cout << "Score: " << score << endl;
        }

        // Similar case handling for random == 2 and random == 3...
    }
    cout << "\n\n...game over... your final score: " << score << endl;
    return score;
}

void Game::updateList() {
    ofstream ofile("commands.csv", ios::trunc);
    Node* temp = head;
    while (temp != nullptr) {
        ofile << temp->command << "," << temp->ans << "\n";
        temp = temp->next;
    }
    ofile.close();
}

Game::~Game() {
    updateList();
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void readProfiles(uProfiles arr[], int arrSize) {
    ifstream ifile("profiles.csv");
    int count = 0;

    while (getline(ifile, arr[count].name, ',') && ifile >> arr[count].points && count < arrSize) {
        count++;
    }
    ifile.close();
}

void updateProfile(uProfiles arr[], int arrSize, int score, string name) {
    bool found = false;
    for (int count = 0; count < arrSize && arr[count].name.size() > 0; count++) {
        if (name == arr[count].name) {
            arr[count].points += score;
            found = true;
            break;
        }
    }

    if (!found) {
        int i;
        for (i = 0; i < arrSize && arr[i].name.size() > 0; i++);
        if (i < arrSize) {
            arr[i].name = name;
            arr[i].points = score;
        }
    }

    ofstream ofile("profiles.csv", ios::trunc);
    for (int count = 0; count < arrSize && arr[count].name.size() > 0; count++) {
        ofile << arr[count].name << "," << arr[count].points << "\n";
    }
    ofile.close();
}