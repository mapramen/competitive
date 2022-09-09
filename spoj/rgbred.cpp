#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  map<char,int> C;
  for(int i = 0; s[i] != '\0'; ++i){
    ++C[s[i]];
  }

  if(C.size() == 1){
    return n;
  }

  bool even_found = false, odd_found = false;
  for(pii p: C){
    even_found = even_found || (p.second % 2 == 0);
    odd_found = odd_found || (p.second % 2 == 1);
  }

  return (n % 2 == 1 && even_found) || (n % 2 == 0 && odd_found) ? 1 : 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}