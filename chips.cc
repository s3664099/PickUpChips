//My first c++ program
//by David Sarkies BA LLB

//TO DO - Create an AI option to play against the computers

//iostream for inputting and outputting
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//Since functions need to be set up at the beginning of the program
//these are the functions that will be used in this program
string getName(string player[], bool playerTurn);
bool getAnswer();
void getUserNames(string player[]);
void playGame(int chips, bool playerTurn, string player[]);

//Setting up the constants
const int MAX_CHIPS = 80;
const float MAX_TURN = 0.5;

//main always runs first
int main()
{
	//variables to be used in this program		
	bool playerTurn = false;
	int computersTurn = 0;
	bool playAgain = true;

	//Seeds the randomiser
	srand (time(NULL));
	
	//Sets up the player names
	string player[2];
	getUserNames(player);

	//main loop
	do
	{
		//selects a random number between 20 and 100;
		//Establishes the chips, and the max that can be taken.
		int chips = (rand()%MAX_CHIPS)+20;

		cout << "The piles starts with " << chips << " chips \n";
		
		playGame(chips, playerTurn, player);

		cout << getName(player, playerTurn) << " is the winner!\n";

		//will break out of the loop if the player no longer wishes to play
		cout << "Do you wish to play again?\n";
		playAgain = getAnswer();
	}while(playAgain);

	return 0;
}

//this function will return either a yes or a no.
//it is used to obtain an answer from the player.
bool getAnswer()
{
	char answer;
	bool correct = false;

	do {
		cin >> answer;
		answer = toupper(answer);

		if (answer == 'Y')
			return true;
		else if (answer == 'N')
			return false;
		
		cout << "Please enter Y or N";
	} while (!correct);
	
	return 0;
}

//this function returns the name of the player
string getName(string player[], bool playerTurn)
{
	if (playerTurn)
		return player[0];
	else
		return player[1];
}

//this function prompts the players to enter their names
void getUserNames(string player[])
{
	cout << "Please enter Player One's Name\n";
	cin >> player[0];
	cout << "Please enter Player Two's Name\n";
	cin >> player[1];
}

//This is the main game function.
void playGame(int chips, bool playerTurn, string player[])
{
	//Sets the game over to be false - if it is true the while loop ends.
	bool gameOver = false;

	
	while (!gameOver){
		
		//variables to be used in the game, namely chips taken in the turn
		//and the max number of chips allowed to be taken
		int chipsTaken = 0;
		int maxChips = (chips*MAX_TURN);
		
		//Asks the player how many chips they would like, and determines whether the
		//move is legal, that is that the player has not taken too many chips.
		//Also will round up the value of the max chips that can be taken if it ever reaches 0.
		do {
			cout << "It is " << getName(player, playerTurn) << "'s turn\n";
			
			cout << "How many chips will you take?\n";
		
			if (maxChips ==0)
				cout << "You can take 1 chip\n";
			else
				cout << "You can take up to " << maxChips << "\n";

			cin >> chipsTaken;

		} while ((chipsTaken > maxChips) && (chips > 1));
		
		//reduces the number of chips in the pile
		chips = chips - chipsTaken;
		cout << "There are " << chips << " left in the pile\n";
	
		//Checks to see if there are any chips left in the pile
		//if not, then flags that the game is over
		if (chips == 0)
			gameOver=true;
		
		//switches the player
		playerTurn = !playerTurn;
	}
}


