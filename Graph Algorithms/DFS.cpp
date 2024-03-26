#include<bits/stdc++.h>
using namespace std;

void dfs(vector <int> g[],int node,bool vis[])
{
	//if(vis[node]==true) return;
	vis[node]=true;
	for(auto it:g[node]){
		cout << node << " " << it << endl;
		if(vis[it]) continue;
		dfs(g,it,vis);
	}
}

int main()
{
	int edge,vtx;
	cin >> edge >> vtx;
	vector <int> g[vtx+1];
	bool vis[vtx+1]={false};
	for(int i=1;i<=edge;i++){
		int v1,v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}	
	dfs(g,1,vis);
	return 0;
}