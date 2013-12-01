/*

Mr. Dorsey Dawson recently stole X grams of gold from ACME Jewellers. He is now on a train back home. To avoid getting caught by the police, he has to convert all the gold he has into paper money. He turns into a salesman and starts selling the gold in the train.

There are N passengers who have shown interest in buying the gold. The ith passenger agrees to buy ai grams of gold by paying $vi. Dawson wants to escape from the police and also maximize the profit. Can you help him maximize the profit?

Note: The ith passenger would buy exactly ai grams if the transaction is successful.

Input Format
The first line contains two space separated integers, N X, where N is the number of passengers who agreed to buy and X is the stolen amount of gold (in grams).
N lines follow. Each line contains two space separated integers - vi and ai, where vi is the the value which the ith passenger has agreed to pay in exchange for ai grams of gold.

Output format:
If it’s possible for Dorsey to escape, print the maximum profit he can enjoy, otherwise print “Got caught!” (quotes are for clarity)

Constraints
1 <= X <= 5000
1 <= N <= 106
all vi’s and ai’s are less than or equal to 106 and greater than 0.

Sample input #00

4 10
460 4
590 6
550 5
590 5
Sample output #00

1140
Sample input #01

4 9
100 5
120 10
300 2
500 3
Sample output #01

Got caught!
Explanation

Sample Case #00: Selling it to passengers buying 4 grams and 6 grams would lead to $1050 whereas selling it to passengers buying 5 grams gold would lead to $1140. Hence the answer.

Sample Case #01: There is no way to sell all 9 grams of gold.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;
typedef pair<double,pi> pd;

int n,x;

int ar[5010];

int main()
{
	int a,b;
	cin>>n>>x;
	pd arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr[i]= pd(double(b)/a, pi(a, b));
	}
	sort(arr,arr + n);
	for(int i=0;i<5010;i++)
		ar[i]=-1;
	ar[0]=0;
	for(int i=0;i<n;i++)
	{
		a=arr[i].second.first;
		b=arr[i].second.second;
		for(int j=x-b;j>=0;j--)
		{
				if(ar[j]!=-1)
				{
					ar[j+b]=max(ar[j+b],ar[j]+a);
				}
		}		
	}
	if (ar[x] == -1) printf("Got caught!\n");
    else cout<<ar[x];
 
	return 0;
}

