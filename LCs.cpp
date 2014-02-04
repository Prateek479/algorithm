/* A Naive recursive implementation of LCS problem */
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
/*int max(int a, int b);
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
/*int lcs( char *X, char *Y, int m, int n )
{
	
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
 */
/* <span class="i6hy39c49" id="i6hy39c49_4">Utility function</span> to get max of 2 integers */
/*int max(int a, int b)
{
    return (a > b)? a : b;
}
 */
/* Driver program to test above function */

int max(int a , int b)
{
    if(a>b) 
        return a;
    else 
        return b;
}
/* The printing function that is not functioning Properly */
string backtrack(vector< vector<int> > C, string X,string Y,int i,int j)
{
    if( i<0  || j<0)
        return "";
    else if( X[i] == Y[j])
        return backtrack(C,X,Y,i-1,j-1) + X[i];
    else
        if( C[i][j-1] >= C[i-1][j] )
            return backtrack(C,X,Y,i,j-1);
        else
            return backtrack(C,X,Y,i-1,j);

}



   /* It correctly returns the subsequence length. */
int lcs( char *X, char *Y, int m, int n )
{
	
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int main()
{
  char X[] = "AGGTAB";
  char Y[]  = "GXTXAYB";
 
 
  printf("Length of LCS is %d\n", lcs( X, Y ,6,7) );
 
  getchar();
  return 0;
}


