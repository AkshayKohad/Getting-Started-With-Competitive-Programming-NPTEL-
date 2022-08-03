There are N boxes. The i-th box a[i] packets of Maggi. So, by picking up the i-th box, you grab a[i] packets of Maggi.

There are Q queries regarding these boxes. For the j-th query you have to answer what is the minimum number of boxes you need to pick up to own at least x[j] packs of Maggi, or print -1 if it's not possible to obtain such a quantity.

In other words, you should print the minimum possible K such that after picking K boxes, you have at least x[j] packets of Maggi. Note that one box can be chosen once only, and queries are independent of each other (you can use the same box for different queries).


Input

The first line of input contains a single integer T (1 ≤ T ≤ 1000)  — the number of test cases. The description of test cases follows.

The first line contains 2 integers N and Q (1 ≤ N , Q ≤  10^5) — the number of boxes and the number of queries you have to print an answer for respectively.

The second line contains N integers a[1], ... , a[n] (1 ≤ a[i] ≤ 10^4) — the number of packs of Maggi in each box.

Then Q lines follow.

Each of the next Q lines contains a single integer x[j] (1≤ x[j] ≤ 10^9) – the number of Maggi packets you want to own for each query.

Output

For each test case output Q lines. For the j-th line output the number of boxes you need to pick up to own at least x[j] packs of Maggi, or print -1 if it's not possible to obtain such a quantity.



Example

Sample Input

3
8 7
4 3 3 1 1 4 5 9
1
10
50
14
15
22
30
4 1
1 2 3 4
3
1 2
5
4
6

output

1
2
-1
2
3
4
8
1
1
-1
  
  
  
  #include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
     ll t;
	cin>>t;
	while(t--)
	{
	    ll n,q;
	    
	    
	    cin>>n>>q;
	    vector<ll>a(n);
	    
	    ll mini = a[0];
	    ll sum = 0;
	    for(ll i=0;i<n;i++)
	    {
	        cin>>a[i];
	        
	        
	    }
	    
	    sort(a.begin(),a.end(),greater<int>());
	    vector<int>prefix(n);
	    
	    prefix[0] = a[0];
	    for(int i=1;i<n;i++)
	    {
	        prefix[i] = prefix[i-1] + a[i];
	    }
	    
	    while(q--)
	    {
	        ll total;
	        cin>>total;
	        
	        
	        ll l = 0;
	         ll h = n-1;
	         
	         ll ans = INT_MAX;
	         while(l<=h)
	         {
	             ll mid = (l+h)/2;
	             
	             if(prefix[mid]==total)
	             {
	                 ans = min(mid,ans);
	                 break;
	             }
	             
	             else if(prefix[mid]>total)
	             {
	                 ans = min(ans,mid);
	                 h = mid-1;
	             }
	             
	             else{
	                 l = mid+1;
	             }
	         }
	         
	         if(ans==INT_MAX)
	         cout<<-1<<endl;
	         
	         else{
	             cout<<ans+1<<endl;
	         }
	    }
	    
	}
	return 0;
}
