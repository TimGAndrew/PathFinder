/*
Path.h

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A header file for the Path class

*/
#ifndef PATH_H
#define PATH_H

#include "Includes.h"
#include "Node.h"

class Path 
{
private:
		//The Path's marker:
	char pathMarker = '#';

		//2d Char array:
	char** arr;

		//# of :
	int cols;
	int rows;

		//Handle if the end has been found:
	bool endFound = false;

		//The first and last nodes:
	Node* First;
	Node* Last;

		//Functions to handle the maze hunting:
	void PollMoves(Node* node);
	void ExpandPath(Node* node);
	void BackOff(Node* node);
		//function to handle path destruction:
	void Serve();

public:

	Path();
	Path(char **&arr, int rows, int cols);
	virtual ~Path();

	void Add(int row, int col);

};
#endif PATH_H

