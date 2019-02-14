#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int p[N], cnt[N];
bool visited[N];
bitset<N> dp;

int main(){
  int n, k, ansMin, ansMax;
  vector<int> a;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++)
    scanf("%d", &p[i]);

  for(int i = 1; i <= n; i++){
    if(visited[i])
      continue;

    int l = 0;
    for(int j = i; visited[j] == 0; j = p[j]){
      visited[j] = 1;
      l++;
    }

    cnt[l]++;
  }

  int odd = 0, even = 0;
  for(int i = 1; i <= n; i++){
    odd += cnt[i] * (i % 2);
    even += cnt[i] * (i / 2);
  }

  for(int i = 1; i + i < n; i++){
    if(cnt[i] <= 2)
      continue;

    int x = (cnt[i] - 1) / 2;
    cnt[i + i] += x;
    cnt[i] -= (x + x);
  }

  dp[0] = 1;

  for(int i = 1; i <= k; i++)
    for(int j = 0; j < cnt[i]; j++)
      dp |= (dp << i);

  if(dp.test(k))
    ansMin = k;
  else
    ansMin = k + 1;

  ansMax = 2 * min(k, even);
  k -= min(k, even);
  ansMax += min(k, odd);

  printf("%d %d\n", ansMin, ansMax);

  return 0;
}
