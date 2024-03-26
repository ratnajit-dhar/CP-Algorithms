#include<bits/stdc++.h>
using namespace std;

#define life challenging
#define failure keep trying

#define endl "\n"
#define ifworking(n) cout << "working at" << n << endl;
#define printarray(array,n) for(int a=0;a<n;a++) cout << array[a] << " "; cout << endl;
#define int long long

bool vis[100000];

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

vector <int> g[100000];

void resetvect()
{
	for(int i=0;i<100000;i++){
		g[i].clear();
	}
}

void dfs(int v)
{
	if(vis[v]==true) return;
	vis[v]=true;
	for(auto it:g[v]){
		dfs(it);
	}
}

int find(int v,int par[])
{
	if(par[v]==v) return par[v];
	return par[v]=find(par[v],par);
}

void unionset(int a,int b,int par[])
{
	a=find(a,par);
	b=find(b,par);
	if(a!=b){
		par[b]=a;
	}
}

void solve()
{
	memset(vis,false,100000);
	resetvect();
	vector <pair <int,pair <int,int>>> edges;
	int n;
	cin >> n;
	int ara[n][n];
	int tot=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin >> x;
			tot=tot+x;
			if(x!=0) edges.push_back({x,{i,j}});
			if(x!=0) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(vis[i]==false) {
			//cout << i <<  endl;
			dfs(i);
			cnt++;
		}
	}
	sort(edges.begin(),edges.end());
	int par[n];
	for(int i=0;i<n;i++){
		par[i]=i;
	}
	int cost=0;
	for(auto it:edges){
		int wt=it.first;
		int a=it.second.first;
		int b=it.second.second;
		if(find(a,par)==find(b,par)) continue;
		//if(wt==0) continue;
		unionset(a,b,par);
		cost=cost+wt;
	}
	if(cnt==1) cout << tot-cost << endl;
	else cout << -1 << endl;


}
int32_t main()
{
	fastIO();
	int t;
	cin >> t;
	int tc=1;
	while(t--){
		cout << "Case " << tc << ": ";
		solve();
		tc++;
	}
	return 0;
}