#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define H 12
#define M 60
#define S 60
#define MOD (H * M * S)

int HandsCnt(int j, int i, int t){
  int k = 0;
  if(i > j)
    swap(i, j);

  if(i == 0 && j == 59)
    i = 59, j = 0;

  int x = (t - i + S) % S;
  // printf("x %d %d %d %d\n", i, j, t, x);
  k += (x <= abs(j - i));

  int y = (t - i * S + M * S) % (M * S);
  // printf("y %d %d %d %d\n", i, j, t, y);
  k += (y <= abs(j - i) * S);

  int z = (t - i * 12 * S + MOD) % MOD;
  // printf("z %d %d %d %d\n", i, j, t, z);
  k += (z <= abs(j - i) * 12 * S);

  return k;
}

int main(){
  int a, b, h, m, s;

  cin >> h >> m >> s >> a >> b;

  h %= H, a %= H, b %= H;

  int t = h * M * S + m * S + s, T = b * M * S;

  a *= 5, b *= 5;

  int k = HandsCnt(a, b, t);
  k = max(k, 3 - k);
  if(k == 3)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
