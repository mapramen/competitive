#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000005
#define MOD 998244353

char s[N], l[N], r[N];
int L[2 * N], R[2 * N], dp[2 * N];

void ZAlgorithm(char pattern[], char text[], int Z[]){
  string s = string(pattern) + "$" + string(text);

  for(int L = 0, R = 0, i = 1, n = s.size(); i < n; ++i){
    if(i > R){
      for(L = R = i; R < n && s[R - L] == s[R]; ++R);
      Z[i] = R - L;
      --R;
    }
    else{
      int k = i - L;
      if(Z[k] < R - i + 1){
        Z[i] = Z[k];
      }
      else{
        for(L = i; R < n && s[R - L] == s[R]; ++R);
        Z[i] = R - L;
        --R;
      }
    }
  }

  int m = strlen(pattern), n = strlen(text);
  for(int i = 0; i < n; ++i){
    Z[i] = Z[i + m + 1];
  }
}

bool CheckGE(char t[], char s[], int Z[], int m, int n, int i){
  return (Z[i] == m || (i + m <= n && s[i + Z[i]] >= t[Z[i]] && (m == 1 || s[i] != '0')));
}

bool CheckLE(char t[], char s[], int Z[], int m, int n, int i){
  return (Z[i] == m || (i + m <= n && s[i + Z[i]] <= t[Z[i]] && (m == 1 || s[i] != '0')));
}

int main(){
  scanf("%s%s%s", s, l, r);

  ZAlgorithm(l, s, L);
  ZAlgorithm(r, s, R);

  int n = strlen(s), x = strlen(l), y = strlen(r);
  dp[n] = 1;

  for(int i = n - 1, t = 0; i > -1; --i){
    bool b = (s[i] != '0' && (y - x > 1));

    t = (t + dp[i + x + 1]) % MOD;
    t = (t + MOD - dp[i + y]) % MOD;

    int val = 0;

    if(x < y){
      if(CheckGE(l, s, L, x, n, i)){
        val += dp[i + x];
      }

      if(CheckLE(r, s, R, y, n, i)){
        val += dp[i + y];
      }
    }
    else{
      if(CheckGE(l, s, L, x, n, i) && CheckLE(r, s, R, y, n, i)){
        val += dp[i + x];
      }
    }

    dp[i] = (b * t + (val % MOD)) % MOD;
  }

  cout << dp[0] << '\n';

  return 0;
}
