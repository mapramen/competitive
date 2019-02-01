#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 3
#define MAX_ITER 10000000

tiii a[N];

double Random(int a, int b){
  double random = (1.0 * rand()) / RAND_MAX;
  return a + random * (b - a);
}

int main(){
  int n, x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
  set<int> masks;

  cin >> n;

  for(int i = 0; i < n; ++i){
    int x, y, r;
    cin >> x >> y >> r;
    x1 = min(x1, x - r);
    x2 = max(x2, x + r);
    y1 = min(y1, y - r);
    y2 = max(y2, y + r);
    a[i] = MT(x, y, r);
  }

  for(int iter = 0; iter <= MAX_ITER; ++iter){
    double x = Random(x1, x2), y = Random(y1, y2);
    int mask = 0;
    for(int i = 0; i < n; ++i){
      int cx, cy, cr;
      tie(cx, cy, cr) = a[i];
      if((x - cx) * (x - cx) + (y - cy) * (y - cy) < cr * cr)
        mask |= (1 << i);
    }
    masks.insert(mask);
  }

  cout << masks.size() << '\n';

  return 0;
}
