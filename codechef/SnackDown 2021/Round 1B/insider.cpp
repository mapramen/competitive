#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int b[N], c[N];
vector<int> a;
vector<pii> v;

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    if(a.empty()){
      a.push_back(x);
      continue;
    }

    if(a.back() == x){
      continue;
    }

    int l = a.size();
    if(l >= 2 && ((a[l - 2] < a[l - 1]) == (a[l - 1] < x))){
      a.pop_back();
    }
    a.push_back(x);
  }

  for(int k = 2; k <= n; ++k){
    b[k] = INT_MAX, c[k] = INT_MIN;
  }

  for(int m = a.size(), i = 1; i < m; ++i){
    int x = min(a[i - 1], a[i]), y = max(a[i - 1], a[i]);
    if(y - x > 1){
      v.push_back({x + 1, 1}), v.push_back({y - 1, 2});
    }
  }
  sort(v.begin(), v.end());

  int s = 1;
  for(auto [x, ds]: v){
    if(ds == 1){
      ++s;
      b[s] = min(b[s], x), c[s] = max(c[s], x);
    }
    else{
      b[s] = min(b[s], x), c[s] = max(c[s], x);
      --s;
    }
  }

  a.clear();
  v.clear();

  for(int k = n - 1; k > 1; --k){
    b[k] = min(b[k], b[k + 1]);
    c[k] = max(c[k], c[k + 1]);
  }

  for(int k = 2; k <= n; ++k){
    printf("%d ", b[k] == INT_MAX ? -1 : b[k]);
  }
  printf("\n");

  for(int k = 2; k <= n; ++k){
    printf("%d ", c[k] == INT_MIN ? -1 : c[k]);
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