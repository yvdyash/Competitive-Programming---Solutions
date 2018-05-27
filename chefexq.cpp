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
ll fpow(ll x,ll y,ll p){ll res=1;while(y){if(y&1)res=res*x;res%=p;y=y>>1;x=x*x;x%=p;}return res;}
ll inv(ll a,ll p=MOD){return fpow(a,p-2,p);}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}

int prexor[100005],a[100005];
int cnt[1000002][400],lazy[400]={0};
int n,q,bucks,bs;

void build()
{
	ms(cnt,0);
	
	bs=floor(sqrt(n));
	if(bs*bs==n)
	bucks=bs;
	else
	bucks=bs+1;
	
	prexor[0]=a[0];
	for(int i=1;i<n;i++)
	prexor[i]=prexor[i-1]^a[i];
	
	int bi=-1;
	for(int i=0;i<n;i++)
	{
		if(i%bs==0)bi++;
		cnt[prexor[i]][bi]++;	
	}
}

void update(int ind,int val)
{
	int temp=a[ind];
	a[ind]=val;
	int ii=ind/bs;
	
	for(int j=ind;j<(ii+1)*bs;j++)
	{
		cnt[prexor[j]][ii]--;
		prexor[j]^=val^temp;
		cnt[prexor[j]][ii]++;
	}

	for(int j=ii+1;j<bucks;j++)
	lazy[j]^=temp^val;	
}

int query(int ind,int k)
{
	int ii=ind/bs;
	int ans=0;
	
	for(int j=0;j<ii;j++)
	ans+=cnt[lazy[j]^k][j];
	
	for(int j=bs*(ii);j<=ind;j++)
	if(prexor[j]==(lazy[ii]^k))ans++;
	
	return ans;
}

void solvebrute()
{
	while(q--)
	{
		int t;cin>>t;
		int f=0;
		if(t==1){
			int i,x;
			cin>>i>>x;
			i--;
			a[i]=x;
			if(i==0){
				prexor[0]=a[0];
				for(int j=1;j<n;j++)
				prexor[j]=prexor[j-1]^a[j];	
			}
			else
			for(int j=i;j<n;j++)
			prexor[j]=prexor[j-1]^a[j];		
		}
		else
		{
			int i,k;
			cin>>i>>k;	
			ll ans=0;
			for(int j=0;j<i;j++)
			if(prexor[j]==k)ans++;
			cout<<ans<<"\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	
	build();
	if(n<=1000&&q<=1000)
	solvebrute();
	else
	while(q--)
	{
		int t;cin>>t;
		if(t==1)
		{
			int i,x;
			cin>>i>>x;
			update(i-1,x);
		}
		else
		{
			int i,k;
			cin>>i>>k;
			cout<<query(i-1,k)<<"\n";
		}
	}	 
}

