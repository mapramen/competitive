#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500
#define MOD 1000000007
#define B 5

char s[N + 1];
int A[N][2 * N];
int inv5[B] = {0, 1, 3, 2, 4};

int main(){
  int n, m, q, rank, ans;

  scanf("%d%d", &m, &n);
  for(int j = 0; j < m; ++j){
    scanf("%s", s);
    for(int i = 0; i < n; ++i)
      A[i][j] = (s[i] - 'a');
  }

  scanf("%d", &q);
  for(int j = m; j < m + q; ++j){
    scanf("%s", s);
    for(int i = 0; i < n; ++i)
      A[i][j] = (s[i] - 'a');
  }

  rank = 0;
  for(int row = 0, col = 0; row < n && col < m; ++col){
    int cur = row;
    for(int i = row; i < n; ++i)
      if(A[i][col] > A[cur][col])
        cur = i;

    if(cur != row){
      for(int j = col; j < m + q; ++j)
        swap(A[cur][j], A[row][j]);
    }

    if(A[row][col] == 0)
      continue;

    for(int i = row + 1; i < n; ++i){
      if(A[i][col] == 0)
        continue;
      int val = (A[i][col] * inv5[A[row][col]]) % B;
      for(int j = col; j < m + q; ++j)
        A[i][j] = (B + A[i][j] - (val * A[row][j]) % B) % B;
    }

    ++rank;
    ++row;
  }

  ans = 1;
  for(int i = 0; i < m - rank; ++i)
    ans = (1ll * B * ans) % MOD;

  int target_last_non_empty_row = -1;
  for(int i = n - 1; i > -1 && target_last_non_empty_row == -1; --i)
    for(int j = i; j < m && target_last_non_empty_row == -1; ++j)
      if(A[i][j])
        target_last_non_empty_row = i;

  for(int j = m; j < m + q; ++j){
    int current_last_non_empty_row = -1;
    for(int i = n - 1; i > -1 && current_last_non_empty_row == -1; --i)
      if(A[i][j])
        current_last_non_empty_row = i;
    if(current_last_non_empty_row > target_last_non_empty_row)
      printf("0\n");
    else
      printf("%d\n", ans);
  }

  return 0;
}
