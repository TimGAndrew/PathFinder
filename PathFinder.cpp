/*
	PathFinder.cpp

	AUTHOR:			Tim Andrew
	DATE:			Feb 14th, 2016
	CLASS:			PROG2400-701 - Assignment #2
	INSTRUCTOR:		Hal O'Connell
	DESCRIPTION:	A Program to find a path through a maze.

*/
#include "FileHandler.h"
#include "Path.h"

	//Main entry requires maze file
int main(int argc, char* argv[])
{
		//Set variables to handle cols/rows:
	int cols;
	int rows;

		//Set up a FileHandler to handle the incoming file:
	FileHandler file;

		//If one paramataer was added:
	if (argc == 2)
	{
			//Instantiate FileHandler with the incoming file:
		file = FileHandler(argv[1]);

			//If file doesn't exist:
		if (!file.Exists())
		{
				//Exit program:
			cout << "Invalid file!\n Usage:  PathFinder input.file" << endl;
			return 0;
		}
	}
		//If there aren't 2 arguments:
	else 
	{
			//Exit program:
		cout << " Usage:  PathFinder input.file" << endl;
		return 0;
	}

		//Get file rows and columns:
	cols = file.GetCols();
	rows = file.GetRows();

		//Handle if cols is -1 (meaning file columns are non-uniform);
	if (cols == -1)
	{
			//Exit program:
		cout << "File with non-uniform columns can't be used!\n Usage:  PathFinder input.file" << endl;
		return 0;
	}

		//Create a 2d Array:
	char **arr = new char*[rows];
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new char[cols];
	}

		//Populate the array with file chars:
	file.PopulateArray(arr);

		//Initialize a new path with the 2d array, and the max rows/cols:
	Path path(arr,  rows, cols);
		
		//(Alternative: write a routine to probe the perimiter and try each ' ' char)

		//pick array[1][0] as entry point and go to work:
	path.Add(1, 0);

		//output the array to the screen
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

		//save the solution:
	file.WriteSolution(arr);

		//delete the 2nd element of the array:
	for (int i = 0; i<rows; i++)
		delete[] arr[i];
		//delete the array:
	delete[] arr;

	return 0;
}