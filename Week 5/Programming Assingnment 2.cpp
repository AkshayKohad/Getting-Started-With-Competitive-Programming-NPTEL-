Flip the Tree

You are given an undirected tree as input. The tree has n nodes and the nodes are labeled as 1, 2, …., n. The node which is labeled 1 is the root of the tree (i.e. the tree is rooted at node 1). Node i has been assigned a value vi where vi is either 0 or 1, and 1 ≤ i ≤ n. You want to make the value of the node i equal to di where di is either 0 or 1, and 1 ≤ i ≤ n.


For example: Let n = 3,

v1 = 0, v2 = 1, v3 = 1
d1 = 1, d2 = 1, d3 = 0
So, in this case the required value of node 2 is the same as the assigned value, but the assigned values of node 1 and 3 need to be flipped from 0 to 1 and 1 to 0 in order to get the required values.


In order to change the assigned value of any node you are allowed to perform only the following operation: You can choose any node, say u. After choosing the node, its current value will be flipped (i.e. if the current value is 0 then it will be flipped to 1, and if the current value is 1 then it will be flipped to 0), the values of the sons of node u will remain same, the values of the sons of sons of node u will get flipped, the values of sons of sons of sons of node u will remain same and so on.


Your task is to make the value of node i equal to di for all nodes using the minimum number of the above mentioned operation.

Input Format:
The first line contains a single integer n, the total number of nodes in the tree (1 ≤ n ≤ 105).
Each of the next n-1 lines contains two integers ai and bi, which means there is an edge between the nodes ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi).
The next line contains n integers v1, v2, ...., vn (0 ≤ vi ≤ 1).
The next line contains n integers d1, d2, ...., dn (0 ≤ di ≤ 1).

Output Format:
Output a single integer, the minimum number of operations required to get the required value son all the nodes.
  
  #include <bits/stdc++.h>
using namespace std;
 
void addEdges(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void dfsUtil(int u, vector<int> adj[], vector<bool>& visited, bool foo, bool foo1, int ini[], int fi[], int& ans)
{
    visited[u] = true;
 
    if ((ini[u - 1] ^ foo)
        ^ fi[u - 1]
              == true) {
        ans++;
        foo ^= 1;
    }
 
    for (int i = 0;
         i < adj[u].size(); i++) {

      if (visited[adj[u][i]] == false)
 
            dfsUtil(adj[u][i], adj, visited, foo1, foo, ini, fi, ans);
    }
}
 
int dfs(vector<int> adj[], int v,
        int ini[], int fi[])
{
    int total = 0;
    vector<bool> visited(v, false);
 
 
    for (int u = 1; u <= 1; u++) {
 
 
        if (visited[u] == false)
            dfsUtil(u, adj, visited,  0, 0, ini, fi, total);
    }
 
 
    cout << total;
}
 
void countOperations(int n, int ini[], int fi[], int Edges[][2])
{
 
    vector<int> adj[n + 1];
 
 
    for (int i = 0; i < n - 1; i++) {
        addEdges(adj, Edges[i][0], Edges[i][1]);
    }
 
 
    dfs(adj, n + 1, ini, fi);
}
 
// Driver Code
int main()
{
    int n;
    cin >> n;
 
    
    int ini[n];
    int fi[n];
  
  	int edges[n - 1][2];
  
  for(int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    
    edges[i][0] = x;
    edges[i][1] = y;
    
  }
  
  
  
  for(int i=0;i<n;i++)
  {
    cin >> ini[i];
  }
   for(int i=0;i<n;i++)
   {
    cin >> fi[i];
   }
  
    countOperations(n, ini, fi, edges);
 
    return 0;
}
