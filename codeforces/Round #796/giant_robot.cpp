#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002

int a[N], b[N];
set<pii> S[N];
set<int> non_zeros, zeros;
vector<pii> v;
vector<int> c;
queue<int> Q;

void Reset(int n){
  for(int i = 1; i <= n + 1; ++i){
    S[i].clear();
  }
  zeros.clear(), non_zeros.clear();
}

void Push(ll s, int i){
  if(s == 0){
    zeros.insert(i);
    Q.push(i);
  }
  else{
    non_zeros.insert(i);
  }
}

void Relax(set<pii>& S){
  for(auto [l, r]: S){
    if(zeros.count(l - 1) != 0 && zeros.count(r) != 0){
      v.push_back({l, r});
    }
  }

  for(auto [l, r]: v){
    S.erase({l, r});

    for(auto it = non_zeros.lower_bound(l); it != non_zeros.end() && *it <= r; ++it){
      c.push_back(*it);
    }

    for(int i: c){
      Push(0, i);
      non_zeros.erase(i);
    }

    c.clear();
  }

  v.clear();
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    S[l].insert({l, r});
    S[r].insert({l, r});
  }

  Push(0, 0);
  for(ll i = 1, s = 0; i <= n; ++i){
    s += (b[i] - a[i]);
    Push(s, i);
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    Relax(S[i + 1]);
    Relax(S[i]);
  }

  return non_zeros.empty();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}