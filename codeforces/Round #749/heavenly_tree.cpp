#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bool marked[N];

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    marked[b] = true;
  }

  int root = 1;
  for( ; marked[root]; ++root);

  for(int i = 1; i <= n; ++i){
    marked[i] = false;
    if(i == root){
      continue;
    }
    printf("%d %d\n", root, i);
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