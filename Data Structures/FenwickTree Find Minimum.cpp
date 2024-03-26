#include<bits/stdc++.h>
using namespace std;

int ara[100005];
int tree[100005];

const int INF = 1e9+7;

int query(int idx){
	int sum=INF;
	while(idx > 0){
		sum= min(sum,tree[idx]);
		idx -= (idx & -idx);
	}
	return sum;
}

void updateAdd(int idx,int val, int n){
	// this function add a value to an index
	//ara[idx]+= val;  // updating the value in original array
	while(idx<=n){
		tree[idx] = min(tree[idx],val);
		idx += (idx & -idx);
	}
}

void updateChange(int idx,int val, int n){
	// this function changes the value of an index
	int tmp=idx;
	while(idx<=n){
		//cout << val-ara[tmp] << endl;
		tree[idx] += val-ara[tmp];
		idx += (idx & -idx);
	}
	ara[tmp]=val;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		tree[i]=INF;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		ara[i]=x;
		updateAdd(i,x,n);
	}
	cout << "Original Arrya: " << endl;
	for(int i=1;i<=n;i++) cout << ara[i] << " ";
	cout << query(5) << endl;
	cout << endl;
}