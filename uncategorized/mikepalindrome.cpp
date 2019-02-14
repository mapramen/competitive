#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;
  int diff = 0;

  cin >> s;
  for(int i = 0, n = s.size(); i < n; i++)
    diff += (s[i] != s[n - 1 - i]);

  if(diff == 2 || (diff == 0 && s.size() % 2 == 1))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
