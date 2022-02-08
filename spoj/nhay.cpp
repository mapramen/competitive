#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> f;
string s;

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

void Solve(){
  int n;
  
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  s.clear();
  getchar();
  for(int i = 0; i < n; ++i){
    s.push_back(getchar());
  }
  f.resize(n + 1);

  for(int i = 2, k = 0; i <= n; ++i){
    k = ComputeFailure(k, s[i - 1]);
    f[i] = k;
  }

  getchar();
  for(int i = 1, k = 0; ; ++i){
    char c = getchar();
    if(c == '\n' || c == EOF){
      if(c == '\n'){
        putchar('\n');
      }
      break;
    }

    k = ComputeFailure(k, c);
    if(k == n){
      printf("%d\n", i - n);
      k = f[k];
    }
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}