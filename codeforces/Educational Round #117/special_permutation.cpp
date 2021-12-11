#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);

  int m = n / 2;

  vector<int> L{a}, R{b};
  for(int x = 1; x <= n; ++x){
    if(x == a || x == b){
      continue;
    }

    if(x < a || x < b && R.size() < m){
      R.push_back(x);
    }
    else{
      L.push_back(x);
    }
  }

  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  if(max(L.size(), R.size()) != m || L.front() != a || R.back() != b){
    printf("-1\n");
    return;
  }

  for(int x: L){
    printf("%d ", x);
  }

  for(int x: R){
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