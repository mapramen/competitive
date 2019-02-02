#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define P 31
#define INVP 129032259
#define MOD 1000000007

char s[N], t[N];
ll p[N], invp[N], hsh[N];

void PreProcess(int n){
  p[0] = 1;
  invp[0] = 1;
  for(int i = 1; i < N; ++i){
    p[i] = (P * p[i - 1]) % MOD;
    invp[i] = (INVP * invp[i - 1]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    hsh[i] = (hsh[i - 1] + (t[i - 1] - 'a' + 1) * p[i]) % MOD;
  }
}

ll SubstringHash(int i, int j){
  return ((MOD + hsh[j] - hsh[i - 1]) * invp[i - 1]) % MOD;
}

bool Check(int &j, int m, int length, ll &targetHash){
  if(j + length - 1 > m){
    return 0;
  }

  ll substringHash = SubstringHash(j, j + length - 1);

  if(targetHash < 0 || targetHash == substringHash){
    targetHash = substringHash;
    j += length;
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  int ans = 0;

  scanf("%s", s);
  scanf("%s", t);

  int zeroCount = 0, oneCount = 0;
  int n = strlen(s), m = strlen(t);

  for(int i = 0; i < n; ++i){
    zeroCount += (s[i] == '0');
    oneCount += (s[i] == '1');
  }

  PreProcess(m);

  for(int zeroLength = 1; zeroCount * zeroLength < m; ++zeroLength){
    if((m - zeroCount * zeroLength) % oneCount != 0){
      continue;
    }

    int oneLength = (m - zeroCount * zeroLength) / oneCount;

    ll zeroHash = -1;
    ll oneHash = -1;

    bool valid = 1;
    for(int i = 0, j = 1; i < n && valid == 1; ++i){
      if(s[i] == '0'){
        valid = Check(j, m, zeroLength, zeroHash);
      }
      else{
        valid = Check(j, m, oneLength, oneHash);
      }
    }

    ans += (valid && zeroHash >= 0 && oneHash >= 0 && zeroHash != oneHash);
  }

  printf("%d\n", ans);

  return 0;
}
