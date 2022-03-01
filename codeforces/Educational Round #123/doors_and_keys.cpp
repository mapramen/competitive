#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  int n = s.size();
  for(int i = 0; i < n; ++i){
    if(tolower(s[i]) != s[i]){
      continue;
    }

    bool found = false;
    for(int j = i + 1; j < n; ++j){
      found = found || (tolower(s[j]) == s[i]);
    }

    if(!found){
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