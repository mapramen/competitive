#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b, c;

  cin >> a >> b >> c;

  cout << 7 * min(a, min(b / 2, c / 4)) << '\n';

  return 0;
}
