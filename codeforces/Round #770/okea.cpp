#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(k != 1 && n % 2 != 0){
    printf("NO\n");
    return;
  }

  printf("YES\n");

  vector<pii> a;
  for(int i = 1; i <= n * k; ++i){
    a.push_back({i % 2, i});
  }
  sort(a.begin(), a.end());

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      printf("%d ", a.back().second);
      a.pop_back();
    }
    printf("\n");
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