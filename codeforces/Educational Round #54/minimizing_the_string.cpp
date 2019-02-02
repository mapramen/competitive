#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string s, ans;

  cin >> n >> s;

  for(int i = 0; i < s.size(); ++i){
    char c = s[i], d = s[i + 1];
    if(c <= d){
      ans.PB(c);
    }
    else{
      ans += string(s, i + 1);
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}
