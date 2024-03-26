#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> node[1000];
	vector <int> path[1000];
	int edg;
	cin >> edg;
	while(edg--){
		int x,y;
		cin >> x >> y;
		node[x].push_back(y);
	}
	queue <int> q;
	int level[1000];
	memset(level,-1,1000);
	q.push(1);
	level[1]=0;
	while(q.size()!=0){
		int u=q.front();
		q.pop();
		for(int i=0;i<node[u].size();i++){
			if(level[node[u][i]]==-1) {
				level[node[u][i]]=level[u]+1;
				q.push(node[u][i]);
			}
		}
	}
	cout << level[5]  << endl;
	return 0;
}
