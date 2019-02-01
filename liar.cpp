#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001
#define M 31
#define P 31
#define INVP 129032259
#define MOD 1000000007

string s, t;
ll p[N], invp[N], S[N], T[N];
int n, m, K, dp[M][N];

void PreProcess(){
  p[0] = invp[0] = 1;
  for(int i = 1; i <= max(n, m); i++){
    p[i] = (P * p[i - 1]) % MOD;
    invp[i] = (INVP * invp[i - 1]) % MOD;
  }
  for(int i = 1; i <= n; i++)
    S[i] = (S[i - 1] + (s[i - 1] - 'a' + 1) * p[i]) % MOD;
  for(int i = 1; i <= m; i++)
    T[i] = (T[i - 1] + (t[i - 1] - 'a' + 1) * p[i]) % MOD;
}

ll GetHash(ll H[], int i, int l){
  int j = i + l - 1;
  ll hsh = (MOD + H[j] - H[i - 1]) % MOD;
  hsh = (hsh * invp[i]) % MOD;
  return hsh;
}

bool Check(int i, int j, int l){
  return (GetHash(S, i, l) == GetHash(T, j, l));
}

int BinarySearch(int i, int j){
  if(i > n || j > m)
    return 0;

  int x = 1, y = min(n - i + 1, m - j + 1), z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(i, j, mid))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  cin >> n >> s >> m >> t >> K;
  PreProcess();

  for(int k = 0; k <= K; k++){
    for(int i = 1; i <= n; i++)
      dp[k][i] = max(dp[k][i], dp[k][i - 1]);

    if(k != K){
      for(int i = 0; i <= n; i++){
        int j = dp[k][i];
        int x = BinarySearch(i + 1, j + 1);
        dp[k + 1][i + x] = max(dp[k + 1][i + x], j + x);
      }
    }
  }

  if(dp[K][n] == m)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
