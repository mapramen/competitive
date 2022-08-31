#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001
#define B 30

int a[N], b[N], parent[N];

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

int Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j){
    swap(i, j);
  }

  if(i == 0 || i == j){
    return j;
  }


  parent[j] = i;
  return i;
}

bool IsConnected(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  for(int k = 0; k <= B; ++k){
    for(int i = 1, x = 0; i <= n; ++i){
      if((b[i] & (1 << k)) == 0){
        continue;
      }
      x = Union(x, i);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(Find(i) != 1){
      return false;
    }
  }

  return true;
}

void Increment(int i){
  ++b[i];
}

void Decrement(int i){
  --b[i];
}

void Solve(int n){
  if(IsConnected(n)){
    return;
  }

  for(int i = 1; i <= n; ++i){
    Increment(i);
    if(IsConnected(n)){
      return;
    }
    Decrement(i);
  }

  for(int i = 1; i <= n; ++i){
    Decrement(i);
    if(IsConnected(n)){
      return;
    }
    Increment(i);
  }

  int k = 0;
  for(int i = 1; i <= n; ++i){
    k = max(k, __builtin_ctz(b[i]));
  }

  int x = 0, y = 0;
  for(int i = 1; i <= n && y == 0; ++i){
    if(__builtin_ctz(b[i]) != k){
      continue;
    }
    if(x == 0){
      x = i;
    }
    else{
      y = i;
    }
  }

  Increment(x), Decrement(y);
}

void PrintAns(int n){
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += abs(b[i] - a[i]);
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", b[i]);
  }
  printf("\n");
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    b[i] = max(1, a[i]);
  }

  Solve(n);
  PrintAns(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}