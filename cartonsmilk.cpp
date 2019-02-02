#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10000001

int f[N];
pii c[N];
vector<int> ans;

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int x = 1; x <= n; x++){
    int i;
    scanf("%d", &i);
    f[i]++;
  }

  for(int i = 1; i <= m; i++){
    scanf("%d", &c[i].first);
    c[i].second = i;
  }

  for(int i = N - 1; i > 0; i--){
    f[i - 1] += max(0, f[i] - k);
    f[i] = min(f[i], k);
  }

  for(int i = 0; i < N; i++)
    if(f[i] > k){
      printf("-1\n");
      return 0;
    }

  sort(c + 1, c + m + 1);

  for(int i = 0, j = 1, i_next = 0; i < N; i++){
    for( ; f[i] < k && j <= m; j++){
      if(c[j].first < i)
        continue;
      ans.PB(c[j].second);
      f[i]++;
    }

    for(i_next = max(i_next, i + 1); i_next < N && f[i] < k; i_next++){
      int cntTransfered = min(f[i_next], k - f[i]);
      f[i] += cntTransfered;
      f[i_next] -= cntTransfered;
    }
  }

  printf("%d\n", (int)ans.size());

  for(auto x : ans)
    printf("%d ", x);
  printf("\n");

  return 0;
}
