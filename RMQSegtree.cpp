// Author: yvdyash

#include <bits/stdc++.h>
using namespace std;

int A[100002];    // Input Array  			
int tree[2000001];// Array which stores all the nodes of the Segment Tree

void buildST(int node, int start, int end) // start,end - starting and ending index of the array
{
    if(start == end)
    tree[node] = A[start];
    
    else
    {
        int mid = (start + end) / 2;
        //  2*node will represent the left node and 2*node + 1 will represent the right node  
        buildST(2*node, start, mid);
        buildST(2*node+1, mid+1, end);
        // Internal node will have the minimum of both of its children after merging
        tree[node] = min(tree[2*node] , tree[2*node+1]);
    }
} 

int query(int node, int start, int end, int L, int R)
{
    if(R < start || end < L)
    return 100002;

    if(L <= start && end <= R)
    return tree[node]; //Required condition
    
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, L, R);
    int p2 = query(2*node+1, mid+1, end, L, R);
    return (min(p1,p2)); //After merging of segments
}

 
int main()
{
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	cin>>A[i];
	
	buildST(1,1,n);
	
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		
		cout<<query( 1 , 1 , n , l , r )<<"\n";
	}
	return 0;
}
