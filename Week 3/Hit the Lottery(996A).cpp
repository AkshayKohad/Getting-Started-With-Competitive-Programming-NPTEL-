#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {

ll n;
cin>>n;

ll count = 0;

count += n/100;

n = n%100;

count += n/20;

n = n%20;

count += n/10;

n = n%10;

count += n/5;

n = n%5;


count += n/1;

n = n%1;


cout<<count<<endl;




	return 0;
}
