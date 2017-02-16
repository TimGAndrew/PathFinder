/*
Node.cpp

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Node Class for handling each data node in memory.

*/
#include "Node.h"

	//Default Node constructor:
Node::Node() : nextNode(NULL), prevNode(NULL) {}
	
	//Node Desctuctor:
Node::~Node() {}

	//Methods to get and set row/col # in map:
void Node::setRowCol(int row, int col) 
{ 
	this->rowcol[0] = row; 
	this->rowcol[1] = col;
}
int Node::getRow() { return rowcol[0];  }
int Node::getCol() { return rowcol[1]; }

	//Methods to get and set nextNode/prevNode pointers:
void Node::setNextNode(Node* next) { nextNode = next; }
Node* Node::getNextNode() { return nextNode; }
void Node::setPrevNode(Node* prev) { prevNode = prev; }
Node* Node::getPrevNode() { return prevNode; }