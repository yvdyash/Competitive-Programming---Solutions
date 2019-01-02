// Author : yvdyash
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define int long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vl  vector<ll>
#define vi  vector<int> 
#define sz(a) a.length()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define prec(n) fixed<<setprecision(n)
#define ms(a, n) memset(a, n , sizeof(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n,a[1001];
int dp[1001][1001];
vector<pair<int,int> > v;

int foo(int st,int en,int age){
	if(st>en) return 0;
	if(dp[st][en]!=-1) return dp[st][en];
	if(age&1){
		if(a[st]<a[en])
			return foo(st,en-1,age+1);	
		else
			return foo(st+1,en,age+1);
	}
	else{
		int x = max( a[st]+foo(st+1,en,age+1) , a[en]+foo(st,en-1,age+1) );
		dp[st][en]=x;
		v.pb({st,en});
		return x;
	}
}

int32_t main()
{
	fastio;
	int tc=1;
	ms(dp,-1);
	while(true){
		cin>>n;
		if(!n) 
			return 0;
		int sum=0;
		FOR(i,0,n) cin>>a[i];
		FOR(i,0,n) sum+=a[i];
		int ans=foo(0,n-1,0);
		cout<<"In game "<<tc<<", the greedy strategy might lose by as many as "<<ans-(sum-ans)<<" points."<<endl;
		
		FOR(i,0,v.size()) dp[v[i].fi][v[i].se]=-1;
		tc++;
	}
}
