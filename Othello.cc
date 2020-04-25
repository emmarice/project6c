// File: Othello.cc
//emma rice
//4-19-2020
#include "Othello.h"
#include <cctype>
//separate idea of storage of board & display of same
// *******************************************************************
// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEN:
// The overriding function should call the original when it finishes.
// *******************************************************************
// Have the next player make a specified move:
void Othello::make_move(const std::string& move)
{ 
	if (move == "bahweep")
	{
		pass++;
	}
	else
	{
		int row, col;
		col = int(toupper(move[0]) - 'A');
		row = int(move[1]-'1');
		board[row][col].flip(moves_completed() % 2 == 0);
		//figure out which pieces have been outflanked
		//8 possible directions: 
		// north
		stack<piece*> pieces;
		stack<piece*> piecesn;
		stack<piece*> piecess;
		stack<piece*> piecese;
		stack<piece*> piecesw;
		stack<piece*> piecesnw;
		stack<piece*> piecesne;
		stack<piece*> piecessw;
		stack<piece*> piecesse;

		for (int j = row-1; j >= 0; --j)
		{
			if (board[j][col].is_empty())
			{
				j = -1;
			}
			else if (board[j][col] != board[row][col])
			{
				piecesn.push((&board[j][col])); //check to see if syntax is right
			}
			else if(board[j][col] == board[row][col])//if you find your own pieces
			{
				while(!piecesn.empty())
				{
					pieces.push(piecesn.top());
					piecesn.pop();
				}
				//end for loop
				j=-1;
			}
		}
		
		// south
		for (int j = row+1; j < 8; ++j)
		{
			if (board[j][col].is_empty())
			{
				j = 9;
			}
			else if (board[j][col] != board[row][col])
			{
				piecess.push(&(board[j][col])); //check to see if syntax is right
			}
			else if(board[j][col] == board[row][col])//if you find your own pieces
			{
				while(!piecess.empty())
				{
					pieces.push(piecess.top());
					piecess.pop();
				}
				//end for loop
				j=9;
			}
		}
		
		// east
		for (int j = col+1; j < 8; ++j)
		{
			if (board[row][j].is_empty())
			{
				j = 8;
			}
			else if (board[row][j] != board[row][col])
			{
				piecese.push(&(board[row][j])); //check to see if syntax is right
			}
			else if(board[row][j] == board[row][col])//if you find your own pieces
			{
				while(!piecese.empty())
				{
					pieces.push(piecese.top());
					piecese.pop();
				}
				//end for loop
				j=8;
			}
		}
		
		// west
		for (int j = col-1; j > -1; --j)
		{
			if (board[row][j].is_empty())
			{
				j = -1;
			}
			else if (board[row][j] != board[row][col])
			{
				piecesw.push(&(board[row][j])); //check to see if syntax is right
			}
			else if(board[row][j] == board[row][col])//if you find your own pieces
			{
				while(!piecesw.empty())
				{
					pieces.push(piecesw.top());
					piecesw.pop();
				}
				//end for loop
				j=-1;
			}
		}
		
		// northeast
		for (int j = col+1, i = row-1; (j < 8) && (i > -1); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != board[row][col])
			{
				piecesne.push(&(board[i][j])); //check to see if syntax is right
			}
			else if(board[i][j] == board[row][col])//if you find your own pieces
			{
				while(!piecesne.empty())
				{
					pieces.push(piecesne.top());
					piecesne.pop();
				}
				//end for loop
				j=8;
			}
			--i;
		}
		
		// southeast
		for (int j = col+1, i = row+1; (j < 8) && (i < 8); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != board[row][col])
			{
				piecesse.push(&(board[i][j])); //check to see if syntax is right
			}
			else if(board[i][j] == board[row][col])//if you find your own pieces
			{
				while(!piecesse.empty())
				{
					pieces.push(piecesse.top());
					piecesse.pop();
				}
				//end for loop
				j=8;
			}
			++i;
		}
		
		// southwest
		for (int j = col-1, i = row+1; (j > -1) && (i < 8); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != board[row][col])
			{
				piecessw.push(&(board[i][j])); //check to see if syntax is right
			}
			else if(board[i][j] == board[row][col])//if you find your own pieces
			{
				while(!piecessw.empty())
				{
					pieces.push(piecessw.top());
					piecessw.pop();
				}
				//end for loop
				j=-1;
			}
			++i;
		}
		
		// northwest
		for (int j = col-1, i = row-1; (j > -1) && (i > -1); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != board[row][col])
			{
				piecesnw.push(&(board[i][j])); //check to see if syntax is right
			}
			else if(board[i][j] == board[row][col])//if you find your own pieces
			{
				while(!piecesnw.empty())
				{
					pieces.push(piecesnw.top());
					piecesnw.pop();
				}
				//end for loop
				j=-1;
			}
			--i;
		}
		while(!pieces.empty())
		{
			//flip all enemy pieces
			pieces.top()->flip();
			pieces.pop();
		}
	}
	main_savitch_14::game::make_move(move); 
}
// Restart the game from the beginning:
void Othello::restart() 
{ 
	pass = 0;
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{	
			board[j][i].clear();
			//j is row number
			//i is column number
			if((j == 3 && i == 3) || (j == 4 && i == 4)) //d4 e5
			{
				board[j][i].flip();
			}
			else if((j == 4 && i == 3) || (j == 3 && i == 4)) //d5 e4
			{
				board[j][i].flip(true);
			}
		}
	}
	main_savitch_14::game::restart(); 
}

