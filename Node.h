/*
Node.h

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The header file for the Node class

*/
#ifndef NODE_H
#define NODE_H

#include "Includes.h"

class Node
{
private:

		//This node's location on map:
	int rowcol[2]; // rowcol[0] = row, rowcol[1] = col

		//Pointers to the previous and next nodes:
	Node* nextNode;
	Node* prevNode;

public:
		//Directions this node can move
	bool canMoveUp = false;
	bool canMoveDown = false;
	bool canMoveLeft = false;
	bool canMoveRight = false;

		//Constructors and destructors:
	Node();
	virtual ~Node();

		//Methods to handle getting the nextnode and previous node:
	void setNextNode(Node* next);
	Node* getNextNode();
	void setPrevNode(Node* prev);
	Node* getPrevNode();

		//methods to handle getting and setting the row/col:
	void setRowCol(int row, int col);
	int getRow();
	int getCol();
};
#endif NODE_H

