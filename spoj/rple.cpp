#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000

bool spies[N], is_spied[N];

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    spies[i] = false, is_spied[i] = false;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    spies[i] = true, is_spied[j] = true;
  }

  for(int i = 1; i <= n; ++i){
    if(spies[i] && is_spied[i]){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d: %s\n", k, Solve() ? "spying" : "spied");
  }
  return 0;
}