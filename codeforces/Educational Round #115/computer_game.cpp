#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  string s1, s2;

  cin >> n >> s1 >> s2;

  for(int i = 1; i < n - 1; ++i){
    if(s1[i] == '1' && s2[i] == '1'){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << (Solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}