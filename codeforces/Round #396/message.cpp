#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define B 26
#define MOD 1000000007

int a[B], cnt[B][N], dp1[N], dp2[N], dp3[N];

bool Check(int i, int j){
  int l = j - i + 1;
  bool ans = 1;

  for(int k = 0; k < B; k++){
    if(cnt[k][j] - cnt[k][i - 1] > 0 && a[k] < l)
      ans = 0;
  }

  return ans;
}

int main(){
  int n;
  string s;

  cin >> n >> s;

  for(int i = 0; i < B; i++)
    cin >> a[i];

  for(int i = 1; i <= n; i++){
    int j = s[i - 1] - 'a';
    cnt[j][i]++;

    for(int k = 0; k < B; k++)
      cnt[k][i] += cnt[k][i - 1];
  }

  for(int i = 0; i <= n; i++)
    dp3[i] = n;

  dp1[0] = 1, dp3[0] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      if(Check(j, i) == 0)
        continue;
      dp1[i] = (dp1[i] + dp1[j - 1]) % MOD;
      dp2[i] = max(dp2[i], max(i - j + 1, dp2[j - 1]));
      dp3[i] = min(dp3[i], 1 + dp3[j - 1]);
    }
  }

  printf("%d\n%d\n%d\n", dp1[n], dp2[n], dp3[n]);

  return 0;
}
