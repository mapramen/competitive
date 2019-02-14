#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

int a[N], c[N], dp[N];
bool visited[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    c[a[i]]++;
  }

  for(int i = 1; i <= n; i++){
    for(int x = 0; x < N; x++)
      visited[x] = 0;

    int distinctXOR = 0, cnt = 0, targetCnt = 0;

    for(int j = i; j > 0; j--){
      int x = a[j];
      cnt++;
      distinctXOR ^= (x * (1 - visited[x]));
      targetCnt += (c[x] * (1 - visited[x]));
      visited[x] = 1;

      if(cnt == targetCnt)
        dp[i] = max(dp[i], dp[j - 1] + distinctXOR);
    }

    dp[i] = max(dp[i], dp[i - 1]);
  }

  printf("%d\n", dp[n]);
  
  return 0;
}
