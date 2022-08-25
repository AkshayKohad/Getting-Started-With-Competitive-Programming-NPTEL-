A permutation f of a set S is defined as a bijection from S to itself. That is, it is a function from S to S for which every element occurs exactly once as an image value. For example, if S = {1,2,3}, then an example of a permutation on S is: f(1) = 2, f(2) = 1, f(3) = 3. 

Fix Sn={1,2,3,⋯,n}. Suppose you want to describe a permutation f on Sn. The following are two natural ways to go about it. 

In the one-line notation, we describe the permutation as a sequence of length n. The i-th element of the sequence contains the value of f(i).

In the cyclic notation, we describe the effect of repeatedly applying the permutation on the elements of the set. It expresses the permutation as a product of cycles; since distinct cycles are disjoint, this is referred to as "decomposition into disjoint cycles". To write down the permutation f in cycle notation, one proceeds as follows:

- Select an arbitrary element x of Sn and write it down.

- Then trace the orbit of x; that is, write down its values under successive applications of f until the value returns to x, and once this happens, write down a closing parenthesis rather than x.

- Now continue with an element y of Sn, not yet written down, and proceed in the same way.

- Continue until all elements of Sn are written in cycles.

 So the permutation 2,5,4,3,1 (in one-line notation) could be written as (125)(34) in cycle notation.

You are given a permutation of Sn in one-line notation. For each (1 ≤ i ≤ n), return the number of elements in the cycle that i belongs to. For example, for the permutation 2, 5, 4, 3, 1, the answer should be 3, 3, 2, 2, 3. 

Hint. Treat the elements of Sn as the universe; and view the cycles as sets. Go through the permutation to build up the sets. Keep track of the sizes of the sets as well.

Input

The first line of the input contains one integer T (1≤ T ≤200) — the number of test cases. Then T test cases follow.

The first line of the test case contains one integer 𝑛 (1≤𝑛≤200). The second line of the test case contains 𝑛 integers 𝑝1,𝑝2,…,𝑝𝑛 (1≤𝑝𝑖≤𝑛, all 𝑝𝑖 are distinct, i.e. 𝑝 is a permutation of Sn.

Output

For each test case, print the answer on it: 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛, where 𝑎𝑖 is the number of elements in the cycle that i belongs to.

Example

Sample Input

1
6
2
5
3
1 2 3 4 5
4
3
5
2 3 1
6
6
7
4 6 2 1 5 3
8
1
9
1
10
4
11
3 4 1 2
12
5
13
5 1 2 4 3


Sample Output

1
1 1 1 1 1 
2
3 3 3 
3
2 3 3 2 1 3 
4
1 
5
2 2 2 2 
6
4 4 4 1 4 
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          #include <bits/stdc++.h>
using namespace std;

int find(int i,vector<int>&parent)
{
    if(parent[i]==-1) return i;
    
    return parent[i] = find(parent[i],parent);
}


bool unite(int p,int q,vector<int>&parent,vector<int>&rank)
{
    int n1 = find(p,parent);
    int n2 = find(q,parent);
    
    if(n1==n2) return true;
    
    if(rank[n1]>=rank[n2])
    {
        parent[n2] = n1;
        
        rank[n1] += rank[n2];
    }
    
    else{
        parent[n1] = n2;
        
        rank[n2] += rank[n1];
    }
    
    return false;
}


int main() {
    
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    
	    cin>>n;
	    
	    vector<int>parent(n+1,-1);
	    vector<int>rank(n+1,1);
	    
	    
	    vector<int>a(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    vector<int>visited(n+1,0);
	 
	 for(int i=0;i<n;i++)
	 {
	     int p = a[i];
	     if(visited[p]==1) continue;
	     while(1)
	     {
	     
	     visited[p] = 1;
	     
	     int q = a[p-1];
	     
	     if(unite(p,q,parent,rank))
	     break;
	     
	     
	     int p = q;
	     
	     
	     }
	     
	 }
	 
	 for(int i=0;i<n;i++)
	 {
	     int par = find(a[i],parent);
	     
	     cout<<rank[par]<<" ";
	 }
	 
	 cout<<endl;
	    
	}
	return 0;
}
