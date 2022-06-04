#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  for(int n = s.size(), i = 0; i < n; ){
    char c = s[i];
    int k = 0;

    for( ; i < n && s[i] == c; ++i, ++k);

    if(k < 2){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}