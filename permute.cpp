# include <stdio.h>
 
/* Function to swap values at two pointers */
void swap (int *x, int *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(int *a, int i, int n) 
{
   int j; 
   if (i == n){
   	for(int j=0;j<=n;j++)
		printf("%d", a[j]);   		
   	printf("\n");
   }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
 
/* Driver program to test above functions */
int main()
{
   int a[] = {1,2,3};  
   permute(a, 0, 2);
   return 0;
}
