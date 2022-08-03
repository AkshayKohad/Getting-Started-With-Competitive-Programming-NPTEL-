#include <bits/stdc++.h>

using namespace std;


#define ll long long

ll n;
vector<ll>location;
vector<ll>velocity;


double leftmost_right(double k)
{
    double result = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        result = min(result, location[i]+velocity[i]*k);
    }
    
    return result;
}

double rightmost_left(double k)
{
    double result = INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        result = max(result, location[i]-velocity[i]*k);
    }
    
    return result;
}

bool check(double k)
{
    return leftmost_right(k)>=rightmost_left(k);
}

int main()
{
   cin>>n;
   
   location.resize(n);
   velocity.resize(n);
   
   
   for(ll i=0;i<n;i++)
   {
       cin>>location[i];
   }
   
   
   for(ll i=0;i<n;i++)
   {
       cin>>velocity[i];
   }
    
    
    double l = 0.0;
    
    double h = 1e9;
    
    double mid;
    
    double ans = INT_MAX;
    
    while((h-l)>1e-6)
    {
        mid = (h+l)/2;
        
        if(check(mid))
        {
            ans = min(ans,mid);
            h = mid;
        }
        
        else{
            l = mid;
        }
    }
    cout<<setprecision(12);
    cout<<ans;
    return 0;
}
