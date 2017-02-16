/*
FileHandler.cpp

AUTHOR:			Tim Andrew
DATE:			Feb 14th, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The FileHandler class to handle reading and writing files:

*/
#include "FileHandler.h"

	//Default FileHandler constructor:
FileHandler::FileHandler() {} 

	//FileHandler constructor saves file name:
FileHandler::FileHandler(string fileName) : FileName(fileName) {}

	//FileHandler destructor:
FileHandler::~FileHandler() {}

	//A method to return if the file exists:
bool FileHandler::Exists()
{
	ifstream fileTest(FileName.c_str());
	return fileTest.good();
}

	//a method to return the # of rows:
int FileHandler::GetRows()
{
	int rows = 0;
	string line;

	ifstream file(FileName);

	while (getline(file, line))
		++rows;

	file.close();

	rowCount = rows;
	return rows;
}

	//returns the # of columns, or -1 for bad column structure
int FileHandler::GetCols()
{
	int cols = 0;
	string line;

	ifstream file(FileName);

	while (getline(file, line))
	{
		int countedCols = 0;
			//Trim the line of Carriage Returns:
		//line.erase(line.find_last_not_of("\n\r\t") + 1); //NOT NEEDED.

		for (char& c : line)
		{
			++countedCols;
		}

			//Determine the cols:
		if (cols == 0)
		{
			cols = countedCols;
		}
		else if (cols != countedCols)
		{
				//return -1 if any columns are un-even.
			return -1;
		}
	}
	file.close();

	colCount = cols;
	return cols;
}

	//a method to populate an array with data from a file stream:
void FileHandler::PopulateArray(char **&arr)
{
	string line;

	ifstream file(FileName);

	int rowCount = 0;
	
		//search each line:
	while (getline(file, line))
	{
		int colCount = 0;
		
			//for each char in this line
		for (char& c : line)
		{
				//set the char into its array position:
			arr[rowCount][colCount] = c;
			++colCount;
		}
		++rowCount;
	}

	file.close();
}

	//a method to write out the solution to a file:
void FileHandler::WriteSolution(char **&arr)
{

	ofstream file(FileName+".Solution.txt");
	string line = "The Solution for '" + FileName + "':\n\n";
		//write out the header:
	file << line;

		//for each row
	for (int i = 0; i < rowCount; i++)
	{
			//reset line
		line = "";
			//for each col:
		for (int j = 0; j < colCount; j++)
		{
				//add the char to the string:
			line += arr[i][j];
		}
			//append a line break:
		line += "\n";

		//then write the line:
		file << line;
	}

	file.close();
}
