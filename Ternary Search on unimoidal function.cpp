#include<bits/stdc++.h>
using namespace std;

double Function(double x){
	return // given function
}

double ternarySearch(double left,double right,double epsilon){
	while(right-left>epsilon){
		double mid1=left+(right-left)/3.0;
		double mid2=right-(right-left)/3.0;

		double f_mid1= Function(mid1);
		double f_mid2= Function(mid2);

		if(f_mid1<f_mid2){
			right=mid2;
		}
		else{
			left=mid1;
		}
	}
	return (left+right)/2.0;
}

int main()
{
	double left=0.0;
	double right=100.0;
	double epsilon = 0.000001; // for error less than 10^-6
	double minima = ternarySearch(left,right,epsilon);
}