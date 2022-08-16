#include<bits/stdc++.h>

using namespace std;

bool mycmp(pair<int,int>f,pair<int,int>s)
{
  if(f.second == s.second)
    return f.first<s.first;
  
  return f.second < s.second;
}

int main()
{
  int n,d;
  
  cin>>n>>d;
  
  
  vector<pair<int,int>>intervals;
  
  while(d--)
  {
   int l,r;
    cin>>l>>r;
    
    intervals.push_back({l,r});
  }
  
  sort(intervals.begin(),intervals.end(),mycmp);
  
  int curr_left = intervals[0].second-1;
  int curr_right = intervals[0].second;
  
  int count = 1;
  for(int i=1;i<intervals.size();i++)
  {
    if(curr_left>=intervals[i].first && curr_right<=intervals[i].second)
    {
      continue;
    }
    
    else{
      curr_left = intervals[i].second-1;
      curr_right = intervals[i].second;
      
      count++;
    }
  }
  
  
  cout<<count<<endl;
}
