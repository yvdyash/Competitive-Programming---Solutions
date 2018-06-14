// Author: yvdyash

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,k,a[100],ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	ll k1=1,f1=0,k2=1,f2=0;
	ll x[50000],y[50000];
	x[0]=1;y[0]=1;
	for (int i=0; i<(1<<n/2); i++)
	{
	    ll s = 1;
	    for (int j=0; j<n/2; j++)
	    {
	        if (i & (1<<j))
	        {
				if((log(s)+log(a[j]))<=log(pow(10,18)))
	           	{
					s *= a[j];
					f1=1;
				}
	           	else 
				{
					f1=0;
					break;
				}
        	}
        }
	    if(f1)
		{
			x[k1]=s; 
			k1++;
		}
	}
	    
    for (int i=0; i<(1<<(n-n/2)); i++)
    {
        ll s = 1;
        for (int j=0; j<(n-n/2); j++)
		{
            if (i & (1<<j))
            {
				if((log(s)+log(a[j+n/2]))<=log(pow(10,18)))
				{
                	s *= a[j+n/2];
					f2=1;
                }
				else
				{
					f2=0;
					break;
				}
			}
		}
        if(f2)        
        {
			y[k2] =s ;
			k2++;
		}
    }
	
	ll sizex=k1;
	ll sizey=k2;
	
	sort(y,y+sizey);
	ll p,z;
	
	for(int i=0;i<sizex;i++)
	{
		if(x[i]<=k)
		{
			p = lower_bound(y, y+sizey,k/x[i])- y ;
			z=p+1;
			while(y[z]==k/x[i])
			{
				p=z;
				z++;
			}
			
			if (p == sizey || y[p] != (k/x[i]))
	    	p--;
	    	
	    	p++;
		}
		else p=0;
	
		ans+=p;
	}
	cout<<ans-1<<"\n";
} 
