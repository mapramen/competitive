#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& ai: a){
    scanf("%d", &ai);
  }

  map<int,int> C;
  for(int x: a){
    ++C[x];
  }

  for(auto [_, c]: C){
    if(c % 2 == 1){
      printf("-1\n");
      return;
    }
  }

  int base = 0;
  vector<pii> v;
  vector<int> t;

  while(!a.empty()){
    int k = 1;
    for( ; a[k] != a.front(); ++k);

    for(int j = 1; j < k; ++j){
      v.push_back({base + k + j, a[j]});
    }

    int d = 2 * k;
    t.push_back(d);
    base += d;

    for(int i = 1, j = k; i < j; ++i, --j){
      swap(a[i], a[j]);
    }

    reverse(a.begin(), a.end());
    a.resize(a.size() - 2);
    reverse(a.begin(), a.end());
  }

  printf("%lu\n", v.size());
  for(auto [p, c]: v){
    printf("%d %d\n", p, c);
  }

  printf("%lu\n", t.size());
  for(int d: t){
    printf("%d ", d);
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