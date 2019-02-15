#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

ll X1[N], X2[N], Y1[N], Y2[N], A[N], B[N], C[N];

bool CheckInsideSegment(int i, ll x, ll y){
  return (X1[i] <= x && x <= X2[i] && Y1[i] <= y && y <= Y2[i]);
}

int main(){
  int n, ans = 0;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll a = y2 - y1, b = - (x2 - x1), c = - (a * x1 + b * y1);
    ans += (1 + __gcd(abs(a), abs(b)));
    if(x1 > x2){
      swap(x1, x2);
    }
    if(y1 > y2){
      swap(y1, y2);
    }
    X1[i] = x1, Y1[i] = y1, X2[i] = x2, Y2[i] = y2;
    A[i] = a, B[i] = b, C[i] = c;
  }

  for(int i = 1; i <= n; ++i){
    set< pll > intersections;
    for(int j = i + 1; j <= n; ++j){
      ll p = (C[j] * B[i] - C[i] * B[j]), q = (C[j] * A[i] - C[i] * A[j]), r = (A[j] * B[i] - A[i] * B[j]);

      if(abs(r) == 0 || abs(p) % abs(r) != 0 || abs(q) % abs(r) != 0){
        continue;
      }

      ll x = - p / r, y = q / r;
      if(CheckInsideSegment(i, x, y) && CheckInsideSegment(j, x, y)){
        intersections.insert(MP(x, y));
      }
    }
    ans -= intersections.size();
  }

  cout << ans << '\n';

  return 0;
}
