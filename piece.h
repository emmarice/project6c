//piece.h
// emma rice
#ifndef PIECE_H
#define PIECE_H

#include <cstdlib>
using namespace std;
class piece
{
public:
	piece(){bw = false; empty = true;}
	bool flip(bool c = false) // 0 = black, 1 = white
	{
		if(empty)
		{
			bw = c;
			empty = false;
		}
		else
		{
			bw = !bw;
		}
		return bw;
	}
	bool is_empty(){return empty;}
	bool is_black(){return !bw;}
	bool is_white(){return bw;}
	bool is_empty()const{return empty;}
	bool is_black()const{return !bw;}
	bool is_white()const{return bw;}
	void clear(){empty = true; bw = false;}
	bool operator !=(const piece& other)const
	{
		if (bw)
		{
			if (other.bw)
			{
				return false;
			}
			return true;
		}
		else
		{
			if (!other.bw)
			{
				return false;
			}
			return true;
		}
	}
	bool operator ==(const piece& other)const
	{
		if (bw)
		{
			if (other.bw)
			{
				return true;
			}
			return false;
		}
		else
		{
			if (!other.bw)
			{
				return true;
			}
			return false;
		}
	}
private:
	bool bw; // 0 = black, 1 = white
	bool empty;
};

#endif
