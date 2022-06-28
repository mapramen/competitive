#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 21

char s[M];

string ReadString(){
  scanf("%s", s);
  return string(s);
}

ll Dna2Int(string s){
  ll ans = 0;
  for(char c: s){
    ans = ans * 4 + (c % 5);
  }
  return ans;
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0 && m == 0){
    exit(0);
  }

  map<ll,int> C;
  for(int i = 1; i <= n; ++i){
    ++C[Dna2Int(ReadString())];
  }

  vector<int> c(n + 1);
  for(pair<ll,int> p: C){
    ++c[p.second];
  }

  for(int i = 1; i <= n; ++i){
    printf("%d\n", c[i]);
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}