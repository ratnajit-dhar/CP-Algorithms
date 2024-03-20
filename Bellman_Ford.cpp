#include<bits/stdc++.h>
using namespace std;

#define printarray(array,n) for(int a=0;a<n;a++) cout << array[a] << " "; cout << endl;

const int N = 1e5+10;
const int INF = 1e9+10;

// shobgulo edge pass korabo

vector <pair <int,int> > g[N];
vector <int> dist(N,INF);
void bellman_ford(int src,int n){
	dist[src] = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			for(auto it:g[j]){
				//cout << dist[it.first] << " " << dist[j]+it.second
				dist[it.first] = min(dist[it.first],dist[j]+it.second);
			}
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin >> u >> v >> wt;
		g[u].push_back({v,wt});
	}
	bellman_ford(0,n);
	printarray(dist,n);
}