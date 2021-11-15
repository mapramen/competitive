#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 102
#define B 10

bool  M[B][B];
int x[N], y[N];
int dx[] = {1, -1, -1, 1}, dy[] = {1, 1, -1, -1};

int Compress(int n, int m, int x[]){
  vector<int> v{0, m - 1};
  for(int i = 0; i < n; ++i){
    v.PB(x[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < n; ++i){
    x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
  }
  return v.size();
}

void Reset(){
  for(int i = 0; i < B; ++i){
    for(int j = 0; j < B; ++j){
      M[i][j] = 0;
    }
  }
}

void Fill(int n, int m, int i, int k){
  for(int p = x[i]; p >= 0 && p < n; p += dx[k]){
    for(int q = y[i]; q >= 0 && q < m; q += dy[k]){
      M[p][q] = 1;
    }
  }
}

bool Check(int n, int m){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(M[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

bool Solve(){
  int n, m, k;

  scanf("%d%d", &k, &n);

  for(int i = 0; i < k; ++i){
    scanf("%d%d", &x[i], &y[i]);
  }

  if(k >= 4){
    return 1;
  }

  tie(n, m) = MP(Compress(k, n, x), Compress(k, n, y));

  for(int mask = 0; mask < 64; ++mask){
    int currentMask = mask;
    Reset();
    for(int i = 0; i < k; ++i){
      Fill(n, m, i, currentMask % 4);
      currentMask /= 4;
    }
    if(Check(n, m)){
      return 1;
    }
  }

  return 0;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "yes" : "no");
  }

  return 0;
}
