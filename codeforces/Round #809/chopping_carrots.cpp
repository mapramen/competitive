#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int start_index[N], next_index[N];
int X, Y;

void Reset(){
  for(int x = 0; x < N; ++x){
    start_index[x] = 0, next_index[x] = 0;
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
  if(start_index[x] == a){
    return;
  }
  
  next_index[a] = start_index[x];
  start_index[x] = a;
  Y = max(Y, x);
}

int GetAns(){
  for( ; X < Y && start_index[X] == 0; ++X);
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
    while(start_index[x - 1] != 0){
      int a = start_index[x - 1];
      start_index[x - 1] = next_index[a];
      Add(k, a, x);
    }
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