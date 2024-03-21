#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector <int> g[n];
	int indeg[n]={0};
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		indeg[v]++;
	}
	queue <int> q;
	for(int i=0;i<n;i++){
		if(indeg[i]==0) {
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		cout << x << endl;
		q.pop();
		for(auto it:g[x]){
			indeg[it]--;
			if(indeg[it]==0){
				q.push(it);
			}
		}
	}
}