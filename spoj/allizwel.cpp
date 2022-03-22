#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char t[] = "ALLIZZWELL";
int n, m;
char s[N][N];
bool visited[N][N];

bool DFS(int x, int y, int i){
  if(t[i] == '\0'){
    return true;
  }

  if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || s[x][y] != t[i]){
    return false;
  }

  visited[x][y] = true;
  ++i;
  
  for(int dx = -1; dx < 2; ++dx){
    for(int dy = -1; dy < 2; ++dy){
      if((dx != 0 || dy != 0) && DFS(x + dx, y + dy, i)){
        return true;
      }
    }
  }

  visited[x][y] = false;
  return false;
}

bool Solve(){
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      visited[x][y] = false;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(DFS(x, y, 0)){
        return true;
      }
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}