string Othello::get_user_move( ) const
    {
    	queue<std::string> moves;
    	compute_moves(moves);
		if (moves.empty())
		{
			display_message("No available moves. Skipping turn.\n");
			return "bahweep";
		}
		else
		{
			string answer;
			display_message("Your move, please: ");
			getline(cin, answer);
			return answer;
		}
    }

// *******************************************************************
// PURE VIRTUAL FUNCTIONS
// *******************************************************************
// (these must be provided for each derived class)
// Return a pointer to a copy of myself:
main_savitch_14::game* Othello::clone( )const
{
	main_savitch_14::game* tmp = new Othello(*this);
	return tmp;
}

// Compute all the moves that the next player can make:
void Othello::compute_moves(std::queue<std::string>& moves)const
{
	for(int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			//convert i,j to string
			std::string move = {(char(i + 'A')), (char(j + '1'))};
			if (is_legal(move))
			{
				moves.push(move);
			}
		}
	}
	return;
}
// Display the status of the current game:
void Othello::display_status()const
{
	cout << "\n |--- --- --- --- --- --- --- ---|\n";
	cout << " | A   B   C   D   E   F   G   H | \n";
	for (int j = 0; j < 8; ++j)
	{
		cout << j+1 << "| ";
		for (int i = 0; i < 8; ++i)
		{	
			//board[j][i]
			//j is row number
			//i is column number
			string bpiece;
			if(!board[j][i].is_empty())
			{
				if(board[j][i].is_white())
				{
					cout << "O";
				}
				else
				{
					cout << "X";
				}
			}
			else
			{
				cout << "-";
			}
		   	cout << " | ";
		}
		cout << "\n |--- --- --- --- --- --- --- ---|\n";
	}
	return;
}
// Evaluate a board position:
// NOTE: positive values are good for the computer.
int Othello::evaluate( )const
{
	int points;
	int human = 0;
	int computer = 0;
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{	
			if(!board[j][i].is_empty())
			{
				if ((i == 0 || i == 7) && (j == 0 || j == 7))
				{
					points = 5;
				}
				else
				{
					points = 1;
				}
				if(board[j][i].is_white())
				{
					human += points;
				}
				else
				{
					computer += points;
				}
			}
		}
	}
	if (moves_completed() % 2 != 0) //cpu just went
	{
		return human - computer;
	}
	else
	{
		return computer - human;
	}
}
// Return true if the current game is finished:
bool Othello::is_game_over( )const
{
	if (pass == 2)
	{
		return true;
	}
	return false;
}
//returns the winner of the game
main_savitch_14::game::who Othello::winning()const
{
	int human = 0;
	int computer = 0;
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{	
			if(!board[j][i].is_empty())
			{
				if(board[j][i].is_white())
				{
					human++;
				}
				else
				{
					computer++;
				}
			}
		}
	}
	if (human > computer)
	{
		return HUMAN;
	}
	else if (computer > human)
	{
		return COMPUTER;
	}
	else{return NEUTRAL;}
}
// Return true if the given move is legal for the next player:
bool Othello::is_legal(const std::string& move)const
{
	//process a move:
	if (move == "bahweep")
	{
		return true;
	}
	int row, col;
	col = int(toupper(move[0])-'A');
	row = int(move[1]-'1');
	piece current;
	current.flip(moves_completed() % 2 == 0);
	if(!board[row][col].is_empty())
	{
		return false;
	}
	else
	{
		//8 possible directions: 
		// north
		bool enemy = false;
		for (int j = row-1; j >= 0; --j)
		{
			if (board[j][col].is_empty())
			{
				j = -1;
			}
			else if (board[j][col] != current)
			{
				enemy = true;
			}
			else if(board[j][col] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
		}
		enemy = false;
		// south
		for (int j = row+1; j < 8; ++j)
		{
			if (board[j][col].is_empty())
			{
				j = 9;
			}
			else if (board[j][col] != current)
			{
				enemy = true;
			}
			else if(board[j][col] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=9;
			}
		}
		enemy = false;
		// east
		for (int j = col+1; j < 8; ++j)
		{
			if (board[row][j].is_empty())
			{
				j = 8;
			}
			else if (board[row][j] != current)
			{
				enemy = true;
			}
			else if(board[row][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
		}
		enemy = false;
		// west
		for (int j = col-1; j > -1; --j)
		{
			if (board[row][j].is_empty())
			{
				j = -1;
			}
			else if (board[row][j] != current)
			{
				enemy = true;
			}
			else if(board[row][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
		}
		enemy = false;
		// northeast
		for (int j = col+1, i = row-1; (j < 8) && (i > -1); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
			--i;
		}
		enemy = false;
		// southeast
		for (int j = col+1, i = row+1; (j < 8) && (i < 8); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
			++i;
		}
		enemy = false;
		// southwest
		for (int j = col-1, i = row+1; (j > -1) && (i < 8); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
			++i;
		}
		enemy = false;
		// northwest
		for (int j = col-1, i = row-1; (j > -1) && (i > -1); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
			--i;
		}
		
	}
	return false;
}

//is_legal but for the next next player
bool Othello::next_is_legal(const std::string& move)const
{
	if (move == "bahweep")
	{
		return true;
	}
	//process a move:
	int row, col;
	col = int(toupper(move[0])-'A');
	row = int(move[1]-'1');
	piece current;
	current.flip(moves_completed() % 2 != 0);
	if(!board[row][col].is_empty())
	{
		return false;
	}
	else
	{
		//8 possible directions: 
		// north
		bool enemy = false;
		for (int j = row-1; j >= 0; --j)
		{
			if (board[j][col].is_empty())
			{
				j = -1;
			}
			else if (board[j][col] != current)
			{
				enemy = true;
			}
			else if(board[j][col] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
		}
		enemy = false;
		// south
		for (int j = row+1; j < 8; ++j)
		{
			if (board[j][col].is_empty())
			{
				j = 9;
			}
			else if (board[j][col] != current)
			{
				enemy = true;
			}
			else if(board[j][col] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=9;
			}
		}
		enemy = false;
		// east
		for (int j = col+1; j < 8; ++j)
		{
			if (board[row][j].is_empty())
			{
				j = 8;
			}
			else if (board[row][j] != current)
			{
				enemy = true;
			}
			else if(board[row][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
		}
		enemy = false;
		// west
		for (int j = col-1; j > -1; --j)
		{
			if (board[row][j].is_empty())
			{
				j = -1;
			}
			else if (board[row][j] != current)
			{
				enemy = true;
			}
			else if(board[row][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
		}
		enemy = false;
		// northeast
		for (int j = col+1, i = row-1; (j < 8) && (i > -1); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
			--i;
		}
		enemy = false;
		// southeast
		for (int j = col+1, i = row+1; (j < 8) && (i < 8); ++j)
		{
			if (board[i][j].is_empty())
			{
				j = 8;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=8;
			}
			++i;
		}
		enemy = false;
		// southwest
		for (int j = col-1, i = row+1; (j > -1) && (i < 8); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
			++i;
		}
		enemy = false;
		// northwest
		for (int j = col-1, i = row-1; (j > -1) && (i > -1); --j)
		{
			if (board[i][j].is_empty())
			{
				j = -1;
			}
			else if (board[i][j] != current)
			{
				enemy = true;
			}
			else if(board[i][j] == current)//if you find your own pieces
			{
				if (enemy)
				{
					return true;
				}
				//end for loop
				j=-1;
			}
			--i;
		}
		
	}
	return false;
}
//compute all possible moves for next next player
void Othello::next_compute_moves(std::queue<std::string>& moves)const
{
	for(int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			//convert i,j to string
			std::string move = {(char(i + 'A')), (char(j + '1'))};
			if (next_is_legal(move))
			{
				moves.push(move);
			}
		}
	}
	return;
}
