// Author : yvdyash
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define ms(a, n) memset(a,n,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
const int MOD=(int)1e9+7;
const int N=1e6+5;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ull ipow(ull base,int exp){ull res=1ULL;while(exp){if(exp&1){res*=(ull)base;}exp>>=1;base*=base;}return res;}
ll fpow(ll x,ll y,ll p){ll res=1;while(y){if(y&1)res=res*x;res%=p;y=y>>1;x=x*x;x%=p;}return res;}
ll inv(ll a,ll p=MOD){return fpow(a,p-2,p);}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}

vector<vector<int> > g(N);
vector <bool> vis(N);
vector< int> color(N,-1);

bool bfs(int node){
	queue<int> q;
	q.push(node);
	color[node]=1;
	while(!q.empty()){
		int parent=q.front();
		q.pop();
		vis[parent]=true;
		for(int i=0;i<g[parent].size();i++){
			int child=g[parent][i];
			if(!vis[child]){
				q.push(child);
				
			}
			if(color[child]==-1)
				color[child]=!color[parent];
			else if(color[child]==color[parent]){
				return false;
			}
		}
	}
	return true;
}

int main()
{	
	int tc,t=0;cin>>tc;
	while(tc--){
		t++;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			color[i]=-1;
			vis[i]=false;
			g[i].clear();
		}
				
		FOR(i,0,m){
			int x,y;
			cin>>x>>y;
			g[x].pb(y);
			g[y].pb(x);
		}
		cout<<"Scenario #"<<t<<":\n";
		int f=0;
		FOR(i,1,n){
			if(!vis[i]){
				if(!bfs(i))
				{
					cout<<"Suspicious bugs found!\n";
					f=1;
					break;
				}
			}
		}
		if(!f){
			cout<<"No suspicious bugs found!\n";
		}
	}
}
