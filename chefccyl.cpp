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
ll fapow(ll n,ll k,ll p=MOD){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%p;n=n*n%p;}return r;}
ll inv(ll a,ll p=MOD){return fapow(a,p-2,p);}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;cin>>tc;
	while(tc--)
	{
		vector<vector<ll> > pfs(100005);
		vector<ll > cycles(100005);
		vector<ll > ete(100005);
		vector<ll > ent(100005);
		vector<ll > exi(100005);
		ll non[100005]={0};
		
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++)
		{
			cin>>non[i];
			int x;cin>>x;pfs[i].pb(x);
			for(int j=1;j<non[i];j++)
			{
				ll y;
				cin>>y;
				pfs[i].pb(y);
				pfs[i][j]+=pfs[i][j-1];
			} 
		}
		//Cycles
		cin>>ent[0]>>exi[1]>>cycles[0];
		for(int i=1;i<n;i++)
		{
			ll x,y,w;
			cin>>x>>y>>w;
			ent[i]=x;
			if(i==n-1)
			exi[0]=y;
			else
			exi[i+1]=y;
			cycles[i]=w;
			cycles[i]+=cycles[i-1];
		}
		//ETE
		for(int i=0;i<n;i++)
		{
			ll x;
			if(ent[i]==1&&exi[i]!=1)
			x=pfs[i][exi[i]-2];
			else if(exi[i]==1&&ent[i]!=1)
			x=pfs[i][ent[i]-2];
			else if(ent[i]==exi[i])
			x=0;
			else
			x=abs((pfs[i][ent[i]-2]-pfs[i][exi[i]-2]));
			x=min((pfs[i][non[i]-1]-x),x);
			ete[i]=x;
		}
		//ETEPRESUM
		for(int i=1;i<n;i++)
		ete[i]+=ete[i-1];
		
		//QUERIES
		while(q--)
		{
			ll v1,c1,v2,c2;
			cin>>v1>>c1>>v2>>c2;
			ll x=0,y=0,w=0,z=0,x1=0,y1=0,w1=0,z1=0,z2=0,w2=0,z3=0,w3=0;
			if(c2<c1)
			{
				swap(c1,c2);
			swap(v1,v2);
			}
			
			
			ll ans1=0,ans2=0;
			if(c1==1)
			x=cycles[c2-2];
			else
			x=cycles[c2-2]-cycles[c1-2];
			y=ete[c2-2]-ete[c1-1];
			if(v1==1){
				if(ent[c1-1]==1)w=0;
				else w=pfs[c1-1][ent[c1-1]-2];
			}
			else{
				if(ent[c1-1]==1)w=pfs[c1-1][v1-2];
				else w=abs(pfs[c1-1][v1-2]-pfs[c1-1][ent[c1-1]-2]);
			}
			w3=min(w,(pfs[c1-1][non[c1-1]-1]-w));
			if(v2==1){
				if(exi[c2-1]==1)z=0;
				else z=pfs[c2-1][exi[c2-1]-2];	
			}
			else{
				if(exi[c2-1]==1)z=pfs[c2-1][v2-2];
				else z=abs(pfs[c2-1][v2-2]-pfs[c2-1][exi[c2-1]-2]);
			}	
			z3=min(z,(pfs[c2-1][non[c2-1]-1]-z));
			ans1=(x+y+z3+w3);
			
			
			x1=(cycles[n-1]-x);	
			if(c1==1)
			y1=(ete[n-1]-y-(ete[c1-1])-(ete[c2-1]-ete[c2-2]));	
			else
			y1=(ete[n-1]-y-(ete[c1-1]-ete[c1-2])-(ete[c2-1]-ete[c2-2]));	
			if(v1==1){
				if(exi[c1-1]==1)w1=0;
				else w1=pfs[c1-1][exi[c1-1]-2];
			}
			else{
				if(exi[c1-1]==1)w1=pfs[c1-1][v1-2];
				else w1=abs(pfs[c1-1][v1-2]-pfs[c1-1][exi[c1-1]-2]);
			}
			w2=min(w1,(pfs[c1-1][non[c1-1]-1]-w1));
			if(v2==1){
				if(ent[c2-1]==1)z1=0;
				else z1=pfs[c2-1][ent[c2-1]-2];	
			}
			else{
				if(ent[c2-1]==1)z1=pfs[c2-1][v2-2];
				else z1=abs(pfs[c2-1][v2-2]-pfs[c2-1][ent[c2-1]-2]);
			}
			z2=min(z1,(pfs[c2-1][non[c2-1]-1]-z1));
			ans2=x1+y1+z2+w2;
			ll ans=min(ans1,ans2);
			cout<<ans<<"\n";	
		}
	}
}

