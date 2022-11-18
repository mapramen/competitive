#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 17

ll a[N], lg[N], T[LOGN][N];
deque<int> Q;

void SlidingWindowMinimum(int n, int k){
  for(int i = 1; i <= n; ++i){
    while(!Q.empty() && a[Q.back()] >= a[i]){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() >= k){
      Q.pop_front();
    }

    Q.push_back(i);

    T[0][i] = a[Q.front()];
  }

  Q.clear();
}

void PreProcess(int n, int k){
  SlidingWindowMinimum(n, k);
  
  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)); j <= n; ++i, ++j){
      T[k][i] = max(T[k - 1][i], T[k - 1][j]);
    }
  }
}

ll Query(int i, int j){
  int k = lg[j - i + 1];
  return max(T[k][i], T[k][j - (1 << k) + 1]);
}

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  PreProcess(n, k);

  int q;
  scanf("%d", &q);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    i += k - 1;
    printf("%s\n", i > j ? "Impossible" : to_string(Query(i, j)).c_str());
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}