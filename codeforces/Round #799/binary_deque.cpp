#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int idx[N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i <= n; ++i){
    idx[i] = -1;
  }

  idx[0] = 0;

  int ans = INT_MIN;
  for(int i = 1, s = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s += x;

    if(s >= m){
      ans = max(ans, i - idx[s - m]);
    }

    if(idx[s] == -1){
      idx[s] = i;
    }
  }

  return ans == INT_MIN ? -1 : n - ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}