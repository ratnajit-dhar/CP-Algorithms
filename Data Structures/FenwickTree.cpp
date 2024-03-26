#include<bits/stdc++.h>
using namespace std;

int ara[100005];
int tree[100005];

int query(int idx){
	int sum=0;
	while(idx > 0){
		sum+= tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void updateAdd(int idx,int val, int n){
	// this function add a value to an index
	ara[idx]+= val;  // updating the value in original array
	while(idx<=n){
		tree[idx] += val;
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
		int x;
		cin >> x;
		updateAdd(i,x,n);
	}
	cout << "Original Arrya: " << endl;
	for(int i=1;i<=n;i++) cout << ara[i] << " ";
	cout << endl;
	cout << "Range Query 5 to 10:" << endl << query(10)-query(4) << endl;
	updateAdd(8,10,n);
	cout << "Array after adding 10 to index 8: " << endl;
	for(int i=1;i<=n;i++) cout << ara[i] << " ";
	cout << endl;
	cout << "Range Query after updating: " << endl << query(10)-query(4) << endl;
	updateChange(8,10,n);
	cout << "Array after changing value of index 8 to 10:" << endl;
	for(int i=1;i<=n;i++) cout << ara[i] << " ";
		cout << endl;
	cout << "Range Query after changing: " << endl << query(10)-query(4) << endl;	
}