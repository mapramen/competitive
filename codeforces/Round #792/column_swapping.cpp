#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int>> A(n, vector<int>(m));

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      scanf("%d", &A[i][j]);
    }
  }

  set<pii> S;
  for(int i = 0; i < n; ++i){
    vector<int> a = vector<int>(A[i]);
    vector<int> b = vector<int>(A[i]);

    sort(b.begin(), b.end());
    
    int x = 0;
    for( ; x < m && a[x] == b[x]; ++x);

    if(x == m){
      continue;
    }

    int y = m - 1;
    for( ; y != 0 && a[y] == b[y]; --y);

    S.insert({x, y});
  }

  int x, y;
  if(S.empty()){
    x = 0, y = 0;
  }
  else{
    tie(x, y) = *S.begin();
  }

  for(int i = 0; i < n; ++i){
    swap(A[i][x], A[i][y]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 1; j < m; ++j){
      if(A[i][j] < A[i][j - 1]){
        printf("-1\n");
        return;
      }
    }
  }

  printf("%d %d\n", x + 1, y + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}