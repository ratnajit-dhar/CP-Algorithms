// Explanation:
// Dfs from the starting node
// Depth will be considered right after entering a node
// Height will be considered after tracking back from all the child node

// Source Code:

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector <int> g[N];
int depth[N],height[N];

void dfs(int vertex,int parent){
	height[vertex]=vertex;
	for(int child:g[vertex]){
		if(child==parent) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
		height[vertex]=max(height[vertex],height[child]+1);
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
	dfs(1,0);

}
