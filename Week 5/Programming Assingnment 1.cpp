#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int>adj[n+1];
	
	vector<int>parent;
	for(int i=1;i<=n;i++)
	{
	    int val;
	    cin>>val;
	    if(val==-1)
	    parent.push_back(i);
	    
	    
	    else{
	        adj[val].push_back(i);
	    }
	    
	}
	
	int res = 0;
	
	vector<int>visited(n+1,0);
	for(int i=0;i<parent.size();i++)
	{
	  queue<pair<int,int>>q;
	  q.push({parent[i],1});
	  visited[parent[i]] = 1;
	  
	  while(q.empty()==false)
	  {
	      pair<int,int>cur = q.front();
	      q.pop();
	      int p = cur.first;
	      int moves = cur.second;
	      
	      res = max(moves,res);
	      
	      
	      for(auto u:adj[p])
	      {
	          if(visited[u]==0)
	          {
	              q.push({u,moves+1});
	              visited[u] = 1;
	          }
	      }
	  }
	  
	}
	
	cout<<res<<endl;
	
	return 0;
}
