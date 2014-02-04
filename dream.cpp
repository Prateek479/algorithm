#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//nlhthgrfdnnlprjtecpdrthigjoqdejsfkasoctjijaoebqlrgaiakfsbljmpibkidjsrtkgrdnqsknbarpabgokbsrfhmeklrles

int main(){
	string s;
	int p[257],i,j,k,t,p1,p2,r;
//	std::ifstream file("read.txt");
// 	std::getline(file,s);
	cin>>s;
 	for(i=0;i<257;i++)
 		p[i]=-1;
	 
	for(i=0;s[i]!='\0';i++) 
	{ 
		p1=-1;
		p2=-1;
		r=1;
		for(j=0;p[j]!=-1;j++)
		{
			if(p1==-1 && p[j]==s[i])
			{
				p1=j;
				for(k=j+1;p[k]!=-1;k++)
				{
					if(p[k]>s[i])
					{
						p2=k;
						break;
					}
				}
				if(p2>-1)
				{
					for(k=p1+1;k<p2;k++)
					{
						r=0;
						for(t=i+1;s[t]!='\0';t++)
						{
							if(s[t]==p[k])
							{
								r=1;
								break;
							}
						}
						if(r=0)
							break;
					}
				}
			}
			if(p2>-1 && r==1)
				p[j]=p[j+1];
		}
		if(p1==-1)
			p[j]=s[i];
		else if(p2>-1 && r==1)
			p[j-1]=s[i];	
	}	 
	printf("\n"); 
	for(i=0;p[i]!=-1;i++) 
		printf("%c",p[i]); 
 		
	return 0; 
}

/*
*/
