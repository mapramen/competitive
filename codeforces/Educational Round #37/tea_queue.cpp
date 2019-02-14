#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  cin >> t;
  while(t--){
    int n, x = 0;

    cin >> n;
    while(n--){
      int l, r;
      cin >> l >> r;
      x = max(x, l);
      if(x > r)
        cout << 0 << ' ';
      else{
        cout << x << ' ';
        ++x;
      }
    }

    cout << '\n';
  }

  return 0;
}
