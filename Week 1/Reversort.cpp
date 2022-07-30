#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
#define vi  vector<int>
#define vll vector<long long int>


int reverSort(vi a)
{
    int cost = 0;
    
    int len = a.size();
    for(int i=0;i<len-1;i++)
    {
        //finding minimum element in  rest of array
        int m = *min_element(a.begin()+i,a.end());
        
        //find the index of minimum array
        
        auto idx = find(a.begin(),a.end(),m);
        
        // execute the reverse
        
        reverse(a.begin()+i,idx+1);
        
        // track the cost
        
        cost += distance(a.begin(),idx) - i +1;
        
    }
    
    return cost;
}


int main()
{
    std::ios::sync_with_stdio(false);
    
     int t;
     cin>>t;
     int c = 0;
     while(t--)
     {
         c++;
         int n;
         cin>>n;
         
         vi a(n);
         
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
         }
         
         cout << "Case #" << c << ": " << reverSort(a) << endl;
         
     }
}
