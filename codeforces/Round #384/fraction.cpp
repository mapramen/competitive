#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;

  cin >> n;

  if(n == 1)
    cout << "-1\n";
  else
    cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';

  return 0;
}
