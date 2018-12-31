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
bool pr[1000007];
const int MOD=(int)1e9+7;
int fpow(int x,int y,int p){int res=1;while(y){if(y&1)res=res*x;res%=p;y=y>>1;x=x*x;x%=p;}return res;}
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}

const int N=1e6+5;
int has[N];
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
