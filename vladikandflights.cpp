#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int main(){
  int n, a, b;
  string s;

  cin >> n >> a >> b;
  cin >> s;

  a--, b--;

  cout << (int)(s[a] != s[b]) << '\n';

  return 0;
}
