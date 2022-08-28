#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 401

int p[N], f[N];
char s[N];

int ComputeFailure(string& p, int k, char c){
  while(k != 0 && p[k] != c){
    k = f[k];
  }
  return k + (p[k] == c);
}

int GetPeriod(string s){
  int n = s.size();

  s += s;
  for(int i = 2; i <= s.size(); ++i){
    f[i] = ComputeFailure(s, f[i - 1], s[i - 1]);
  }

  for(int i = n + 1; i <= s.size(); ++i){
    if(f[i] >= n){
      return i - n;
    }
  }

  return n;
}

ull Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  vector<int> a;
  for(int i = 1; i <= n; ++i){
    if(p[i] == -1){
      continue;
    }

    string t;
    for(int j = i; p[j] != -1; ){
      t.push_back(s[j - 1]);
      int k = p[j];
      p[j] = -1;
      j = k;
    }

    a.push_back(GetPeriod(t));
  }

  ull ans = 1;
  for(int p = 2; p <= n; ++p){
    int k = 0;
    for(int& x: a){
      int kx = 0;
      while(x % p == 0){
        x /= p, ++kx;
      }
      k = max(k, kx);
    }

    while(k--){
      ans *= p;
    }
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%llu\n", Solve());
  }
  return 0;
}