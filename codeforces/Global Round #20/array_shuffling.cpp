#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> c(n + 1);
  vector<tiii> v;

  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    v.push_back({++c[x], x, i});
  }
  sort(v.begin(), v.end());

  vector<int> a(n);
  for(int k = 0; k < n; ++k){
    a[get<2>(v[k])] = get<1>(v[(k + 1) % n]);
  }

  for(int x: a){
    printf("%d ", x);
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