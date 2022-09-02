Recall that a tree is a graph that has no cycles, and a rooted tree is a tree in which one vertex has been designated the root. For this problem, assume that the edges of the trees are oriented away from the root, for example, if the edges are (r,u), (r,v), and (r,w), where r is the root, then the edges are from r to u, r to v and r to w, respectively. 

In a rooted tree, the parent of a vertex v is the vertex connected directly to v on the path to the root; every vertex has a unique parent except the root which has no parent. A child of a vertex v is a vertex of which v is the parent. An ascendant of a vertex v is any vertex which is either the parent of v or is (recursively) the ascendant of the parent of v. 


You are given a collection of directed rooted trees T1,T2,…,Tr as input.

You have to partition the vertices of these trees into some number of groups such that no group contains two vertices such that one is an ascendant of another. In other words, every group should have the property that it does not contain a pair of vertices u and v such that u is an ascendant of v. Your task is to return the minimum number of groups you need to form to respect this constraint.


Input Format

The first line contains integer n (1 ≤ n ≤ 2000) — the total number of vertices.

The next n lines contain the integers pi (1 ≤ pi ≤ n or pi = -1). Every pi denotes the immediate parent for the i-th node. If pi is -1, that means that the i-th node is a root node.

It is guaranteed that pi ≠ i, that is there are no loops. Also, there are no cycles.

Output Format

Print a single integer denoting the minimum number of groups that will be formed in the party.



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
