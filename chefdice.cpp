// Author: yvdyash

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define ms(a, n) memset(a,n,sizeof(a))
#define pb push_back
#define mp make_pair
#define f first
#define se second
const int MOD=(int)1e9+7;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ull ipow(ull base,int exp){ull res=1ULL;while(exp){if(exp&1){res*=(ull)base;}exp>>=1;base*=base;}return res;}
ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll fapow(ll n,ll k,ll p = MOD){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%p;n=n*n%p;}return r;}
ll inv(ll a,ll p=MOD){return fapow(a,p-2,p);}
ll Sqrt(ll x){if(x==0 || x==1)return x;ll start=1,end=x,ans;while(start<=end){ll mid=(start+end)/2;if(mid*mid==x)return mid;if(mid*mid<x){start=mid+1;ans=mid;}else end=mid-1;}return ans;}
ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b; b=r;} return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--)
	{
		set <int> aa[7];
		int n;
		cin>>n;
		int a[505];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		aa[a[0]].insert(a[1]);
		aa[a[n-1]].insert(a[n-2]);
		if(a[0]==a[1]||a[n-1]==a[n-2])
		{
			cout<<"-1\n";
			continue;
		}
		int red=0,flag;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==a[i-1]||a[i]==a[i+1])
			{
				red=1;
				break;
			}
			aa[a[i]].insert(a[i-1]);
			aa[a[i]].insert(a[i+1]);
		}
		if(red)
		{
			cout<<"-1\n";
			continue;
		}
		vector <int> aaa;
		
		for(int i=1;i<=6;i++)
		aaa.pb(i);

		do{
			flag=0;
			for(int i=1;i<7;i++)
			{
				if(aa[i].count(aaa[i-1])>0||aaa[i-1]==i||i!=aaa[aaa[i-1]-1])
				{
					flag=0;
					break;
				}
				else
				flag=1;
			}
			if(flag)
			break;
		}while(next_permutation(aaa.begin(), aaa.end()));
		
		if(flag)
		{
			for(int i=0;i<6;i++)
			cout<<aaa[i]<<" ";	
			cout<<"\n";
		}
		else
		cout<<"-1\n";
	}
}
