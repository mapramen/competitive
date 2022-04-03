#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s, t;
  cin >> s >> t;

  for(int i = 0, j = s.size() - 1; i < s.size(); ++i, --j){
    if(i % 2 == 0 && j % 2 == 0 && s[i] == t.front()){
      return true;
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}