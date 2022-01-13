#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  if(s.size() % 2 == 1){
    return false;
  }

  for(int n = s.size(), j = n - 1, i = n / 2 - 1; i != -1; --i, --j){
    if(s[i] != s[j]){
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