#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void CheckAndPrint(string s, string t){
  bool check = (s.size() == t.size());
  for(int i = 0; i < s.size() && check == 1; ++i){
    if(s[i] == '.')
      continue;
    check = (s[i] == t[i]);
  }
  if(check)
    cout << t <<'\n';
}

int main(){
  string s;

  cin >> s;
  cin >> s;

  CheckAndPrint(s, "vaporeon");
  CheckAndPrint(s, "jolteon");
  CheckAndPrint(s, "flareon");
  CheckAndPrint(s, "espeon");
  CheckAndPrint(s, "umbreon");
  CheckAndPrint(s, "leafeon");
  CheckAndPrint(s, "glaceon");
  CheckAndPrint(s, "sylveon");

  return 0;
}
