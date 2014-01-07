#include<iostream>
#include<vector>

void sudoku_solve(int grid[9][9]);
bool isSafe(int grid[9][9],int row, int col,int num);
bool inCol(int grid[9][9],int col,int num);
bool inRow(int grid[9][9],int row,int num);
bool inBox(int grid[9][9],int row,int col,int num);
bool solve(int grid[9][9]);
bool FindUnassignedLocation(int grid[9][9], int &row, int &col);
using namespace std;

/* Head ends here */
void sudoku_solve(int grid[9][9]){
	 if (solve(grid) == true)
    {
    	for(int i=0;i<9;i++)
    	{		
			for(int j=0;j<9;j++)
    			cout<<grid[i][j]<<" ";
    		cout<<"\n";
		}
	}
}
bool solve(int grid[9][9])
{
    int row, col;
 
    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!
 
    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
 
            // return, if success, yay!
            if (solve(grid))
                return true;
 
            // failure, unmake & try again
            grid[row][col] = 0;
        }
    }
    return false; // this triggers backtracking
}
bool FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool isSafe(int grid[9][9],int row, int col,int num)
{
	return ( (!inCol(grid,col,num)) && (!inRow(grid,row,num)) && (!inBox(grid,row - row%3,col - col%3,num)));			
}

bool inCol(int grid[9][9],int col,int num)
{
	for(int i=0;i<9;i++)
		if(grid[i][col]==num)
			return true;
	return false;
}
bool inRow(int grid[9][9],int row,int num)
{
	for(int i=0;i<9;i++)
		if(grid[row][i]==num)
			return true;
	return false;
}
bool inBox(int grid[9][9],int row,int col,int num)
{
	for(int i=0+row;i<3;i++)
		for(int j=0+col;j<3;j++)
			if(grid[i][j]==num)
				return true;
	return false;
}
/* Tail starts here */
int main(void) {
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
               board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);
    }
    return 0;
}
