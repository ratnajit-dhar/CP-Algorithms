// Explanation:

// First run a dfs from any node and find the maximum depth and the node
// Then run another dfs from that node and find the maximum depth

// Code:

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> g[N];
int depth[N];

dfs(int vertex,int parent=0)
{
	for(int child:g[vertex]){
		if(child==parent) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
	}
}

int32_t main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0); 
	int mx_depth=-1;
	int mx_node=-1;
	for(int i=1;i<=n;i++){
		if(mx_depth<depth[i]){
			mx_depth=depth[i];
			mx_node=i;
		}
	}
	for(int i=1;i<=N;i++){
		depth[i]=0;
	}
	dfs(mx_node);
	for(int i=1;i<=n;i++){
		if(mx_depth<depth[i]){
			mx_depth=depth[i];
		}
	}
	cout << mx_depth << endl;
}
