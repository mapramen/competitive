#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

char s[N], t[N];

int Solve(){
  scanf("%s%s", s, t);

  if(s[0] == '*'){
    exit(0);
  }

  int n = strlen(s), ans = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == t[i]){
      continue;
    }
    for( ; i < n && s[i] != t[i]; ++i);
    ++ans;
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}