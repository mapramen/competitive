#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 8
#define M (1 << B)
#define N 1002

int freq[N][B], freq_occur[N][B], dp[M];

bool BasicCheck(int k, int mask, int n){
  for(int i = 1; i < M; i++)
    dp[i] = n + 1;

  for(int i = 0; i < M; i++){
    for(int j = 0; j < B; j++){
      if((i & (1 << j)))
        continue;

      int i_new = (i | (1 << j));
      int ans = max(dp[i], freq_occur[freq[dp[i]][j] + k + ((mask & (1 << j)) != 0)][j]);
      dp[i_new] = min(dp[i_new], ans);
    }
  }

  return (dp[M - 1] != (n + 1));
}

bool Check(int len, int n){
  int k = len / B;
  len %= B;
  bool ans = 0;

  for(int mask = 0; mask < M && ans == 0; mask++)
    if(__builtin_popcount(mask) == len)
      ans |= BasicCheck(k, mask, n);

  return ans;
}

int BinarySearch(int n){
  int x = 0, y = n, ans = 0;

  while(x <= y){
    int mid = x + (y - x) / 2;

    if(Check(mid, n)){
      ans = mid;
      x = mid + 1;
    }
    else
      y = mid - 1;
  }

  return ans;
}

int main(){
  int n, i, j, k, a;

  scanf("%d", &n);

  for(i = 1; i <= n + 1; i++)
    for(j = 0; j < B; j++)
      freq_occur[i][j] = n + 1;

  for(i = 1; i <= n; i++){
    scanf("%d", &a);
    a--;

    for(j = 0; j < B; j++)
      freq[i][j] = freq[i - 1][j];

    freq[i][a]++;

    for(j = 0; j < B; j++){
      k = freq[i][j];
      freq_occur[k][j] = min(i, freq_occur[k][j]);
    }
  }

  printf("%d\n", BinarySearch(n));

  return 0;
}
