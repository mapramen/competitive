#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 500001

set<int> S;
int b[N], a[N];

int GetLowerBound(int n, int i){
  return (i / (b[i] + 1)) + 1;
}

int GetUpperBound(int n, int i){
  return b[i] == 0 ? n : i / b[i];
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  vector<tiii> v;
  for(int i = 1; i <= n; ++i){
    v.push_back({GetUpperBound(n, i), GetLowerBound(n, i), i});
  }
  sort(v.begin(), v.end());

  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  for(auto [r, l, i]: v){
    int x = *S.lower_bound(l);
    a[i] = x;
    S.erase(x);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
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