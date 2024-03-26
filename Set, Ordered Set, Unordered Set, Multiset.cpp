#include<bits/stdc++.h>
using namespace std;

int main()
{
	set <string> s;
	// insertion in log(n)
	s.insert("abc");
	s.insert("asfaf");
	s.insert("afafa");
	//unordered_set
	unordered_set <string> s1;
	s1.insert("abc");
	s1.insert("asfaf");
	s1.insert("afafa");
	auto it = s1.find("abc");
	if(it==s1.end()){
		cout << "Not found" << endl;
	}
	else{
		cout << *it << endl;
	}
	// multiset
	multiset<string> s2;
	s2.insert("abc");
	// Takes multiple value
	// iterator finds the first occurence 
	// s.erase() deletes every occurence
}