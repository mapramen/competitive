#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  bool check = 1;

  cin >> n;
  while(n % 10 == 0)
    n /= 10;

  string s = to_string(n);
  for(int i = 0, n = s.size(); i < n && check == 1; ++i)
    check = (s[i] == s[n - 1 - i]);

  if(check)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
