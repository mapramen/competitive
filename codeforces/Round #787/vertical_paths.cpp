#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int c[N], parent[N];
bool visited[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    c[i] = 0, visited[i] = false;
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &parent[i]);
    if(parent[i] != i){
      ++c[parent[i]];
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (c[i] == 0);
  }

  printf("%d\n", ans);

  for(int i = 1; i <= n; ++i){
    if(c[i] != 0){
      continue;
    }

    vector<int> v;
    for(int x = i; !visited[x]; x = parent[x]){
      v.push_back(x);
      visited[x] = true;
    }
    reverse(v.begin(), v.end());

    printf("%lu\n", v.size());
    for(int x: v){
      printf("%d ", x);
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