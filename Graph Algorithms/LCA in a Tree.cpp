#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector <int> g[N];
int parent[N];

void dfs(int vertex,int par){
	parent[vertex]=par;
	for(auto child:g[vertex]){
		if(child==par) continue;
		dfs(child,vertex);
	}
}

vector <int> path(int v){
	vector <int> ans;
	while(v!=0){
		ans.push_back(v);
		v=parent[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int node;
	cin >> node;
	for(int i=1;i<=node-1;i++){
		int vt1,vt2;
		cin >> vt1 >> vt2;
		g[vt1].push_back(vt2);
		g[vt2].push_back(vt1);
	}
	dfs(1,0);
	int v1,v2;
	cin >> v1 >> v2;
	// for(int i=1;i<=node;i++){
	// 	cout << i << " " << parent[i] << endl;
	// }
	vector <int> path1=path(v1);
	vector <int> path2=path(v2);
	int lca=-1;
	for(int i=0;i<min(path1.size(),path2.size());i++){
		if(path1[i]==path2[i]) lca=path1[i];
		else break;
	}
	cout << lca << endl;
}