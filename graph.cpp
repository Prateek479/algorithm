#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class  vertex{
	public :
		char label;
		bool visited;

	void add(char labs)
	{
		label=labs;
	} 
	
};

class graph{
	public:
		int vertexcount;
		vertex vertexlist[10];
		int adjmatrix[10][10];
		std::stack<int> thestack; 
		std::queue<int> thequeue;
		graph(){
			vertexcount=0;
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
					adjmatrix[i][j]=0;
		}
		
		void addvertex(char lab)
		{
			vertexlist[vertexcount++].add(lab);
		}
		void addedge(int i,int j){
			adjmatrix[i][j]=1;
			adjmatrix[j][i]=1;
		}
		void displayvertex(int v){
			cout<<vertexlist[v].label<<"\t";
		}
		int getunvisitedvertex(int v){
			for(int j=0;j<=vertexcount;j++)
				if(adjmatrix[v][j]==1 && vertexlist[j].visited==false)
						return j;
						
			return -1;
		}
		void dfs(){
			vertexlist[0].visited=true;
			displayvertex(0);
			thestack.push(0);
			while(!thestack.empty()){
				//get an unvisited verttex
				int v=getunvisitedvertex(thestack.top());
				if(v==-1)
				{
					thestack.pop();
				}	
				else {
					vertexlist[v].visited= true;
					displayvertex(v);
					thestack.push(v);
				}
			}
			for(int j=0;j<vertexcount;j++)
				vertexlist[j].visited=false;
		}
		void bfs(){
			vertexlist[0].visited=true;
			displayvertex(0);
			thequeue.push(0);
			while(!thequeue.empty()){
				//get an unvisited verttex
				int v=getunvisitedvertex(thequeue.pop());
				if(v==-1)
				{
					thequeue.pop();
				}	
				else {
					vertexlist[v].visited= true;
					displayvertex(v);
					thestack.push(v);
				}
			}
			for(int j=0;j<vertexcount;j++)
				vertexlist[j].visited=false;
		}


		void adj()
		{
			for(int i=0;i<=vertexcount;i++){
				for(int j=0;j<=vertexcount;j++)
					cout<<adjmatrix[i][j]<<"  ";
				cout<<endl;
			}
					
		}
};

int main(){
	graph g;
	g.addvertex('a');
	g.addvertex('b');
	g.addvertex('c');
	g.addvertex('d');
	g.addvertex('e');
	g.addvertex('f');
	g.addvertex('g');
	g.addvertex('h');
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(1,4);
	g.addedge(2,5);
	g.addedge(5,6);
	g.addedge(6,7);	
	g.addedge(6,8);
	g.dfs();
	return 0;
}

