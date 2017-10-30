#include<iostream>
using namespace std;

int fib(int n,int *dp){
	if(n==0||n==1){
		return n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n] = fib(n-1,dp) + fib(n-2,dp);
	return dp[n];
}

int bottomUp(int n){
	int *dp = new int[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}




int main(){
	int dp[100];
	int n;
	cin>>n;
	
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}

	cout<<fib(n,dp)<<endl;

	return 0;
}