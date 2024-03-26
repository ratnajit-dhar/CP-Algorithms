#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// less<int> for ascending order
// greater<int> for descending order
// less_equal<int> for multiset ascending

int main()
{
	pbds A; // declaration

	A.insert(1); // insertion
	cout << *A.find_by_order(2) << endl; // Element at 2nd index
	cout << A.order_of_key(6) << endl; // Number of element smaller than 6
	cout << *A.lower_bound(6) << endl;
	cout << *A.upper_bound(6) << endl;
	A.erase(5);
}