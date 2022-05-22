#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetCount(vector<int>& a, int m, int mask){
  vector<int> b;

  while(mask != 0){
    int i = __builtin_ctz(mask);
    mask ^= (1 << i);

    int x = a[i];
    for(int y: b){
      x /= __gcd(x, y);
    }

    m /= x;
    b.push_back(x);
  }

  return m;
}

int main(){
  int m, n;
  scanf("%d%d", &m, &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int ans = m;
  for(int mask = 1; mask < (1 << n); ++mask){
    int ansx = GetCount(a, m, mask);
    ans += (__builtin_popcount(mask) % 2 == 1 ? -ansx : ansx);
  }

  printf("%d\n", ans);

  return 0;
}