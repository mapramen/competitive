#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<int,int> M;

void Reset(){
  M.clear();
}

pii ReadRoom(){
  int r, p;
  scanf("%d%d", &r, &p);
  M[r] = p;
  return {r, p};
}

void Print(char c, ll x){
  printf("%c", c);
  if(x != 0){
    printf(" %lld", x);
  }
  printf("\n");
  fflush(stdout);

  if(c != 'E'){
    ReadRoom();
  }
}

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  Reset();

  ReadRoom();

  uniform_int_distribution<int> uid = uniform_int_distribution<int>(1, n);
  for(int i = 1; i <= k && M.size() != n; ++i){
    int r = M.begin()->first;
    while(M.count(r) != 0){
      r = uid(rng);
    }
    Print('T', r);
    // Print('W', 0);
  }

  ll ans = 0;
  for(auto [_, ansx]: M){
    ans += ansx;
  }
  ans = (ans * n / M.size());

  Print('E', ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}