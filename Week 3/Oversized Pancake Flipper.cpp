#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int p = 0;
    while(t--)
    {
        string s;
        int k;
        
        cin>>s>>k;
        
        
        int n = s.length();
        vector<bool>status(n);
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-')
            {
                status[i] = 0;
            }
            
            else{
                status[i] = 1;
            }
        }
        
        int count = 0;
        
        bool flag = false;
        
        for(int i=0;i<n;i++)
        {
           if(status[i]==0)
           {
               if(i+k<=n)
               {
                   count++;
                   
                   for(int j=i;j<i+k;j++)
                   {
                       status[j]=!status[j];
                   }
                   
                   
               }
               
               
               else{
                   flag = true;
                   break;
               }
           }
        }
        
        p++;
        if(flag==true)
        {
            cout<<"Case #"<<p<<": IMPOSSIBLE"<<endl;
        }
        
        else{
            cout<<"Case #"<<p<<": "<<count<<endl;
        }
        
    }
}
