#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 600

int A[N][N], S[N][N], c[N];
char s[N];

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; ++i){
      scanf("%s", s);
      for(int j = 1; j <= m; ++j){
        A[i + j - 1][i + m - j] = s[j - 1] - '0';
      }
    }

    int k = n + m - 1;
    for(int i = 1; i <= k; ++i){
      for(int j = 1; j <= k; ++j){
        S[i][j] = A[i][j] + S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1];
      }
    }

    for(int i = 1; i <= k; ++i){
      for(int j = 1; j <= k; ++j){
        if(A[i][j] == 0){
          continue;
        }
        for(int x = 0; x < k; ++x){
          int x1 = max(1, i - x), y1 = max(1, j - x), x2 = min(k, i + x), y2 = min(k, j + x);
          c[x] += (S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1]);
        }
      }
    }

    for(int i = k - 1; i > 0; --i){
      c[i] -= c[i - 1];
    }

    for(int i = 1; i < k; ++i){
      printf("%d ", c[i] / 2);
    }
    printf("\n");

    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        A[i][j] = 0;
        S[i][j] = 0;
      }
      c[i] = 0;
    }
  }

  return 0;
}
