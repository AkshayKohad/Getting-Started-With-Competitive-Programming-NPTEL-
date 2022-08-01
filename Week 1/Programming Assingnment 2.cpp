At a party, there are n cups of gulab jamun arranged in a circle. A fly is sitting in one of the cups at the moment.

After minute number k, the fly jumps over k - 1 cups (clockwise) and lands and the next one. For example, after the first minute the fly ends up at the neighboring cup, and after that at the third cup from the start.

You should answer: will the fly visit all the cups or not?

We assume that fly is jumping forever.

Input. The only line contains single integer: 1 ≤ n ≤ 1000 — number of cups.

Output. Output "YES" if all the cups will be visited and "NO" otherwise.

Examples.

input

1

output

YES


input

3

output

NO




#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  int n;
  
  cin>>n;
  
  // if n is power of 2
  if((n & (n-1)) == 0)
    cout<<"YES";
  
  else
    cout<<"NO";
}
