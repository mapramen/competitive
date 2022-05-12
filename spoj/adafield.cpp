#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> MX, MY;
priority_queue<pii> QX, QY;

void Set(map<int,int>& M, priority_queue<pii>& Q, int x, int d){
  M[x] = d;
  Q.push({d, x});
}

void Reset(map<int,int>& M, priority_queue<pii>& Q, int n){
  while(!Q.empty()){
    Q.pop();
  }
  M.clear();

  Set(M, Q, 0, n);
}

void Reset(int n, int m){
  Reset(MX, QX, n);
  Reset(MY, QY, m);
}

void Split(map<int,int>& M, priority_queue<pii>& Q, int z){
  auto it = prev(M.upper_bound(z));
  if(it->first == z){
    return;
  }

  int a = it->first, l = it->second;
  Set(M, Q, a, z - a);
  Set(M, Q, z, l - (z - a));
}

int GetMaxSide(map<int,int>& M, priority_queue<pii>& Q){
  while(M[Q.top().second] != Q.top().first){
    Q.pop();
  }
  return Q.top().first;
}

ll Query(){
  return 1ll * GetMaxSide(MX, QX) * GetMaxSide(MY, QY);
}

void Solve(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  Reset(n, m);

  while(q--){
    int t, z;
    scanf("%d%d", &t, &z);

    if(t == 0){
      Split(MX, QX, z);
    }
    else{
      Split(MY, QY, z);
    }

    printf("%lld\n", Query());
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