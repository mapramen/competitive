#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

ll T[N][N];

void Update(ll T[], int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int i, int j, int x){
  for( ; i < N; i += (i & -i)){
    Update(T[i], j, x);
  }
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int i, int j){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += Query(T[i], j);
  }
  return ans;
}

ll Query(int x1, int y1, int x2, int y2){
  return Query(x2, y2) + Query(x1 - 1, y1 - 1) - Query(x2, y1 - 1) - Query(x1 - 1, y2);
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x;
      scanf("%d", &x);
      Update(i, j, x);
    }
  }

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int i, j, x;
      scanf("%d%d%d", &i, &j, &x);
      Update(i, j, x);
    }
    else{
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      printf("%lld\n", Query(x1, y1, x2, y2));
    }
  }

  return 0;
}