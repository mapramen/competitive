#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

bool visited[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    visited[i] = false;
  }

  printf("%d\n", 2);
  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }

    for(int j = i; j <= n && !visited[j]; j += j){
      printf("%d ", j);
      visited[j] = true;
    }
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}