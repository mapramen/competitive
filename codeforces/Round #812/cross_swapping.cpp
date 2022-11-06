#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000

int parent[2 * N], a[N][N];

void Reset(int n){
  for(int i = 0; i < 2 * n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

void TryUnion(int i, int j, bool opposite){
  int x = 2 * i, y = 2 * j;
  if(opposite){
    y ^= 1;
  }

  int a = Find(x), b = Find(y);
  if(a != b && (a / 2) == (b / 2)){
    return;
  }

  Union(x, y);
  Union(x ^ 1, y ^ 1);
}

void Operate(int n, int k){
  for(int i = 0; i < n; ++i){
    swap(a[i][k], a[k][i]);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  Reset(n);

  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      if(a[i][j] == a[j][i]){
        continue;
      }
      TryUnion(i, j, a[j][i] < a[i][j]);
    }
  }

  for(int x = 0; x < 2 * n; x += 2){
    int p = Find(x);
    if(p % 2 == 1){
      Operate(n, x / 2);
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ", a[i][j]);
    }
    printf("\n");
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