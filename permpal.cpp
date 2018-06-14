// Author: yvdyash

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
const int MOD=(int)1e9+7;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ull ipow(ull base,int exp){ull res=1ULL;while(exp){if(exp&1){res*=(ull)base;}exp>>=1;base*=base;}return res;}
ll fpow(ll x,ll y,ll p){ll res=1;while(y){if(y&1)res=res*x;res%=p;y=y>>1;x=x*x;x%=p;}return res;}
ll inv(ll a,ll p=MOD){return fpow(a,p-2,p);}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		map <char,vector<int> > x;
		set <char> setc;
		int occ[26]={0},ans[s.length()],n=s.length();
		FOR(i,0,s.length())
		{
			occ[s[i]-'a']++;
			x[s[i]].pb(i+1);
			setc.insert(s[i]);
		}
		
		set<char> :: iterator it;
		if(s.length()%2==0)
		{
			int f=0;
			for(it=setc.begin();it!=setc.end();it++)
			{
				if(occ[*it-'a']%2==0)
				f=1;
				else
				{
					f=0;break;
				}
			}
			if(!f)
			cout<<"-1\n";
			else
			{
				int i=0;
				for(it=setc.begin();it!=setc.end();it++)
				{
					if(x[*it].size()>0)
					{
						for(int j=0;j<x[*it].size();j++)
						{
							if(j%2==0)
							ans[i]=x[*it][j];
							else
							ans[n-i-1]=x[*it][j];
							if(j>0&&j%2==1)
							i++;
						}
					}
				}
				FOR(i,0,n)
				cout<<ans[i]<<" ";
				cout<<"\n";
			}
		}
		else
		{
			int f1=0,f2=0;
			for(it=setc.begin();it!=setc.end();it++)
			{
				if(occ[*it-'a']%2==0)
				f2++;
				else
				f1++;
			}
			if(f1==1)
			{
				int mid=n/2;
				int i=0,k=0;
				for(it=setc.begin();it!=setc.end();it++)
				{
					if(x[*it].size()%2==1)
					{
						for(int j=0;j<x[*it].size();j++)
						{
							if(j%2==1)
							k++;
							if(j%2==0)
							ans[mid-k]=x[*it][j];
							else
							ans[mid+k]=x[*it][j];
						}
					}
					else
					{
						for(int j=0;j<x[*it].size();j++)
						{
							if(j%2==0)
							ans[i]=x[*it][j];
							else
							ans[n-i-1]=x[*it][j];
							if(j>0&&j%2==1)
							i++;
						}
					}
				}
				FOR(i,0,n)
				cout<<ans[i]<<" ";
				cout<<"\n";
			}
			else
			cout<<"-1\n";
		}
	}
}
