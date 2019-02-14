#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

char M[N][N];
string s;

int n, m, a[4], sx, sy;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool Check(){
  for(int i = 0; i < 4; ++i)
    for(int j = i + 1; j < 4; ++j)
      if(a[i] == a[j])
        return 0;

  int x, y, i;
  for(x = sx, y = sy, i = 0; i < s.size() && M[x][y] != 'E' && M[x][y] != '#'; ++i){
    x += dx[a[s[i] - '0']];
    y += dy[a[s[i] - '0']];

    if(x < 0 || y < 0 || x >= n || y >= m)
      return 0;
  }
  return (M[x][y] == 'E');
}

int main(){
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    scanf("%s", M[i]);

  cin >> s;

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(M[i][j] == 'S')
        sx = i, sy = j;

  int ans = 0;
  for(int mask = 0; mask < 256; ++mask){
    for(int x = mask, i = 0; i < 4; ++i, x /= 4)
      a[i] = x % 4;
    ans += Check();
  }

  printf("%d\n", ans);

  return 0;
}
