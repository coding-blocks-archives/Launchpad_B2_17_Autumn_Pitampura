#include<iostream>
using namespace std;

int dp[100][100] = {0};

int wines(int *a,int i,int j,int day){
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}

	int op1 = wines(a,i+1,j,day+1) + day*a[i];
	int op2 = wines(a,i,j-1,day+1) + day*a[j];

	dp[i][j] = max(op1,op2);
	return dp[i][j];
}

int main(){

	int a[] = {2,3,5,1,4};
	int n = 5;

	cout<<wines(a,0,n-1,1);

	return 0;	
}