#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Assume that the starting position is always [1][1]
#define START_DIM_1	1
#define START_DIM_2	1

class funMaze
{
private:
	char** maze;
	int dim1;
	int dim2;

public:
	funMaze();
	~funMaze();
	void readMaze(char* fileName);
	void solveMaze(int x,int y);
	void printMaze();
};

//A method to recursively solve the maze
//input:  A coordinate of the maze to inspect (x,y)
//output:  Either a solution to the maze or nothing if no path is found (calls printMaze())
//
//note:  we need to mark visited positions to avoid cycles when searching for a solution (testing the same positions over and over again)
void funMaze::solveMaze(int x, int y)
{
  if(maze[x][y] == ' '){
    maze[x][y] = '0';
  }

  if(maze[x][y] == 'X'){
    printMaze();
    return;
  }

  //up
  if(maze[x][y+1] == ' ' || maze[x][y+1] == 'X'){
    solveMaze(x, y+1);
  }

  //down
  if(maze[x][y-1] == ' ' || maze[x][y-1] == 'X'){
    solveMaze(x, y-1);
  }

  //right
  if(maze[x+1][y] == ' ' || maze[x+1][y] == 'X'){
    solveMaze(x+1, y);
  }

  //left
  if(maze[x-1][y] == ' ' || maze[x-1][y] == 'X'){
    solveMaze(x-1, y);
  }

  //unmark the value
  if(maze[x][y] == '0'){
    maze[x][y] = ' ';
  }

  //return
  return;
  //First check to see if the current spot is open (' ')

      //If it is mark the position as visited (0)


  //If the current spot is not open check to see if you have arrived at the goal position (X), (this is our basis case!)
      //If the goal has been found print the current solution for the maze


  //Next we need to check if there are any open spots (' ') around our current position and explore them, there are up to 4 directions to explore


  //finally after we have examined all possible paths from this location we must "unmark" this position and make it open again (' ')

  //If we have have come this far it means that there is no solution to be found along this path (our other basis case!)



}

//Constructor
funMaze::funMaze()
{
	maze = NULL;
	dim1 = 0;
	dim2 = 0;
}

//Destructor
funMaze::~funMaze()
{
	//free all memory we allocated earlier
	if(maze != NULL) {
		for(int i = 0; i < dim1; i++)
			delete[] maze[i];
		delete[] maze;
	}
}

//Reads the input file and stores the maze in an mxn array 
void funMaze::readMaze(char* fileName)
{
	ifstream file;
	file.open(fileName, ios::in);
	string dummyLine;

	//check that we correctly opened the file
	if(!file) {
		cout << "Unable to open file" << endl;
		exit(1);
	}

	//get the dimensions of the maze
	file >> dim1;
	file >> dim2;

	//place the file get pointer at the beginning of the file
	file.seekg(ios::beg);
	
	//skip over the first line
	std::getline(file, dummyLine);

	//allocate memory for the maze
	//read in at the same time
	maze = new char*[dim1];
	for(int i = 0; i < dim1; i++){
		maze[i] = new char[dim2];
		file.getline(maze[i], dim2+1);	
	}

}

//Output the current state of the maze 
void funMaze::printMaze()
{
  for(int y=0; y< dim1-1; y++){
    for(int x=0; x< dim2-1; x++){
      cout << maze[y][x];
    }
    cout << "\n";
  }
  //This should output the maze to the console
  //The output should look the same as the input file
}

int main(int argc, char* argv[])
{
	funMaze maze;

	if( argc != 2)
	{
		cout << "One argument required: name of maze input file" << endl;
		exit(1);
	}

	maze.readMaze(argv[1]);
	maze.solveMaze(START_DIM_1, START_DIM_2);
}

	
