#include<bits/stdc++.h>
using namespace std;

#define mx 100006
int ara[mx];
int tree[mx*4];

void build(int node,int beg,int end)
{

	if(beg==end){
		tree[node] = ara[beg];
		return;
	}	
	int left=2*node;
	int right=2*node+1;
	int mid=(beg+end)/2;
	build(left,beg,mid);
	build(right,mid+1,end);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int beg, int end, int i, int j)
{
	// node is the current node, beg and end are the range of the node
	// i and j are the range of query
	if( i > end || j < beg ) {
		return 0;
	}
	if( i <= beg && j >= end){
		return tree[node];
	}
	int left = node*2;
	int right = node*2+1;
	int mid = (beg + end)/2;
	int q1 = query(left,beg,mid,i,j);
	int q2 = query(right,mid+1,end, i, j);
	return q1+q2;
}

void update(int node, int beg, int end, int i, int newvalue)
{
	// node is the current node, beg and end are the range of the node
	// i is the index to be updated
	if( i > end || i < beg ) {
		return;
	}
	if( i == beg && i == end){
		tree[node] = newvalue;
		return;
	}
	int left = node*2;
	int right = node*2+1;
	int mid = (beg + end)/2;
	update(left, beg, mid, i, newvalue);
	update(right, mid+1, end, i, newvalue);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	
}