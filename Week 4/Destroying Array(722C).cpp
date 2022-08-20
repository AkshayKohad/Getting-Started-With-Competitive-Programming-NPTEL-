#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll find(ll i,vector<ll>&parent)
{
    if(parent[i]==-1)
    return i;
    
    
    return parent[i] = find(parent[i],parent);
}



void unite(ll i,ll j,vector<ll>&parent,vector<ll>&rank)
{
    ll n1 = find(i,parent);
    
    ll n2 = find(j,parent);
    
    if(n1!=n2)
   {    
    if(rank[n1] > rank[n2])
    {
        rank[n1] += rank[n2];
        
        parent[n2] = n1;
    }
    
    else{
        rank[n2] += rank[n1];
        
        parent[n1] = n2;
    }
    
   }
}


int main() {
    
  ll n;
  cin>>n;
  
  vector<ll>a(n);
  vector<ll>sequence(n);
  
  
  for(ll i=0;i<n;i++)
  {
    cin>>a[i];    
  }
  
  for(ll i=0;i<n;i++)
  {
      cin>>sequence[i];
  }
  
  reverse(sequence.begin(),sequence.end());
  
  vector<ll>parent(n,-1);
  
  vector<ll>rank(n);
  
  for(ll i=0;i<n;i++)
  {
      rank[i] = a[i];
  }
  
  vector<int>state(n,0);
  
  vector<ll>res;
  res.push_back(0);
  ll maxi = 0;
  for(ll i=0;i<sequence.size();i++)
  {
      ll index = sequence[i]-1;
      state[index] = 1;
      
      
      if(index-1>=0 && state[index-1])
      {
          unite(index-1,index,parent,rank);
          
      }
      
      if(index+1<n && state[index+1])
      {
          unite(index+1,index,parent,rank);

      }
      
      ll p = find(index,parent);

      maxi = max(rank[p],maxi);
      
      
      res.push_back(maxi);
      
  }
  
 reverse(res.begin(),res.end());
 for(ll i=1;i<res.size();i++)
 {
     cout<<res[i]<<endl;
 }
 
	return 0;
}
