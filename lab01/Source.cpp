#include <iostream>
#include <ctime>
#include <cstdlib>
#include "array2D.h"

using namespace std;

class Cell
{
public:
	Cell();
	~Cell();

	bool getIsBomb();
	char getState();

	void setState(char input);
	void setIsBomb(bool input);
	void setBombNum(int input);

	void drawCell();

private:
	char m_state; //covered, uncovered, marked
	bool m_isBomb;
	int m_bombsNear;
};

Cell::Cell() {
	m_state = 'c';
	m_isBomb = false;
	m_bombsNear = 0;
}

Cell::~Cell() { }
bool Cell::getIsBomb() { return m_isBomb; }
char Cell::getState() { return m_state; }
void Cell::setState(char input) { m_state = input; }
void Cell::setIsBomb(bool input) { m_isBomb = input; }
void Cell::setBombNum(int input) { m_bombsNear = input; }

void Cell::drawCell()
{
	switch (m_state) {
	case 'm':
		if (m_isBomb)
			std::cout << '*';
		else
			std::cout << 'X';
		break;
	case 'u':
		std::cout << m_bombsNear;
		break;
	default:
		std::cout << ' ';
		break;
	}
}

class Board
{
	//b = beginner board; 10x10; 10 mines
public:
	Board();
	Board(char input);
	~Board();

	void setBombNum();
	void drawBoard();
	int getBombNum(int row, int col);
	void changeState(char input, int x, int y);

private:
	int m_gridSize;
	Array2D<Cell> *m_board;
};

Board::Board()
{
	m_gridSize = 0;
}

Board::Board(char input)
{
	int i, j;
	if (input == 'b')
	{
		//variable declaration
		int temp;
		int bombs;

		m_gridSize = 10;
		m_board = new Array2D<Cell>(m_gridSize, m_gridSize);
		do      //so; I discovered that maybe there were bombs left over. 
		//that just won't do. gotta redo it until we use ALL the
		//bombs
		{
			bombs = 10;
			//clear the board first. easier to do it here.
			for (i = 0; i<m_gridSize; i++)
			{
				for (j = 0; j<m_gridSize; j++)
				{
					m_board->Select(i, j).setState('?');
					m_board->Select(i, j).setIsBomb(false);
				}
			}

			for (i = 0; i<m_gridSize; i++)
			{
				for (j = 0; j<m_gridSize; j++)
				{
					//m_board->Select(i,j).setState('?');
					temp = rand() % m_gridSize + 1;
					if ((temp == 10) && (bombs > 0))
					{
						//m_board->Select(i,j).setState('b');
						m_board->Select(i, j).setIsBomb(true);
						//bombNum = 0;
						bombs--;
					}
					else
					{
						//m_board->Select(i,j).setState('x');
						m_board->Select(i, j).setIsBomb(false);
						//bombNum();

					}
				}
			}
		} while (bombs>0);
	}
	for (i = 0; i<m_gridSize; i++)
	{
		for (j = 0; j<m_gridSize; j++)
		{
			m_board->Select(i, j).setBombNum(getBombNum(i, j));
		}
	}

}

int Board::getBombNum(int row, int col)
{
	int count = 0;

	if ((row>0) && (row<m_gridSize)) { //look up 
		if (m_board->Select(row - 1, col).getIsBomb()) { count++; }
	}

	if ((row>-1) && (row<m_gridSize - 1)) { //look down 
		if (m_board->Select(row + 1, col).getIsBomb()) { count++; }
	}

	if ((col>0) && (col<m_gridSize)) { //look left 
		if (m_board->Select(row, col - 1).getIsBomb()) { count++; }
	}

	if ((col>-1) && (col<m_gridSize - 1)) { //look right 
		if (m_board->Select(row, col + 1).getIsBomb()) { count++; }
	}

	if ((row>0) && (row<m_gridSize) && (col>-1) && (col<m_gridSize - 1)) { //look up/right 
		if (m_board->Select(row - 1, col + 1).getIsBomb()) { count++; }
	}

	if ((row>-1) && (row<m_gridSize - 1) && (col>-1) && (col<m_gridSize - 1)) { //look down/right 
		if (m_board->Select(row + 1, col + 1).getIsBomb()) { count++; }
	}

	if ((row>0) && (row<m_gridSize) && (col>0) && (col<m_gridSize)) { //look up/left 
		if (m_board->Select(row - 1, col - 1).getIsBomb()) { count++; }
	}

	if ((row>-1) && (row<m_gridSize - 1) && (col>0) && (col<m_gridSize)) { //look down/left 
		if (m_board->Select(row + 1, col - 1).getIsBomb()) { count++; }
	}

	return count;
}


Board::~Board()
{
	//if(m_board != NULL)
	//   delete [] m_board;
	// std::cout << "deleted board" << std::endl;

}

void Board::drawBoard()
{
	int i, j;

	std::cout << "Game Board" << std::endl;
	std::cout << "**";
	for (i = 0; i<m_gridSize; i++)
		std::cout << "*";
	std::cout << "**" << std::endl;

	for (i = 0; i<m_gridSize; i++)
	{
		std::cout << "* ";

		for (j = 0; j<m_gridSize; j++)
		{
			m_board->Select(i, j).drawCell();
		}
		std::cout << " *" << std::endl;
	}
	std::cout << "**";
	for (i = 0; i<m_gridSize; i++)
		std::cout << "*";
	std::cout << "**" << std::endl;
}

void Board::changeState(char input, int x, int y)
{
	m_board->Select(x, y).setState(input);
}

class Minesweeper
{
public:
	Minesweeper();
	~Minesweeper();

	char takeATurn(char move, int x, int y);

private:
	Board foo;
};

Minesweeper::Minesweeper()
{
	char gameLevel = 'b';
	Board foo(gameLevel);
	foo.drawBoard();
}

Minesweeper::~Minesweeper()
{

}

char Minesweeper::takeATurn(char move, int x, int y)
{
	char gameState;

	foo.changeState(move, x, y);
	//foo.drawBoard();

	gameState = 'y';
	return gameState;
}

int main()
{

	char playAgain = 'y';
	do
	{
		srand(time(NULL)); //seeding the random number generator
		Minesweeper game;
		char gameOver = 'n';

		do
		{
			char move;
			int x, y;

			cout << "Enter a move [m]ark, [u]ncover: ";
			cin >> move;
			cout << "Enter a row: ";
			cin >> x;
			cout << "Enter a column: ";
			cin >> y;

			gameOver = game.takeATurn(move, x, y);
		} while (gameOver == 'n');
		playAgain = 'n';
	} while (playAgain == 'y'); //this forces at least a single pass through the loop

	return 0;
}