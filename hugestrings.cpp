#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201
#define B 10
#define M (1 << (B + 1))

bool c[N][M];
string s[N];

void FillMask(string s, bool c[]){
  for(int i = 0; i < s.size(); ++i){
    for(int j = i, k = 0, x = 1; j < s.size() && k < B; ++j, ++k){
      x = 2 * x + (s[j] - '0');
      c[x] = 1;
    }
  }
}

void CopyMask(bool d[], bool s[]){
  for(int i = 0; i < M; ++i)
    d[i] |= s[i];
}

int main(){
  int n, m;

  cin >> n;

  for(int i = 1; i <= n; ++i){
    cin >> s[i];
    FillMask(s[i], c[i]);

    if(s[i].size() > 20)
      s[i] = string(s[i], 0, 10) + string(s[i], s[i].size() - 10, 10);
  }

  cin >> m;

  for(int j = 1, i = n + 1; j <= m; ++j, ++i){
    int x, y;
    cin >> x >> y;

    string t = string(s[x], max(0, (int)s[x].size() - 10), 10) + string(s[y], 0, 10);
    FillMask(t, c[i]);
    CopyMask(c[i], c[x]);
    CopyMask(c[i], c[y]);

    s[i] = s[x] + s[y];

    if(s[i].size() > 20)
      s[i] = string(s[i], 0, 10) + string(s[i], s[i].size() - 10, 10);

    int ans = 9;
    for( ; ans > 0; --ans){
      int cnt = 0;
      for(int k = (1 << ans); k < (1 << (1 + ans)) && c[i][k] == 1; ++k)
        cnt += c[i][k];
      if(cnt == (1 << ans))
        break;
    }

    printf("%d\n", ans);
  }

  return 0;
}
