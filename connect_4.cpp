#include <iostream>
#include <string>


using namespace std;

class Board
{

private:
	char player;
	char board[6][7];

public:
	Board ();
	void showBoard();
	bool checkMove(int);
	void makeMove(char, int);
	bool isFull();
	bool hasWon(char);
	void hostGame();

};
//Construct Game Board
Board::Board ()
{
	for (int row=0; row<6; row++)
	{
		for (int col=0; col<7; col++)
		{
			board[row][col]='e';

		}
	}
	player='x';

}
//Put Gameboard on screen
void Board::showBoard()
{
	for (int row=0; row<6; row++)
	{
		cout<<endl<<"|";
		for (int col=0; col<7; col++)
		{
			if (board[row][col]=='e')
				cout<<" |";
			else
				cout<<board[row][col]<< "|";
		}
	}
}
//Check if the space is filled
bool Board::checkMove(int col)
{
	if(col < 0 || col >6)
		return false;
	if(board[0][col] == 'e')
		return true;
	else
		return false;
}
//allow player to move
void Board::makeMove (char player,int col)
{

	int best=0;
	for (int row=0; row<6;row++)
	{
		if (board[row][col]=='e')
			best=row;
	}//when this ends, best stores where to put the move

	board[best][col]=player;



}
//check to see if board is full
bool Board::isFull()
{
	int row=0;
	for(int col=0;col<7;col++)
	{
		if (board[row][col]=='e')
		{
			return false;
		}
	}

	return true;
}
//Game winning condition filled
bool Board::hasWon(char player)
{
	for (int r=0;r<3;r++)
	{
		for (int c=0;c<4;c++)
		{
			if (board[r][c]==player && board[r+1][c+1]==player && board[r+2][c+2]==player && board[r+3][c+3]==player)
				return true;
		}
	}
	for (int r=0;r<3;r++)
	{
		for (int c=0;c<7;c++)
		{
			if (board[r][c]==player && board[r+1][c]==player && board[r+2][c]==player && board[r+3][c]==player)
				return true;
		}
	}
	for (int r=0;r<6;r++)
	{
		for (int c=0;c<4;c++)
		{
			if (board[r][c]==player && board[r][c+1]==player && board[r][c+2]==player && board[r][c+3]==player)
				return true;
		}
	}
	for (int r=5;r>2;r--)
	{
		for (int c=0;c<4;c++)
		{
			if (board[r][c]==player && board[r-1][c+1]==player && board[r-2][c+2]==player && board[r-3][c+3]==player)
				return true;
		}
	}
	return false;
}
//player moves
void Board::hostGame()
{
	bool gameOver=false;
	int col;
	string player1name;
	string player2name;
	cout << "Player 1, Enter your name." << endl;
	cin >> player1name;
	cout << "Player 2, Enter your name." << endl;
	cin >> player2name;
	do
	{
		showBoard();
		//Player 1
		if (player=='x')
		{
			do
			{
				cout<< player1name << " - Enter column you would like to move:\n 0 1 2 3 4 5 6"<<endl;
				cin>>col;
				checkMove(col);
				if (checkMove(col)==false)
					cout<<"invalid move enter column (0-6)\n";
				makeMove(player,col);
			}while(!checkMove(col));
			player='o';
		}
		//Player 2
		else
		{
			do
			{
				cout<< player2name << " - Please enter column you would like to move:\n 0 1 2 3 4 5 6"<< endl;
				cin>>col;
				checkMove(col);
				if (checkMove(col)==false)
					cout<<"Invalid move enter column (0-6)\n";
				makeMove(player,col);
			}while(!checkMove(col));
			player='x';
		}
		// end game - win message player 1
		if (hasWon('x'))
		{
			gameOver=true;
			cout<<"Congratulations " << player1name << "! You Won!\n";
		}
		// end game - win message player 2
		else if (hasWon('o'))
		{
			gameOver=true;
			cout<<"Congratulations " << player2name << "! You Won!\n";
		}
		cout << "Press any key to continue" << endl;
	}while(!gameOver && !isFull());
}


void gamebox()
{
	int players;
	cout << "WELCOME TO CONNECT 4" << endl;
	do
	{
		cout << "Press 1 if you would like to play? or press 2 to exit?" << endl;
		cin >> players;
		if(players==1)
		{
			Board b;
			b.hostGame();
			char d;
			cin >> d;
		}
		else if(players==2)
			exit(1);
	}while(players != 1);
}


int main (){

	gamebox();
	char c;
	cin >> c;
	return 0;
}
