#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001
#define K 11
#define M (1 << K)
#define B 6

int a[N], d[M], parentMove[M], checkMask;
vector< tiii > ans;
tiii moveBits[M];

void Initialise(int m, int c){
  vector<int> moves;
  for(int i = 0; i < m; ++i){
    for(int j = i + 1; j < m; ++j){
      int k = 2 * j - i;
      if(k >= m){
        continue;
      }
      int mask = (1 << i) + (1 << j) + (1 << k);
      moves.PB(mask);
      moveBits[mask] = MT(i, j, k);
    }
  }

  for(int i = 1; i < M; ++i){
    d[i] = -1;
    parentMove[i] = -1;
  }

  checkMask = (1 << c) - 1;

  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    for(auto j : moves){
      int k = ((i ^ j) & checkMask);
      if(d[k] == -1 || d[k] > 1 + d[i]){
        d[k] = 1 + d[i];
        parentMove[k] = j;
        Q.push(k);
      }
    }
  }
}

bool Fix(int i, int l){
  int mask = 0;
  for(int j = i - l + 1; j <= i; ++j){
    mask = 2 * mask + a[j];
  }

  if(d[(mask & checkMask)] < 0){
    return false;
  }

  while((mask & checkMask)){
    int move = parentMove[(mask & checkMask)], x, y, z;
    tie(x, y, z) = moveBits[move];
    ans.PB(MT(i - z, i - y, i - x));
    mask ^= move;
  }

  for(int j = i; j >= i - l + 1; --j, mask /= 2){
    a[j] = (mask % 2);
  }

  return true;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  if(n > K){
    for(Initialise(K, B); n > K; n -= B){
      Fix(n, K);
    }
    n = max(n, K);
  }

  Initialise(n, n);

  if(!Fix(n, n)){
    printf("NO\n");
    return 0;
  }

  printf("YES\n%lu\n", ans.size());
  for(auto t : ans){
    int x, y, z;
    tie(x, y, z) = t;
    printf("%d %d %d\n", x, y, z);
  }

  return 0;
}
