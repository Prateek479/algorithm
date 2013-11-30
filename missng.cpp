/*Sample Input

10
203 204 205 206 207 208 203 204 205 206
13
203 204 204 205 206 207 205 208 203 206 205 206 204
Sample Output

204 205 206
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,n1;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];    
	cin>>n1;
	vector<int> b(n1);
	for(int i=0;i<n1;i++)
		cin>>b[i];    
	std::sort (a.begin(), a.end());	
	std::sort (b.begin(), b.end());
	int j=0;
	for(int i=0;i<n1;i++)
	{
		if(b[i]==a[j])
			j++;
		else{
			cout<<b[i]<<" ";
		}
	}
	return 0;
}

