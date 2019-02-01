#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define B 8

int leastPrime[N];
vector<int> u;
vector< vector<int> > v(B);

void Initialise(){
  for(int i = 2; i < N; ++i)
    for(int j = i; j < N; j += i)
      if(leastPrime[j] == 0)
        leastPrime[j] = i;
}

void PreProcess(int n){
  u.clear();
  for(int i = 0; i < B; ++i)
    v[i].clear();

  while(n > 1){
    int x = leastPrime[n];
    while(n % x == 0)
      n /= x;
    u.PB(x);
  }

  for(int mask = 0, b = u.size(); mask < (1 << b); ++mask){
    int p = 1;
    for(int i = 0; i < b; ++i){
      if((mask & (1 << i)) > 0)
        p *= u[i];
    }
    int k = __builtin_popcount(mask);
    v[k].PB(p);
  }
}

int Cnt(int m){
  int ans = 0;
  for(int i = 0; i < B; ++i){
    int ansx = 0;
    for(auto x : v[i])
      ansx += (m / x);
    if(i % 2)
      ans -= ansx;
    else
      ans += ansx;
  }
  return ans;
}

int BinarySearch(int a, int k){
  int x = 1, y = 1E9, z = y, base_cnt = Cnt(1ll * a);
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Cnt(mid) >= k + base_cnt)
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  int t;

  Initialise();

  scanf("%d", &t);
  while(t--){
    int x, k, p;
    scanf("%d%d%d", &x, &p, &k);
    PreProcess(p);
    printf("%d\n", BinarySearch(x, k));
  }

  return 0;
}
