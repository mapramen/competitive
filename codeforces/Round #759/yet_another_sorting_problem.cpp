#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001

int a[N], b[N];
int parent[N], c[N], dc[N];

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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
  c[i] += c[j];
  dc[i] += dc[j];
}

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] = x, b[i] = x;
  }

  for(int i = 1; i <= n; ++i){
    c[i] = 0, dc[i] = 0, parent[i] = i;
  }

  for(int i = 1; i <= n; ++i){
    int x = b[i];
    ++c[x], dc[x] = 1;
  }

  sort(b + 1, b + n + 1);

  for(int i = 1; i <= n; ++i){
    Union(a[i], b[i]);
  }

  bool oddCountPossible = false, evenCountPossible = true;
  for(int i = 1; i <= n; ++i){
    if(parent[i] != i || dc[i] == 0){
      continue;
    }

    if(c[i] == dc[i]){
      if(c[i] % 2 == 0){
        swap(evenCountPossible, oddCountPossible);
      }
      continue;
    }

    evenCountPossible = true;
    oddCountPossible = true;
  }

  return evenCountPossible;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}