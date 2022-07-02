#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  string s, t;
  cin >> s >> t;

  if(t == "a"){
    return 1;
  }

  if(t.find('a') != string::npos){
    return -1;
  }

  return (1ll << s.size());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}