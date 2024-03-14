#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

bool vis[N];
vector <int> g[N];

vector <int> temp;

bool dfs(int vertex,int parent){
	vis[vertex]=true;
	bool isLoopExists=false;
	for(int child:g[vertex]){
		if(vis[child] && child==parent) continue;
		if(vis[child]) return true;
		isLoopExists |= dfs(child,vertex);
	} 
}

int main()
{
	int node,edge;
	cin >> node >> edge;
	for(int i=1;i<=edge;i++){
		int vtx1,vtx2;
		cin >> vtx1 >> vtx2;
		g[vtx1].push_back(vtx2);
		g[vtx2].push_back(vtx1);
	}
	int cnt=0; 
	bool isLoop=false;
	vector <vector <int> > comp;
	for(int i=1;i<=node;i++){
		if(vis[i]==true) continue;
		if(dfs(i,0)){
			isLoop=true;	
			break;
		}
	}
	if(isLoop) cout << "Cycle detected" << endl;
	else cout << "No cycle" << endl;
}
