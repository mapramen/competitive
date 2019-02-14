#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;
  char a[] = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
  set<char> m(a, a + 10);

  int ans = 0;
  cin >> s;
  for(auto c : s)
    ans += (m.find(c) != m.end());

  cout << ans << '\n';
  
  return 0;
}
