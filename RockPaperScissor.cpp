#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

char generatecomputermove() {
    int randomvalue;
    srand(time(0));
    randomvalue = rand() % 3;

    if (randomvalue == 0) {
        return 'p';
    } else if (randomvalue == 1) {
        return 's';
    } else {
        return 'r';
    }
}

int determinegameresult(char playermove, char computermove) {
    if (playermove == computermove) {
        return 0;
    }
    if (playermove == 's' && computermove == 'p') {
        return 1;
    }
    else if (playermove == 'p' && computermove == 'r'){
        return 1;
    }
    else if(playermove == 'r' && computermove == 's'){
    return -1;
    }
}

string convertmovetoname(char move) {
    if (move == 'r') {
        return "Rock";
    }
    else if (move == 'p') {
        return "Paper";
    }
    else if (move == 's') {
        return "Scissors";
    }
    return "Invalid Move";
}

int main() {
    char playermove;

    cout << "\n\n\n\t\t--------------------------------------------------";
    cout << "\n\n\t\t\t\t     Hi User!";
    cout << "\n\n\t\t\tWelcome to Rock Paper Scissors: The Game\n";
    cout << "\n\t\tEnter r for Rock, p for Paper, and s for Scissors:\n\t\t\t\t\t";
    cout << "\n\t\t--------------------------------------------------\n";

    while (true) {
        cout<<"\n\t\t\tEnter the Value: ";
        cin >> playermove;
        if (playermove == 'p' || playermove == 'r' || playermove == 's') {
            break;
        } else {
            cout << "\t\t\tInvalid Move! Please enter r, p, or s." << endl;
        }
    }

    char computermove = generatecomputermove();
    int result = determinegameresult(playermove, computermove);
    if (result == 0) {
        cout << "\n\t\t\tIt's a Draw!\n";
    } else if (result == 1) {
        cout << "\n\t\t\tCongratulations! You won!\n";
    } else {
        cout << "\n\t\t\tOh no! The computer won!\n";
    }
    cout << "\t\t\tYour Move: " << convertmovetoname(playermove) << endl;
    cout << "\t\t\tComputer's Move: " << convertmovetoname(computermove) << endl;

    return 0;
}
