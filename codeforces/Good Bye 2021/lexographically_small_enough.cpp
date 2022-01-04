#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100005
#define B 26

vector<vector<int>> V(B);
int a[B][N], d[B];

bool IsImpossible(string s, string t){
  sort(s.begin(), s.end());
  return t <= s;
}

int GetNextSmallerChar(char c){
  int k = -1, xk = INT_MAX;
  for(int i = 0; i < B; ++i){
    if('a' + i >= c || V[i].empty()){
      continue;
    }

    int xi = d[i] + V[i].back();
    if(xi < xk){
      k = i, xk = xi;
    }
  }

  return k;
}

void MoveNext(int i){
  int j = V[i].back() + 1;
  V[i].pop_back();

  if(V[i].empty()){
    return;
  }

  for(int m = V[i].back(); j <= m; ++j){
    d[i] += a[i][j];
  }
}

ll Solve(){
  int n;
  string s, t;

  cin >> n >> s >> t;

  if(IsImpossible(s, t)){
    return -1;
  }

  if(s < t){
    return 0;
  }

  for(int k = 0; k < B; ++k){
    V[k].clear();
    d[k] = 0;

    for(int i = 0; i <= n; ++i){
      a[k][i] = 0;
    }
  }

  for(int i = n - 1; i != -1; --i){
    int k = s[i] - 'a';
    V[k].push_back(i);
  }

  ll ans = LLONG_MAX, ansx = 0;
  for(int i = 0; i < n; ++i){
    int lk = GetNextSmallerChar(t[i]);
    if(lk != -1){
      ans = min(ans, ansx + V[lk].back() + d[lk] - i);
    }

    int ek = t[i] - 'a';
    if(V[ek].empty()){
      break;
    }

    int ekx = V[ek].back() + d[ek];

    for(int k = 0; k < B; ++k){
      if(!V[k].empty() && V[k].back() < V[ek].back()){
        ++d[k];
        --a[k][V[ek].back()];
      }
    }
    
    ansx += ekx - i;
    MoveNext(ek);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}