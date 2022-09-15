A new prime minister has been elected for the country, ByteLand. Having spend all the time learning maths, he always finds new and weird ways to make decisions. Recently, with the revamping of the road system of the country, he has been asked to provide a plan of breaking some roads from a system of roads. There might be some cities which have multiple roads of different length between them.

He should make a plan such that, the length of the total road broken should be as high as possible. He should also ensure that after breaking the roads, all the cities should still be connected with each other (any city can be visited from another city following a simple path along the route after breaking the roads)



Help him break the roads following the above instruction and tell the maximum length of road that you can break.

Constraints:
Number of cities (n) <= 106
Number of roads (m) <= 106
Weight of edges (wi) <= 106

Input:
- The first line of input contains 2 integers n, m representing the number of cities and the number of bidirectional roads respectively.
- The next m lines contain 3 numbers each, A, B and C. A and B are the 2 cities and C is the length of the bidirectional road between these cities.

Output:
- Print the length of the maximum road length that the new prime minister can break.
  
  
  #include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>>adj[n];
    
    int sum = 0;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        
        cin>>x>>y>>w;
        
        sum += w;
        
        adj[x-1].push_back({y-1,w});
        
        adj[y-1].push_back({x-1,w});
        
    }
    
    vector<int>visited(n,0);
    
    
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    pq.push({0,0});
    
    int cnt = 0;
    
    while(pq.size()>0)
    {
        pair<int,int>cur = pq.top();
        pq.pop();
        
        int weight = cur.first;
        int node = cur.second;
    
       if(visited[node]==1) continue;
       
      // cout<<weight<<endl;
        visited[node] = 1;
        sum -= weight;
        
        cnt++;
        
        if(cnt == n) break;
        for(auto u : adj[node])
        {
            int nd = u.first;
            
            int w = u.second;
            
            if(visited[nd]==1) continue;
            
            pq.push({w,nd});
            
            
        }
        
        
    }
    
    cout<<sum;
    return 0;
}
