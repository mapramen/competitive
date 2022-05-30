#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int d[N][N];
pii parent[N][N];
queue<pii> Q;

void Reset(int n){
  for(int r = 0; r <= n; ++r){
    for(int s = 0; s <= n; ++s){
      d[r][s] = INT_MAX;
    }
  }

  while(!Q.empty()){
    Q.pop();
  }
}

void CheckAndUpdate(int r, int s, int val, int pr, int ps){
  if(val >= d[r][s]){
    return;
  }
  d[r][s] = val, parent[r][s] = {pr, ps};
  Q.push({r, s});
}

string Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  CheckAndUpdate(0, 0, 0, -1, -1);

  while(d[0][n] == INT_MAX){
    int r, s;
    tie(r, s) = Q.front();
    Q.pop();

    for(int x = 0, val = d[r][s]; x < 10; ++x){
      int nr = (10 * r + x) % n, ns = s + x;
      if(ns > n){
        continue;
      }
      CheckAndUpdate(nr, ns, val + 1, r, s);
    }
  }

  string ans;
  for(int r = 0, s = n; r != 0 || s != 0; ){
    int pr, ps;
    tie(pr, ps) = parent[r][s];

    ans.push_back('0' + s - ps);
    r = pr, s = ps;
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}