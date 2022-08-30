#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int n;
	
	cin>>n;
	
	vector<int>adj[n];
	
	for(int i=0;i<n;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    adj[x-1].push_back(y-1);
	    adj[y-1].push_back(x-1);
	}
	
	vector<int>visited(n,0);
	
	queue<int>q;
	
	q.push(0);
	visited[0] = 1;
	
	while(q.empty()==false)
	{
	    int curr = q.front();
	    
	    q.pop();
	    
	    for(auto u:adj[curr] )
	    {
	        if(visited[u]==0)
	        {
	          q.push(u);
	          visited[u] = 3-visited[curr];
	        }
	        
	    }
	    
	}
	
	
	int count1 = 0;
	int count2 = 0;
	
	
	for(int i=0;i<n;i++)
	{
	    if(visited[i]==1) count1++;
	    
	    else  count2++;
	}
	
	

	long long res = (long long)count1 * (long long)count2;
		cout<<res-(long long)(n-1)<<endl;
	return 0;
}
