#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<vector<int>> indxs(N);

int Query(int l, int r, int x, int k){
  vector<int> &a = indxs[x];
  k += (lower_bound(a.begin(), a.end(), l) - a.begin());
  
  if(k > a.size()){
    return -1;
  }

  int i = a[k - 1];
  return i <= r ? i : -1;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    indxs[x].push_back(i);
  }

  while(q--){
    int l, r, x, k;
    scanf("%d%d%d%d", &l, &r, &x, &k);
    printf("%d\n", Query(l, r, x, k));
  }

  return 0;
}