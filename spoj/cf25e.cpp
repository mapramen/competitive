#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001
#define B 3

char s[N];
int f[N];

string ReadString(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }

  return string(s);
}

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

string GetMinString(string& a, string& b){
  for(int i = 0; i < b.size(); ++i){
    s[i] = b[i];
  }

  s[b.size()] = '$';

  for(int k = b.size() + 1, i = 0; i < a.size(); ++i, ++k){
    s[k] = a[i];
  }

  s[a.size() + 1 + b.size()] = '\0';

  int n = strlen(s);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);

    if(f[i] == b.size()){
      return a;
    }
  }

  return a + string(b, f[n]);
}

int Solve(){
  vector<string> S;
  for(int i = 0; i < B; ++i){
    S.push_back(ReadString());
  }

  sort(S.begin(), S.end());

  int ans = N;

  do{
    string s;
    for(int i = 0; i < B; ++i){
      s = GetMinString(s, S[i]);
    }
    ans = min(ans, (int)s.size());
  } while(next_permutation(S.begin(), S.end()));

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}