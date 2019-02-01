#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, s;

  cin >> n >> s;

  cout << (s / n) + (s % n != 0) << '\n';

  return 0;
}
