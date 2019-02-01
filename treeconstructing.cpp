#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 400001

vector< vector<int> > adj(N);
int a[N];

int main(){
  int n, d, k;

  scanf("%d%d%d", &n, &d, &k);

  if(d >= n || (k == 1 && n != 2)){
    printf("NO\n");
    return 0;
  }

  for(int i = 1; i <= d; ++i){
    adj[i].PB(i + 1);
    adj[i + 1].PB(i);
  }

  for(int i = 1; i <= d + 1; ++i){
    a[i] = max(i - 1, d - i + 1);
  }

  for(int j = d + 2, i = 1; j <= n; ++j){
    for( ; i <= n && (i == j || adj[i].size() == k || a[i] == d); ++i);

    if(i > n){
      printf("NO\n");
      return 0;
    }

    adj[i].PB(j);
    adj[j].PB(i);
    a[j] = 1 + a[i];
  }

  printf("YES\n");
  for(int i = 1; i <= n; ++i){
    for(auto j : adj[i]){
      if(j <= i){
        continue;
      }
      printf("%d %d\n", i, j);
    }
  }

  return 0;
}
