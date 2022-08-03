#include <bits/stdc++.h>

using namespace std;

int main() {

int t;
cin>>t;


while(t--)
{

int n;
cin>>n;



unordered_set<char>s;

for(int i=0;i<n;i++)
{
    char ch;
    cin>>ch;
    
    s.insert(ch);
}


cout<<n+s.size()<<endl;
}
	return 0;
}
