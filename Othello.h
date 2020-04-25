// Othello.h
// emma rice
//4-19-2020

#ifndef OTHELLO_H
#define OTHELLO_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>
#include "piece.h"
#include "game.h"
using namespace std;
class Othello:public main_savitch_14::game
{
public:
	Othello(){;}
	
	//separate idea of storage of board & display of same
	// *******************************************************************
	// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEN:
	// The overriding function should call the original when it finishes.
	// *******************************************************************
	// Have the next player make a specified move:
    void make_move(const std::string& move);
    // Restart the game from the beginning:
    void restart( );

    // *******************************************************************
    // OPTIONAL VIRTUAL FUNCTIONS (overriding these is optional)
    // *******************************************************************
    who winning( ) const;
    string get_user_move( ) const;
	// *******************************************************************
    // PURE VIRTUAL FUNCTIONS
	// *******************************************************************
	// (these must be provided for each derived class)
    // Return a pointer to a copy of myself:
    main_savitch_14::game* clone( )const;
	//do the above for all pure virtual functions
	
    // Compute all the moves that the next player can make:
    void compute_moves(std::queue<std::string>& moves)const;
    // Display the status of the current game:
    void display_status()const;
    // Evaluate a board position:
	// NOTE: positive values are good for the computer.
    int evaluate()const;
    // Return true if the current game is finished:
    bool is_game_over()const;
    // Return true if the given move is legal for the next player:
    bool is_legal(const std::string& move)const;

    //***************************************
    // STUFF I ADDED TO MAKE THINGS EASIER
    //***************************************
    //is legal for next next player :)
    bool next_is_legal(const std::string& move)const;
    //compute all possible moves for next next player
	void next_compute_moves(std::queue<std::string>& moves)const;
private:
	piece board[8][8]; //first is row, second is column
    int pass;
	
};

#endif

