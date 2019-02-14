#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, s = 0, mx = 0, a;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a;
    s += a;
    mx = max(mx, a);
  }

  cout << n * mx - s << '\n';
  
  return 0;
}
