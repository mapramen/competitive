#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int c[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    c[i] = 1;
  }

  for(int i = 2; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      c[j] = 0;
    }
  }

  for(int i = 2; i < N; ++i){
    c[i] += c[i - 1];
  }
}

int GetCount(vector<int>& a, int n, int mask){
  int ans = n;
  while(mask != 0){
    int k = __builtin_ctz(mask);
    ans /= a[k];
    mask ^= (1 << k);
  }
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& x: a){
    scanf("%d", &x);
  }
  
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  m = a.size();

  int ans = 0;
  for(int mask = 0; mask < (1 << m); ++mask){
    int ansx = GetCount(a, n, mask);
    ans += __builtin_popcount(mask) % 2 == 0 ? ansx : -ansx;
  }

  ans -= c[n];
  for(int x: a){
    ans += (x <= n);
  }

  return ans;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  
  return 0;
}