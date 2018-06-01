// Author: yvdyash
// Segment Tree Implementation

#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 1000005
#define INF 99999999
 
int spf[MAXN];
int a[MAXN];

vector<vector<int> > primefactors(1000006);
vector<vector<int> > segmentTree(4000006);
 

void findSmallestPrimeFactors()
{
    spf[1]=1;
    for (int i=2;i<MAXN;i++)
        spf[i]=i;
  
    for (int i=4;i<MAXN;i+=2)
        spf[i]=2;

    for (int i=3;i*i<MAXN;i++)
    {        
        if (spf[i]==i)
        {    
            for (int j=i*i;j<MAXN;j+=i)
               	if (spf[j]==j)
                    spf[j]=i;
        }
    }
}
 
 
void buildDivisorsArray(int a[],int n)
{
    for (int i=1;i<n+1;i++)
    {
        int ni=i,p=spf[a[i]];
        
        while (a[ni]>1)
        {
            primefactors[i].push_back(p);
            a[ni]=a[ni]/p;
            p=spf[a[ni]];
        }
    }
}


void buildSegtmentTree(int node,int a,int b)
{
    if (a==b)
    {
	for(int i=0;i<primefactors[a].size();i++)
        segmentTree[node].push_back(primefactors[a][i]);
        return ;
    }
    
    buildSegtmentTree(2*node,a,(a+b)/2);
    buildSegtmentTree(2*node+1,((a+b)/2)+1,b);
 
    
    for(int i=0;i<segmentTree[2*node].size();i++)
    segmentTree[node].push_back(segmentTree[2*node][i]);
    for(int i=0;i<segmentTree[2*node+1].size();i++)
    segmentTree[node].push_back(segmentTree[2*node+1][i]);
    
    
    sort(segmentTree[node].begin(),segmentTree[node].end());
}


int query(int a[],int node,int c,int d,int l,int r,int x,int y,int ans)
{

    if (l>d||c>r)
   	return 0;
	
    
    if (c>=l&&d<=r)
    {
    	int x1=lower_bound(segmentTree[node].begin(),segmentTree[node].end(),x)- segmentTree[node].begin();
    	int y1=upper_bound(segmentTree[node].begin(),segmentTree[node].end(),y)- segmentTree[node].begin();
    	
    	ans+=y1-x1;
    	
        return ans ;
    }
    
    return (query(a,2*node,c,(c+d)/2,l,r,x,y,ans)+query(a,2*node+1,((c+d)/2)+1,d,l,r,x,y,ans));
}
 

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    findSmallestPrimeFactors();
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++)
    cin>>a[i];
	
    buildDivisorsArray(a,n);
    buildSegtmentTree(1, 1,n);
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
	    int l,r,x,y;
	    cin>>l>>r>>x>>y;
	    cout<<query(a,1,1,n,l,r,x,y,0)<<"\n";
    }
}
