#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(k == 0){
    printf("YES\n0\n");
    return;
  }

  if(k % 2 == 0){
    printf("NO\n");
    return;
  }

  int m = 1;
  while(m <= k){
    m *= 2;
  }
  m /= 2;

  vector<tiii> v;
  for(int l = 1, r = k; m != 0; m /= 2){
    n = r - l + 1;

    if(m <= n){
      v.push_back({m, r - m + 1, r});
      r -= m;
      continue;
    }

    if(m <= r){
      v.push_back({m, r - m + 1, r});
      tie(l, r) = make_pair(r - m + 1, l - 1);
      continue;
    }
    
    v.push_back({m, l, l + m - 1});
    tie(l, r) = make_pair(r + 1, l + m - 1);
  }
  sort(v.begin(), v.end());

  printf("YES\n%lu\n", v.size());
  for(auto [k, l, r]: v){
    printf("%d\n", l);
  }
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}