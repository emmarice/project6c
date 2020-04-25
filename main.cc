/*****************************************************
This is a sample of what the main should like for the third phase of 
the Othello game.The only change is that the game now announces tells 
the human whether or not they have won.
	John Dolan	Ohio University		Fall 2019
*************************************************************/
#include<iostream>
#include "Othello.h"
using namespace std;
using namespace main_savitch_14;


int main()
{
    Othello mygame;
	game::who winner;
	winner=mygame.play();
	if (winner == game::HUMAN)
		std::cout<<"YOU WIN!\n";
	else
		std::cout<<"YOU LOSE!\n";
	return 0;
}
