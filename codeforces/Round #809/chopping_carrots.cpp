#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> V(N);
int X, Y;

void Reset(){
  for(int x = 0; x < N; ++x){
    V[x].clear();
  }
  X = 0, Y = 0;
}

int GetAdjustedValue(int k, int a, int x){
  int p = x == 0 ? k : min(k, a / x);
  p = max(1, p);
  return a / p;
}

void Add(int k, int a, int x){
  x = GetAdjustedValue(k, a, x);
  V[x].push_back(a);
  Y = max(Y, x);
}

int GetAns(){
  for( ; X < Y && V[X].empty(); ++X);
  return Y - X;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  Reset();

  int m = INT_MAX;
  while(n--){
    int a;
    scanf("%d", &a);
    Add(k, a, 0);
    m = min(m, a);
  }

  int ans = GetAns();
  for(int x = 1; x <= m; ++x){
    for(int a: V[x - 1]){
      Add(k, a, x);
    }
    V[x - 1].clear();
    V[x - 1].shrink_to_fit();
    ans = min(ans, GetAns());
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}