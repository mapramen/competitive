#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 110

vector< vector<int> > adj(N);
int inTime[N], outTime[N], d[N], M[2 * N][2 * N], timer;
bool visited[N];

int DFS(int i, int p = 0){
  int c = 1;
  visited[i] = 1;
  d[i] = 1 + d[p];
  inTime[i] = ++timer;

  for(auto j : adj[i]){
    if(visited[j]){
      continue;
    }
    c += DFS(j, i);
    ++timer;
  }

  outTime[i] = timer;

  int x = d[i], y1 = inTime[i], y2 = outTime[i];
  M[x][y1] = 1;
  M[x][y2 + 1] = 1;

  return c;
}

int main(){
  int n, m;

  cin >> n >> m;

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  if(m != n - 1 || DFS(1) < n){
    printf("-1\n");
    return 0;
  }

  int A = 0, B = timer;
  for(int i = 1; i <= n; ++i){
    A = max(A, d[i]);
  }

  for(int i = 1; i <= A; ++i){
    for(int j = 1; j <= B; ++j){
      M[i][j] += (M[i][j - 1] + M[i - 1][j] - M[i - 1][j - 1]);
    }
  }

  printf("%d %d\n", A, B);
  for(int i = 1; i <= A; ++i){
    for(int j = 1; j <= B; ++j){
      putchar('0' + M[i][j] % 2);
    }
    putchar('\n');
  }

  return 0;
}
