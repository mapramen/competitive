#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

string Solve(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }

  int n = strlen(s);
  reverse(s, s + n);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  int m = 0;
  for(int i = n - 1; i != -1; --i){
    m = ComputeFailure(m, s[i]);
  }

  reverse(s, s + n);

  string t = string(s, n - m);
  reverse(t.begin(), t.end());

  return string(s) + t;
}

int main(){
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}