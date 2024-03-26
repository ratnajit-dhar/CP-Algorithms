#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

bool vis[N];
vector <int> g[N];

vector <int> temp;

void dfs(int vertex){
	if(vis[vertex]) return;
	temp.push_back(vertex);
	vis[vertex]=true;
	for(int child:g[vertex]){
		dfs(child);
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
	vector <vector <int> > comp;
	for(int i=1;i<=node;i++){
		if(vis[i]==true) continue;
		dfs(i);
		cnt++;
		comp.push_back(temp);
		temp.clear();
	}
	for(auto it:comp){
		for(auto x:it){
			cout << x << " ";
		}
		cout << endl;
	}
	cout << cnt << endl;
}