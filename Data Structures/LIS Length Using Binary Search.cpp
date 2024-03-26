#include<bits/stdc++.h>
using namespace std;

#define life challenging
#define failure keep trying

#define endl "\n"
#define ifworking(n) cout << "working at" << n << endl;
#define printarray(array,n) for(int a=0;a<n;a++) cout << array[a] << " "; cout << endl;
#define int long long

const int N = 1e5+9;
const int MOD = 1e9+7;

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve()
{
	int n;
	cin >> n;
	int ara[n];
	for(int i=0;i<n;i++){
		cin >> ara[i];
	}
	vector <int> LIS;
	LIS.push_back(ara[0]);
	for(int i=1;i<n;i++){
		if(ara[i] > LIS.back()){
			LIS.push_back(ara[i]);
		}
		else{
			int ind = lower_bound(LIS.begin(), LIS.end(),ara[i]) - LIS.begin();
			// If i want to find Longest Non Decreasing, then use upper bound;
			LIS[ind] = ara[i];
		}
	}
	cout << LIS.size() << endl;
}

int32_t main()
{
	fastIO();
	solve();
	return 0;
}