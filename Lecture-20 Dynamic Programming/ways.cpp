#include<iostream>
using namespace std;

int ways(int n,int k,int *dp){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	if(dp[n]!=-1){
		return dp[n];
	}
	int ans = 0;
	for(int j=1;j<=k;j++){
		ans += ways(n-j,k,dp);
	}
	dp[n] = ans;
	return dp[n];
}



int bottomUp(int n,int k){
	int *dp = new int[n+1];

	dp[0] = 1;
	dp[1] = 1;

	for(int i=2;i<=n;i++){

			/*
			int subtract =  (i-k-1>=0)? dp[i-(k+1)]: 0 ;
			dp[i] = 2*dp[i-1] - subtract;	
			*/
			int ans = 0;
			for(int j=1;j<=k;j++){
				if(i-j>=0){
					ans += dp[i-j];
				}
			}
			dp[i] = ans;
	}

	for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	return dp[n];
}




int main(){
	int dp[100];
	int n = 100;
	
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}

	bottomUp(5,3);

	return 0;
}