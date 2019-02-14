#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N), divisors(N);
int a[N], d[N], c[N], ans[N];

void PreProcess(){
  for(int i = 1; i < N; ++i)
    for(int j = i; j < N; j += i)
      divisors[j].PB(i);
}

void DFS(int i, int p){
  d[i] = d[p] + 1;
  ans[i] = __gcd(a[i], ans[p]);

  for(auto j : divisors[a[i]])
    ++c[j];

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
  }

  ans[i] = ans[p];
  for(auto j : divisors[a[i]]){
    if(d[i] - c[j] <= 1)
      ans[i] = max(ans[i], j);
    --c[j];
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  PreProcess();
  DFS(1, 0);

  for(int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
