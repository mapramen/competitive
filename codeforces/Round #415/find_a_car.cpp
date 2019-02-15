#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define L 31
#define B 2
#define MOD 1000000007

int c[L + 1][B][B][B], s[L + 1][B][B][B], T[B][B][B];

void Initialise(){
  T[0][0][0] = 0;
  T[0][0][1] = 1;
  T[0][1][0] = 0;
  T[0][1][1] = 0;
  T[1][0][0] = 1;
  T[1][0][1] = 1;
  T[1][1][0] = 0;
  T[1][1][1] = 1;
}

int Query(int n, int m, int k){
  if(n < 0 || m < 0)
    return 0;

  for(int x = 0; x <= L; x++)
    for(int i = 0; i < B; i++)
      for(int j = 0; j < B; j++)
        for(int k = 0; k < B; k++)
          c[x][i][j][k] = s[x][i][j][k] = 0;

  c[0][0][0][0] = 1;
  for(int x = 0; x < L; x++){
    int t1 = ((n & (1 << x)) > 0), t2 = ((m & (1 << x)) > 0), t3 = ((k & (1 << x)) > 0);
    for(int mask = 0; mask < 32; mask++){
      int p1 = ((mask & (1 << 0)) > 0);
      int p2 = ((mask & (1 << 1)) > 0);
      int p3 = ((mask & (1 << 2)) > 0);
      int c1 = ((mask & (1 << 3)) > 0);
      int c2 = ((mask & (1 << 4)) > 0);
      int c3 = (c1 ^ c2);

      int n1 = T[p1][t1][c1], n2 = T[p2][t2][c2], n3 = T[p3][t3][c3];
      c[x + 1][n1][n2][n3] = (c[x + 1][n1][n2][n3] + c[x][p1][p2][p3]) % MOD;
      s[x + 1][n1][n2][n3] = (s[x + 1][n1][n2][n3] + s[x][p1][p2][p3]) % MOD;
      if(c3)
        s[x + 1][n1][n2][n3] = (s[x + 1][n1][n2][n3] + (1ll * (1 << x) * c[x][p1][p2][p3]) % MOD) % MOD;
    }
  }

  return (s[L][0][0][0] + c[L][0][0][0]) % MOD;
}

int FindCars(int x1, int y1, int x2, int y2, int k){
  x1--, y1--, x2--, y2--, k--;
  int ans = (Query(x2, y2, k) + Query(x1 - 1, y1 - 1, k)) % MOD - (Query(x1 - 1, y2, k) + Query(x2, y1 - 1, k)) % MOD;
  ans = (MOD + ans) % MOD;
  return ans;
}

int main(){
  int q;

  Initialise();
  scanf("%d", &q);
  while(q--){
    int x1, x2, y1, y2, k;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    printf("%d\n", FindCars(x1, y1, x2, y2, k));
  }

  return 0;
}
