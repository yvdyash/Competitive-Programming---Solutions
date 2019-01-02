// Author : yvdyash

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int> > gr(10005);
vector<bool> vis(10005);
vector<int> dist(10005,999999);
 
void bfs(int node)
{
	queue<int> q;
	q.push(node);
	vis[node]=true;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(int i=0;i<gr[curr].size();i++)
		{
			int cur_child=gr[curr][i];
			dist[cur_child]=min(dist[curr]+1,dist[cur_child]);
			if(!vis[gr[curr][i]])
			{
				q.push(gr[curr][i]);
				vis[gr[curr][i]]=true;
			}
		}
	}
}
 
int main()
{
	int tc;cin>>tc;
	while(tc--)
	{
		int v;
		cin>>v;
		int edges;
		cin>>edges;
		while(edges--)
		{
			int x,y;
			cin>>x>>y;
			gr[x].push_back(y);
			gr[y].push_back(x);
		}
		dist[1]=0;
		bfs(1);
		cout<<dist[v]<<"\n";
		
		for(int i=1;i<=v;i++)
			gr[i].clear();
		for(int i=0;i<10005;i++){
			dist[i]=999999;
			vis[i]=0;
		}
	}
}
