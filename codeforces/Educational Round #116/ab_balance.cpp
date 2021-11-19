#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    s[s.size() - 1] = s[0];
    cout << s << '\n';
  }
  return 0;
}