There is a couple who is madly in love, but due to the upcoming semester exams, they need to study in the workspace. The workspace has chairs in form of a N×M matrix.

Rows are numbered from 1 to N from top to bottom and columns are numbered from 1 to M as we move from left to right. 

The seat at the intersection of the i−th row and j−th column is occupied if matrix[i][j]=1, otherwise it is empty. 


Distance between 2 seats is the Manhattan Distance of the 2 points in the 2D matrix. 

The couple needs wants to sit as close to each other as possible. What is the minimum manhattan distance between such empty pair of seats. If it is not possible, output -1.

Input: 
The first line contains T, the number of test cases. 
In each test case, the first line contains two integers n and m (1 ≤ m, n ≤ 106), number of rows and number of columns of matrices respectively. Note that sum of n×m across all test cases is ≤ 106.

The next n lines each contain m integers separated by spaces describing the state of occupancy of seats in the workspace.

Constraints:
 1≤T≤103 
 1≤N≤106 
 1≤M≤106 
 1≤Sum of N∗M over all test cases≤106 

Output Format:
Output the minimum distance between two empty seats if possible. Otherwise, print -1.
  
  
  #include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

vector<pair<int,int>>directions1 = {{1,1},{1,-1},{-1,1},{-1,-1}};

void bfs(int i,int j,vector<vector<int>>&a,int &n,int &m,int &res)
{
    
    vector<vector<int>>visited(n,vector<int>(m,0));
  
  
  queue<pair<int,int>>q;
  q.push({i,j});
  visited[i][j] = 1;
  
  while(q.empty() == false)
  {
    pair<int,int>curr = q.front();
    
    q.pop();
    
    for(auto k:directions)
    {
        int x = k.first + curr.first;
        int y = k.second + curr.second;
        
        if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==1)
        continue;
        
        if(abs(i-x) + abs(j-y) < res)
        {
            if(a[x][y] == 1)
            {
                q.push({x,y});
                visited[x][y] = true;
            }
            
            else{
                res = abs(i-x) + abs(j-y);
                
               // cout<<i<<" "<<j<<" --> "<<x<<" "<<y<<endl;
            }
        }
        
    }
  }
  
}
int main()
{

   int t;
   cin>>t;
   
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       
       vector<vector<int>>a(n,vector<int>(m));
       
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               cin>>a[i][j];
               
               if(a[i][j]==0)
               {
                   q.push({i,j});
               }
           }
       }
       
       
       
       int res = INT_MAX;
       
       while(q.empty()==false)
       {
           pair<int,int>curr = q.front();
           q.pop();
           int x = curr.first;
           int y = curr.second;
            bfs(x,y,a,n,m,res);
           
          // res = min(res,ans);
       }
       
       
       if(res==INT_MAX) cout<<-1<<endl;
       
       else
       cout<<res<<endl;
       
   }
	return 0;
}
