#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 2501
#define P 37
#define M 100001
#define MOD 1000000007

int n, m, q, p[M], T[N][N];
map< tiiii, int > S;

void Initialise(){
  p[0] = 1;
  for(int i = 1; i < M; ++i)
    p[i] = (1ll * P * p[i - 1]) % MOD;
  for(int i = 1; i < M; ++i)
    p[i] = (1ll * i * p[i]) % MOD;
}

void UpdateX(int x, int y, int val){
  val = (MOD + val) % MOD;
  for(int i = x; i <= n; i += (i & -i))
    for(int j = y; j <= m; j += (j & -j))
      T[i][j] = (T[i][j] + val) % MOD;
}

void Update(int x1, int y1, int x2, int y2, int val){
  UpdateX(x1, y1, val);
  UpdateX(x1, y2 + 1, -val);
  UpdateX(x2 + 1, y1, -val);
  UpdateX(x2 + 1, y2 + 1, val);
}

int Query(int x, int y){
  int ans = 0;
  for(int i = x; i > 0; i -= (i & -i))
    for(int j = y; j > 0; j -= (j & -j))
      ans = (ans + T[i][j]) % MOD;
  return ans;
}

int main(){
  scanf("%d%d%d", &n, &m, &q);

  Initialise();

  for(int x = 1; x <= q; ++x){
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);

    if(t <= 2){
      if(x1 > x2)
        swap(x1, x2);

      if(y1 > y2)
        swap(y1, y2);

      tiiii a = MT(x1, y1, x2, y2);

      if(S.find(a) == S.end())
        S[a] = x;

      int k = S[a];

      if(t == 1)
        Update(x1, y1, x2, y2, p[k]);
      else
        Update(x1, y1, x2, y2, -p[k]);
    }
    else{
      if(Query(x1, y1) == Query(x2, y2))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }

  return 0;
}
