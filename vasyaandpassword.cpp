#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool valid;
string ans;
vector<string> v{"", "a", "A", "1", "aA", "a1", "A1", "aA1"};

void Check(string s){
  int mask = 0;
  for(auto c : s){
    if(c >= 'a' && c <= 'z'){
      mask |= 1;
    }
    if(c >= 'A' && c <= 'Z'){
      mask |= 2;
    }
    if(c >= '0' && c <= '9'){
      mask |= 4;
    }
  }

  if(__builtin_popcount(mask) == 3){
    valid = 1;
    ans = s;
  }
}

int main(){
  int n;

  cin >> n;
  while(n--){
    string s;
    cin >> s;
    valid = 0;
    for(int x = 0; x < v.size() && valid == 0; ++x){
      auto r = v[x];
      for(int i = 0; i + r.size() < s.size() && valid == 0; ++i){
        string t = string(s, 0, i) + r + string(s, i + r.size());
        Check(t);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
