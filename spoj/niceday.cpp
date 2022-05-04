#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

pii a[N];
int T[N];

void Reset(){
  for(int i = 1; i < N; ++i){
    T[i] = INT_MAX;
  }
}

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] = min(T[i], x);
  }
}

int Query(int i){
  int ans = INT_MAX;
  for( ; i > 0; i -= (i & -i)){
    ans = min(ans, T[i]);
  }
  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  for(int i = 1; i <= n; ++i){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    a[x] = {y, z};
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += Query(a[i].first) > a[i].second;
    Update(a[i].first, a[i].second);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}