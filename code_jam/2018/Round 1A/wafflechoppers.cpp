#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

char s[N][N];
int a[N], b[N];

vector<int> GetPartitions(int a[], int n, int h, int k){
  vector<int> v;
  for(int i = 0, c = 0; i < n && v.size() != h + 1; ++i){
    c += a[i];
    if(c > k){
      break;
    }
    if(c == k){
      v.PB(i);
      c = 0;
    }
  }
  return v;
}

bool Solve(){
  int n, m, h, v, t = 0;

  scanf("%d%d%d%d", &n, &m, &h, &v);

  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 0; i < N; ++i)
    a[i] = b[i] = 0;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      int k = s[i][j] == '@';
      a[i] += k;
      b[j] += k;
      t += k;
    }
  }

  if(t % ((h + 1) * (v + 1)) != 0){
    return 0;
  }

  t /= ((h + 1) * (v + 1));

  vector<int> H = GetPartitions(a, n, h, t * (v + 1));
  vector<int> V = GetPartitions(b, m, v, t * (h + 1));

  if(H.size() != h + 1 || V.size() != v + 1){
    return 0;
  }

  for(int i = 0; i < H.size(); ++i){
    for(int j = 0; j < V.size(); ++j){
      int x1 = (i == 0) ? 0 : H[i - 1] + 1;
      int x2 = (i == h) ? n - 1 : H[i];

      int y1 = (j == 0) ? 0 : V[j - 1] + 1;
      int y2 = (j == v) ? m - 1 : V[j];

      int k = 0;
      for(int x = x1; x <= x2; ++x)
        for(int y = y1; y <= y2; ++y)
          k += (s[x][y] == '@');

      if(k != t){
        return 0;
      }
    }
  }

  return 1;
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    bool f = Solve();
    printf("Case #%d: %s\n", k, f == 1 ? "POSSIBLE" : "IMPOSSIBLE");
  }

  return 0;
}
