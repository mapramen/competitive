#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k, d;
  cin >> n >> k;
  d = n / k;
  d = (d % 2);
  if(d)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
