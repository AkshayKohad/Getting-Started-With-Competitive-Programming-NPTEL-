#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
	 
    ll sx,sy;
    ll ex,ey;
    
    cin>>sx>>sy;
    cin>>ex>>ey;
    
    ll n;
    cin>>n;
    
   string s; cin>>s;

        //Declaring the required variables
        //As discussed in the lecture, the upper bound of the search space is n*D
        //where D is the manhattan distance between the start and the end point 
        ll lo=0, hi = (abs(sx-ex) + abs(sy-ey))*n, ans=-1;

        //vectors to store the x and y offsets 
        //Here devx[i] denotes the offset in x(i.e. the change in x-coordinate after i days)
        // and devy[i] denotes the offset in y(i.e. the change in y-coordinate after i days)
        vector<ll> devx(n+1,0);
        vector<ll> devy(n+1,0);

        //Pre - processing the offsets corresponding to the x and y coordinates 
        //This helps to determine the change in x and y coordinates in O(1) 
        for(int i=0;i<=s.length()-1;i++)
        {
            devx[i+1] = devx[i];
            devy[i+1] = devy[i];
            if(s[i] == 'U') devy[i+1]++;
            else if(s[i] == 'D') devy[i+1]--;
            else if(s[i] == 'L') devx[i+1]--;
            else devx[i+1]++;
        }

        //Binary Search Logic
        while(hi>=lo)
        {
            ll mid = (lo+hi)/2;

            ll q = mid/n;                      // q determines the no of full cycles of n days 
            ll r = mid%n;                      // r determines the no of days which are not accounted in the 'q' cycles

            ll x3 = sx + devx[n]*q + devx[r];  // x3 and y3 determine the x and y coordinates after m days 
            ll y3 = sy + devy[n]*q + devy[r];  // only due to the wind(i.e, without the captain's influence) 
            ll d = abs(ex-x3) + abs(ey-y3);    //d is the manhattan distance between the end point and the point(x3,y3)

            if(d<=mid)                         //if we can get to the end point from (x3,y3) by performing <=mid no of 
            {                                  //operations, then mid is a possible ans, also any k>mid is a possible 
                ans = mid;                     //ans, thus we narrow down our search space and discard the part[mid,hi] 
                hi = mid-1;
            }
            else lo = mid+1;                   // Else, we start searching in [mid+1,hi] and discard [lo,mid].
        }
    
    cout<<ans;
	
	
	
	return 0;
}
