#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char ch[2], s[N][N];
int n, m, sx, sy;
bool visited[N][N];

char ReadChar(){
  scanf("%s", ch);
  return ch[0];
}

bool DFS(int x, int y, int k){
  if(x == sx && y == sy && visited[x][y]){
    return k <= 0;
  }

  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '*' || visited[x][y]){
    return false;
  }

  visited[x][y] = true;
  bool ans = DFS(x - 1, y, k - 1) || DFS(x, y - 1, k - 1) || DFS(x, y + 1, k - 1) || DFS(x + 1, y, k - 1);
  visited[x][y] = false;
  return ans;
}

int main(){
  int k;
  scanf("%d%d%d%d%d", &n, &m, &k, &sx, &sy);
  --sx, --sy;

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      s[x][y] = ReadChar();
    }
  }

  printf("%s\n", DFS(sx, sy, k) ? "YES" : "NO");
  
  return 0;
}