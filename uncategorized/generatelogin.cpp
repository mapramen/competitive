#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string a, b, ans;

  cin >> a >> b;

  ans.PB(a[0]);

  for(int i = 1; i < a.size() && a[i] < b[0]; ans.PB(a[i]), ++i);

  ans.PB(b[0]);

  cout << ans << '\n';

  return 0;
}
