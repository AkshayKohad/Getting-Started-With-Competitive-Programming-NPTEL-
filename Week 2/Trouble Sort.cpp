#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    int count = 0;
    while(t--)
    {
        
        ll n;
        cin>>n;
        
        vector<ll>a(n);
        
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        vector<ll>odd;
        vector<ll>even;
        
        for(int i=0;i<n;i++)
        {
            // odd index (because of 0 indexing)
            if(i%2==0)
            {
                odd.push_back(a[i]);
            }
            
            else{
                even.push_back(a[i]);
            }
        }
        
        sort(odd.begin(),odd.end());
        
        sort(even.begin(),even.end());
        
        int i_odd = 0;
        int i_even = 0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                a[i] = odd[i_odd];
                i_odd++;
            }
            
            else{
                a[i] = even[i_even];
                i_even++;
            }
        }
        int index=-1;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                index = i-1;
                break;
            }
        }
        
        count++;
        
        if(index==-1)
        {
         cout<<"Case #"<<count<<": OK"<<endl;   
        }
        
        else{
         cout<<"Case #"<<count<<": "<<index<<endl;    
        }
        
    }
}
