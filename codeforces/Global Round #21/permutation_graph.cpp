#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 250001

int a[N], prefix_min[N], prefix_max[N], suffix_min[N], suffix_max[N];

void PreProcess(int n){
  prefix_min[1] = 1, prefix_max[1] = 1;
  for(int i = 2; i <= n; ++i){
    prefix_min[i] = min(make_pair(a[prefix_min[i - 1]], prefix_min[i - 1]), make_pair(a[i], i)).second;
    prefix_max[i] = max(make_pair(a[prefix_max[i - 1]], prefix_max[i - 1]), make_pair(a[i], i)).second;
  }

  suffix_min[n] = n, suffix_max[n] = n;
  for(int i = n - 1; i > 0; --i){
    suffix_min[i] = min(make_pair(a[suffix_min[i + 1]], suffix_min[i + 1]), make_pair(a[i], i)).second;
    suffix_max[i] = max(make_pair(a[suffix_max[i + 1]], suffix_max[i + 1]), make_pair(a[i], i)).second;
  }
}

int Solve(int n, bool query_max, int l, int r){
  if(r < l){
    return 0;
  }

  if(l == 1){
    int k = query_max ? prefix_max[r] : prefix_min[r];
    return 1 + Solve(n, !query_max, l, k - 1);
  }
  else{
    int k = query_max ? suffix_max[l] : suffix_min[l];
    return 1 + Solve(n, !query_max, k + 1, n);
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  int i = prefix_max[n];
  return Solve(n, false, 1, i - 1) + Solve(n, false, i + 1, n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}