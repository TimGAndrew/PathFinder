/*
Path.cpp

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Path Class, a stacked/queued list for finding a path through a maze

*/
#include "Path.h"
//#include <Windows.h>

		//Default constructor for the path:
	Path::Path() : First(NULL), Last(NULL) {}

		//Constructor for the path, tha handles a char array:
	Path::Path(char **&array, int rows, int cols) 
		: arr(array), rows(rows), cols(cols), First(NULL), Last(NULL) {}

		//Destructor for the path:
	Path::~Path()
	{
			//While First is not Null:
		while (First != NULL)
		{
				//queue out each item:
			Serve();
		}
	}

		//Creates node and begins to find its path
	void Path::Add(int row, int col)
	{
			//If, by chance, the end is found, exit:
		if (endFound) return;

			//Set up a new node:
		Node* node = new Node();

			//Store the incoming position:
		node->setRowCol(row,col);

			//Mark the array with the pathMarker
		arr[row][col] = pathMarker;

			//Find the node's possible moves:
		PollMoves(node);
	
			//If if this Path was just created:
		if (this->First == NULL)
		{
				//set this node as the First node:
			this->First = node;
				//set this node's previous value to NULL
			node->setPrevNode(NULL);
		}
		else
		{
				//otherwise set the last node's next node to this node
			this->Last->setNextNode(node);
				//set this nodes previous node
			node->setPrevNode(Last);

		}
		//set this node as the Last node:
		Last = node;

		/* //PRINTOUT TEST
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, {0,0});
		//system("cls");
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		*/
			//Move the path:
		ExpandPath(node);

	}

		//A queue method to get rid of the first node in the path:
	void Path::Serve()
	{
			//set up a new node equal to the path's first node:
		Node* node = First;

			//Set the first node pointer to point to this node's next node
		First = First->getNextNode();

			//Then delete this node's data:
		delete node;
	}

		//A method to poll each node to set its move flags:
	void Path::PollMoves(Node* node)
	{
			//check Right:
		if (node->getCol() + 1 <= cols)
		{
			if (arr[node->getRow()][node->getCol() + 1] == ' ')
			{
				node->canMoveRight = true;
			}
		}

			//check Left:
		if (node->getCol() - 1 >= 0)
		{
			if (arr[node->getRow()][node->getCol() - 1] == ' ')
			{
				node->canMoveLeft = true;
			}
		}

			//check Down:
		if (node->getRow() + 1 <= rows)
		{
			if (arr[node->getRow() + 1][node->getCol()] == ' ')
			{
				node->canMoveDown = true;
			}
		}

			//check Up:
		if (node->getRow() - 1 >= 0)
		{
			if (arr[node->getRow() - 1][node->getCol()] == ' ')
			{
				node->canMoveUp = true;
			}
		}
	}
	
		//A method to Expand the path
	void Path::ExpandPath(Node* node)
	{
			//if the row or col of this node has reached the end of the maze:
		if (node->getCol() == cols -1 || node->getRow() == rows -1 || endFound == true)
		{
			endFound = true;
			return;
		}	

			//If the path can move up:
		else if (node->canMoveUp == true)
		{
				//set up to false:
			node->canMoveUp = false;

				//add a node there:
			Add(node->getRow() - 1, node->getCol());

		}

			//If the path can move Down:
		else if (node->canMoveDown == true)
		{
				//set it to false:
			node->canMoveDown = false;

				//add a node there:
			Add(node->getRow() + 1, node->getCol());
		}

			//If the path can move Left:
		else if (node->canMoveLeft == true)
		{
				//set it to false:
			node->canMoveLeft = false;

				//add a node there:
			Add(node->getRow(), node->getCol() - 1);

		}

			//If the path can move Right:
		else if (node->canMoveRight == true)
		{
				//set it to false:
			node->canMoveRight = false;

				//add a node there:
			Add(node->getRow(), node->getCol() + 1);
		}
			//Otherwise the path can't expand and it needs to back off:
		else
		{
			BackOff(node);
		}
	}

		//A method to back up the path:
	void Path::BackOff(Node* node)
	{
			//set this node's array to a space:
		arr[node->getRow()][node->getCol()] = ' ';

			//get the previous node pointer
		Node* nextNode = node->getPrevNode();

			//Then set that node as the Path's Last node:
		Last = nextNode;

			//delete the node
		delete node;

		/* //PRINTOUT TEST
		//system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, {0,0});
		for (int i = 0; i < rows; i++)
		{
		for (int j = 0; j < cols; j++)
		{
		cout << arr[i][j];
		}
		cout << endl;
		}
		*/

			//Then see if the next node can expand the path:
		ExpandPath(nextNode);
	}



