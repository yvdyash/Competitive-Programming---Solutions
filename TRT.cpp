// Author : yvdyash
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,a[2001];
int dp[2001][2001];

int foo(int st,int en,int age){
	if(dp[st][en]) return dp[st][en];
	if(st>en) return 0;
	int x = max(((a[st])*(age+1))+foo(st+1,en,age+1),((a[en])*(age+1))+foo(st,en-1,age+1));
	dp[st][en]=x;
	return x;
}

int32_t main()
{
	cin>>n;
	FOR(i,0,n) cin>>a[i];
	FOR(i,0,n) FOR(j,0,n) dp[i][j]=0;
	cout<<foo(0,n-1,0);
}
