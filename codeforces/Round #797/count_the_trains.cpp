#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  map<int,int> C;
  for(int i = 1, j = 1; i <= n; i = j){
    for(j = i; j <= n && a[j] >= a[i]; ++j);
    C[i] = j - 1;
  }

  while(m--){
    int i, x;
    scanf("%d%d", &i, &x);
    a[i] -= x;

    auto it = prev(C.upper_bound(i));
    int l = it->first, r = it->second;
    if(a[i] < a[l]){
      C[l] = i - 1, C[i] = r;
    }

    l = prev(C.upper_bound(i))->first;
    while(true){
      it = C.upper_bound(r);
      if(it == C.end() || a[it->first] < a[l]){
        break;
      }
      r = it->second;
      C.erase(it);
    }
    C[l] = r;

    printf("%lu ", C.size());
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}