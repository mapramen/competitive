#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 251

int n, m, k, A[N], B[N];

int MaxMatching(int x){
  int ans = 0;
  ll y = x + 2 * k;
  for(int i = 1, j = 1; i <= n && j <= m; ++i){
    for( ; j <= m && B[j] - A[i] < x; ++j);
    if(j > m){
      continue;
    }
    if(B[j] - A[i] <= y){
      ++ans;
      ++j;
    }
  }
  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int ans = 0;
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &A[i]);
    }

    for(int j = 1; j <= m; ++j){
      scanf("%d", &B[j]);
    }

    sort(A + 1, A + n + 1);
    sort(B + 1, B + m + 1);

    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        ans = max(ans, MaxMatching(B[j] - A[i]));
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
