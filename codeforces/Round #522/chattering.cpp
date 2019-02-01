#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 18
#define M (2 * N)

int a[N], lg[M], leftEnd[M], rightEnd[M], ans[M], leftEndTable[LOGN][M], rightEndTable[LOGN][M], leftEndSparseTable[LOGN][M], rightEndSparseTable[LOGN][M];

void BuildSparseTables(int n, int k){
  for(int i = 0; i < n; ++i){
    leftEndSparseTable[0][i] = leftEndTable[k][i];
    rightEndSparseTable[0][i] = rightEndTable[k][i];
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 0, j = (1 << (k - 1)); j < n; ++i, ++j){
      leftEndSparseTable[k][i] = min(leftEndSparseTable[k - 1][i], leftEndSparseTable[k - 1][j]);
      rightEndSparseTable[k][i] = max(rightEndSparseTable[k - 1][i], rightEndSparseTable[k - 1][j]);
    }
  }
}

int LeftEndRMQ(int i, int j){
  int k = lg[j - i + 1];
  return min(leftEndSparseTable[k][i], leftEndSparseTable[k][(j - (1 << k) + 1)]);
}

int RightEndRMQ(int i, int j){
  int k = lg[j - i + 1];
  return max(rightEndSparseTable[k][i], rightEndSparseTable[k][(j - (1 << k) + 1)]);
}

void Initialize(int n, int m){
  for(int i = 2; i <= m; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int i = 0; i < m; ++i){
    leftEndTable[0][i] = max(0, i - a[(i % n)]);
    rightEndTable[0][i] = min(m - 1, i + a[(i % n)]);
  }
}

void PreProcess(int m){
  for(int k = 1; k < LOGN; ++k){
    BuildSparseTables(m, k - 1);
    for(int i = 0; i < m; ++i){
      leftEndTable[k][i] = LeftEndRMQ(leftEndTable[k - 1][i], rightEndTable[k - 1][i]);
      rightEndTable[k][i] = RightEndRMQ(leftEndTable[k - 1][i], rightEndTable[k - 1][i]);
    }
  }
}

void Solve(int n, int m){
  for(int i = 0; i < m; ++i){
    leftEnd[i] = i;
    rightEnd[i] = i;
  }

  for(int k = LOGN - 1; k > -1; --k){
    BuildSparseTables(m, k);
    for(int i = 0; i < m; ++i){
      int l = LeftEndRMQ(leftEnd[i], rightEnd[i]), r = RightEndRMQ(leftEnd[i], rightEnd[i]);
      if(r - l + 1 < n){
        ans[i] += (1 << k);
        leftEnd[i] = l;
        rightEnd[i] = r;
      }
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  if(n == 1){
    printf("0\n");
    return 0;
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int m = 2 * n;

  Initialize(n, m);
  PreProcess(m);
  Solve(n, m);

  for(int i = 0; i < n; ++i){
    printf("%d ", 1 + min(ans[i], ans[n + i]));
  }
  printf("\n");

  return 0;
}
