#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001
#define BLOCK_SIZE 100
#define TOTAL_BLOCKS ((N / BLOCK_SIZE) + 1)
#define MOD 998244353

int n, m, a[N], pos[N], pre[N], b[N], dp[N], c[TOTAL_BLOCKS][2 * BLOCK_SIZE + 1], s[TOTAL_BLOCKS];

int GetBlockNumber(int i){
  return i / BLOCK_SIZE + (i % BLOCK_SIZE != 0);
}

void UpdateBlock(int k){
  s[k] = 0;
  for(int i = 0; i <= 2 * BLOCK_SIZE; ++i){
    c[k][i] = 0;
  }

  int l = (k - 1) * BLOCK_SIZE + 1, r = min(n, l + BLOCK_SIZE - 1), &x = s[k], y = BLOCK_SIZE;
  for(int i = r; i >= l; --i){
    x += b[i];
    y += b[i];
    c[k][y] = (c[k][y] + dp[i - 1]) % MOD;
  }

  for(int i = 1; i <= 2 * BLOCK_SIZE; ++i){
    c[k][i] = (c[k][i] + c[k][i - 1]) % MOD;
  }
}

void Update(int i, int x, int curBlockNo){
  if(i == 0){
    return;
  }
  b[i] = x;
  int iBlockNo = GetBlockNumber(i);
  if(iBlockNo != curBlockNo){
    UpdateBlock(iBlockNo);
  }
}

int Query(int i){
  int ans = 0, x = 0, iBlockNo = GetBlockNumber(i);

  int l = (iBlockNo - 1) * BLOCK_SIZE + 1;
  for( ; i >= l; --i){
    x += b[i];
    if(x <= m){
      ans = (ans + dp[i - 1]) % MOD;
    }
  }

  for(--iBlockNo; iBlockNo > 0; x += s[iBlockNo], --iBlockNo){
    int y = BLOCK_SIZE + m - x;
    if(y < 0){
      continue;
    }
    y = min(2 * BLOCK_SIZE, y);
    ans = (ans + c[iBlockNo][y]) % MOD;
  }

  return ans;
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    int iBlockNo = GetBlockNumber(i);
    
    pre[i] = pos[a[i]];
    Update(pre[pre[i]], 0, iBlockNo);
    Update(pre[i], -1, iBlockNo);

    b[i] = 1;
    dp[i] = Query(i);

    pos[a[i]] = i;
    if(i % BLOCK_SIZE == 0){
      UpdateBlock(iBlockNo);
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}