#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

map<int,int> C;
int a[N];

void Add(int x){
  ++C[x];
}

void Remove(int x){
  if(--C[x] == 0){
    C.erase(x);
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1, j = 1; i <= n; ++i){
    for( ; j <= n && C.size() <= k; ++j){
      Add(a[j]);
    }
    ans += (j - i - (C.size() > k));
    Remove(a[i]);
  }

  printf("%lld\n", ans);

  return 0;
}