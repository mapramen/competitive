#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string s;
  vector<string> v;

  cin >> s >> n;

  while(n--){
    string t;
    cin >> t;
    v.PB(t);
  }

  for(auto s1 : v){
    for(auto s2 : v){
      if((s1 + s2).find(s) != string::npos){
        cout << "YES\n";
        return 0;
      }
    }
  }

  cout << "NO\n";

  return 0;
}
