#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define TOTAL_MILES 1422
#define CHARGE_MILES 200

bool Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  for(int i = 1; i < n; ++i){
    if(a[i] - a[i - 1] > CHARGE_MILES){
      return false;
    }
  }

  return 2 * (TOTAL_MILES - a.back()) <= CHARGE_MILES;
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}