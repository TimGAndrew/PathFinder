/*
FileHandler.h

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The header file for the FileHandler class.

*/
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Includes.h"
#include <fstream>

class FileHandler
{
private:
		//Stores the file name argument:
	string FileName;

		//A row and col counter:
	int rowCount;
	int colCount;

public:
	FileHandler();
	FileHandler(string filename);
	virtual ~FileHandler();

	bool Exists();
	int GetCols();
	int GetRows();
	void PopulateArray(char **&arr);
	void WriteSolution(char **&arr);

};
#endif FILEHANDLER_H