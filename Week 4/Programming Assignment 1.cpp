Bob is instructed by his father to paint a row of cubes. Initially, there are no cubes in the row. But Bob has a lot of unpainted cubes. His father gives him specific instructions and expects him to follow these instructions. Solve this problem using either of the methods discussed in the quiz (online and offline). The merging technique would be used to solve this online.


These are the queries: 



Type 1 → Put an unpainted cube in the end of the row and paint it to colour "c".

Type 2 → Paint all blocks which were painted with colour “c1” to colour “c2”.

Input:
First line contains Q(number of queries). This if followed by Q lines, each containing a query. 

Query of Type is given as follows:
1 X → place a cube in the end and paint it X

Query of Type is given as follows:
2 X Y → Paint all blocks which were painted with colour X to colour Y

Constraints:
Q ≤ 10^5
1 ≤ X ≤ 10^5 and 1 ≤ Y ≤ 10^5





#include  <bits/stdc++.h>

using namespace std;

int find(int i,vector<int>&parent)
{
    if(parent[i]==-1) return i;
    
    return parent[i] = find(parent[i],parent);
}

int unite(int p,int q,vector<int>&parent,vector<int>&rank)
{
    int n1 = find(p,parent);
    
    int n2 = find(q,parent);
    
    
    if(n1 != n2)
    {
      if(rank[n1]>=rank[n2])
      {
          parent[n2] = n1;
          
          rank[n1] += rank[n2];
          
          return n1;
      }
      
      
      else{
          parent[n1] = n2;
          
          rank[n2] += rank[n1];
          
          return n2;
      }
    }
    
}
int main() {

    unordered_map<int,int>mp;
    
    vector<int>parent;
    vector<int>rank;
    
    int q;
    cin>>q;
    
    while(q--){
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int color;
            cin>>color;
            
            parent.push_back(-1);
            rank.push_back(1);
            int n = parent.size();
            if(mp.find(color)==mp.end())
            {
                mp[color] = n-1;
            }
            
            else{
                int p = mp[color];
                
               int par =  unite(p,n-1,parent,rank);
                
                
                mp[color] = par;
            }
            
        }
        
        else{
            int color1,color2;
            cin>>color1>>color2;
            
            
            if(mp.find(color1) != mp.end())
            {
                int par = mp[color1];
                
                mp.erase(color1);
                
                if(mp.find(color2)!=mp.end())
                {
                    int par2 = mp[color2];
                    
                    int par3 = unite(par,par2,parent,rank);
                    
                    mp[color2] = par3;
                }
                
                else
                {
                    mp[color2] = par;
                }
            }
        }
    }
    
    
    unordered_map<int,int>parent_color;
    
    for(auto k:mp)
    {
        parent_color[k.second] = k.first;
        
    }
    
    for(int i=0;i<parent.size();i++)
    {
        int par = find(i,parent);
        
        cout<<parent_color[par]<<" ";
    }
    
    cout<<endl;
	return 0;
}
