#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N], t[N];

string Solve(){
  scanf("%s%s", s, t);

  int n = strlen(s), m = strlen(t);
  for(int i = 0; i < m; ++i){
    int q = i / n, r = i % n;
    if(q % 2 != 0){
      r = n - 1 - r;
    }
    int k = (26 + (t[i] - 'a') - (s[r] - '0')) % 26;
    t[i] = 'a' + k;
  }

  return string(t);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}