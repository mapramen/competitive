#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k, p, q, x = 0, y = 0;

  cin >> n >> k;
  p = n, q = 2 * n;

  for(int i = 1; i <= k; i++){
    int j;
    cin >> j;
    int d = min(j / 4, p);
    p -= d;
    j -= 4 * d;
    y += j / 2;
    x += j % 2;
  }

  for( ; y >= 0; y--, x += 2){
    if(y > p + q || x + y > 2 * p + q)
      continue;
    else{
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
