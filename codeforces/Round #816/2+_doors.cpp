#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 30

vector<vector<int>> edge_nos(N);
int a[N], edge_xor[N], edge_value[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    a[i] = (1 << 30) - 1;
  }

  for(int e = 1; e <= q; ++e){
    int i, j, x;
    scanf("%d%d%d", &i, &j, &x);

    a[i] &= x, a[j] &= x;
    edge_nos[i].push_back(e), edge_nos[j].push_back(e);

    edge_xor[e] = i ^ j, edge_value[e] = x;
  }

  for(int i = 1; i <= n; ++i){
    for(int k = B - 1; k != -1; --k){
      if((a[i] & (1 << k)) == 0){
        continue;
      }

      bool should_set = false;
      for(int e: edge_nos[i]){
        int j = edge_xor[e] ^ i, x = edge_value[e];
        if((x & (1 << k)) != 0 && ((a[j] & (1 << k)) == 0 || j == i)){
          should_set = true;
        }
      }

      if(!should_set){
        a[i] ^= (1 << k);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}