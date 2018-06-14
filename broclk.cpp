//Author: yvdyash

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define ms(a, n) memset(a,n,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define prec(n) fixed<<setprecision(n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(x) x.begin(),x.end()
const int MOD=(int)1e9+7;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ull ipow(ull base,int exp){ull res=1ULL;while(exp){if(exp&1){res*=(ull)base;}exp>>=1;base*=base;}return res;}
ll fpow(ll x,ll y,ll p){ll res=1;while(y){if(y&1)res=res*x;res%=p;y=y>>1;x=x*x;x%=p;}return res;}
ll inv(ll a,ll p=MOD){return fpow(a,p-2,p);}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}

void multiply(ll F[2][2], ll M[2][2])
{
	ll x =  ((((F[0][0]%MOD)*(M[0][0]%MOD))%MOD)%MOD + (((F[0][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD)%MOD;x=(x+MOD)%MOD;
	ll y =  ((((F[0][0]%MOD)*(M[0][1]%MOD))%MOD)%MOD + (((F[0][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD)%MOD;y=(y+MOD)%MOD;
	ll z =  ((((F[1][0]%MOD)*(M[0][0]%MOD))%MOD)%MOD + (((F[1][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD)%MOD;z=(z+MOD)%MOD;
	ll w =  ((((F[1][0]%MOD)*(M[0][1]%MOD))%MOD)%MOD + (((F[1][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD)%MOD;w=(w+MOD)%MOD;
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(ll F[2][2], ll n,ll x)
{
	if( n == 0 || n == 1)
	return;
	ll M[2][2] = {{((2%MOD)*(x%MOD))%MOD,-1},{1,0}};
	
	power(F, n/2, x);
	multiply(F, F);
	
	if (n%2 != 0)
	multiply(F, M);
}

ll cosnth(ll n,ll x)
{
	ll F[2][2] = {{((2%MOD)*(x%MOD))%MOD,-1},{1,0}};
	if (n == 1)
	return x;
	power(F,n-1,x);
	return ((((F[0][0]%MOD)*(x%MOD))%MOD)%MOD + F[0][1]%MOD)%MOD;
}
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;cin>>tc;
	while(tc--)
	{
		ll l,d,t;
		cin>>l>>d>>t;
		ll x=(d+MOD)%MOD;
		x=((x%MOD)*(inv(l,MOD)%MOD))%MOD;
		ll ans=(cosnth(t,x)+MOD)%MOD;
		ans=((ans%MOD) * (l%MOD))%MOD;			
		cout<<ans<<"\n";
	}
}
