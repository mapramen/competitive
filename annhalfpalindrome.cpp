#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define M N * N

char s[N];
int a[N], T[2][M], parent[M], b[M], c[M], nxt;
bool p[N][N];

int GetNextNode(int i, int j){
  if(T[j][i] == 0){
    T[j][i] = ++nxt;
    parent[T[j][i]] = i;
    b[T[j][i]] = j;
  }
  return T[j][i];
}

int DFS(int i, int &k){
  if(k <= c[i])
    return i;
  else{
    k -= c[i];
    int ans = 0;
    if(T[0][i])
      ans = DFS(T[0][i], k);
    if(ans == 0 && T[1][i] != 0)
      ans = DFS(T[1][i], k);
    return ans;
  }
}

void Print(int i){
  if(i == 0)
    return ;
  Print(parent[i]);
  printf("%c", 'a' + b[i]);
}

int main(){
  int n, k;

  scanf("%s%d", s, &k);

  n = strlen(s);
  for(int i = 1; i <= n; ++i)
    a[i] = (s[i - 1] - 'a');

  for(int i = 1; i <= n; ++i)
    p[i][i] = 1;

  for(int l = 2; l <= n; ++l){
    for(int i = 1; i <= n - l + 1; ++i){
      int j = i + l - 1;
      p[i][j] = ((a[i] == a[j]) && (l <= 4 || p[i + 2][j - 2]));
    }
  }

  for(int i = 1; i <= n; ++i){
    int x = 0;
    for(int j = i; j <= n; ++j){
      x = GetNextNode(x, a[j]);
      c[x] += p[i][j];
    }
  }

  k = DFS(0, k);
  Print(k);
  printf("\n");

  return 0;
}
