// Author: yvdyash
// Binary Indexed Tree Implementation

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
ull ipow(ull base,int exp){ull res=1ULL;while(exp){if(exp&1){res*=(ull)base;}exp>>=1;base*=base;}return res;}
ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}

int arr[1000006]={0},dp[1000006]={0};
vector <int> t(1000006),l(1000005),r(1000005);


void updateBIT(ll BITree[], int n, int index, ll val)
{
    index = index + 1;
    
    while (index <= n)
    {
        BITree[index] =(BITree[index]%MOD + val%MOD)%MOD;
        BITree[index]%=MOD;
 
        index += index & (-index);
    }
}


ll *constructBITree(int arr[], int n)
{
    ll *BITree = new ll[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    return BITree;
}
 

ll getSum(ll BITree[], int index)
{
    ll sum = 0;
 
    index = index + 1;
 
    while (index>0)
    {
        sum =(sum%MOD + BITree[index]%MOD)%MOD;
        sum%=MOD;
 
        index -= index & (-index);
    }
    return sum;
}
 

void update(ll BITree[], int l, int r, int n, ll val)
{
    updateBIT(BITree, n, l, val%MOD);
 
    updateBIT(BITree, n, r+1, (-val+MOD)%MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		
		ms(dp,0);
		ms(arr,0);
		ll *BITree = constructBITree(arr,n);
		ll *dptree = constructBITree(dp,m);
		
		for(int i=0;i<m;i++)
		cin>>t[i]>>l[i]>>r[i];
		
		for(ll i=m-1;i>=0;i--)
		{
			if(t[i]==2)
			update(dptree, l[i]-1, r[i]-1, m, ((1+getSum(dptree,i))%MOD));	
		}
		
		for(int i=0;i<m;i++)
		{
			if(t[i]==1)
			update(BITree,l[i]-1,r[i]-1,n,getSum(dptree,i)+1);
		}
		
		for(int i=0;i<n;i++)
		cout<<getSum(BITree,i)<<" ";
		cout<<"\n";
	}
}
