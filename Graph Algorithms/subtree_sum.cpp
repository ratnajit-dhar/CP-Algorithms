#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> g[N];
int subtree_sum[N];

dfs(int vertex,int parent)
{
	subtree_sum[vertex]=vertex;
	for(int child:g[vertex]){
		if(child==parent) continue;
		dfs(child,vertex);
		subtree_sum[vertex]+=subtree_sum[child];
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
	for(int i=1;i<=n;i++){
		cout <<  i << " " << subtree_sum[i] << endl;
	}
}