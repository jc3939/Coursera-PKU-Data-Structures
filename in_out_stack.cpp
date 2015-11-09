#include <iostream>

using namespace std;

long long int fact(int n){
	if(n==0){
		return 1;
	}
	return n*fact(n-1); 
}

long long int comb(int n, int r){
	if(n==r) return 1;
	if(r==0&&n!=0) return 1;
	return fact(n)/(fact(n-r)*fact(r));
}

int main(){
	int n;
	cin >> n;

	long long int count;

	count = comb(2*n, n) - comb(2*n, n-1);

	cout<< fact(2*n)<<endl;

	printf("%lld\n",count);
	return 0;
}