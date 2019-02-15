#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0;

  cin >> n;

  while(n--){
    string s;
    char c;

    cin >> s;
    c = s[0];

    ans += (4 * (c == 'T'));
    ans += (6 * (c == 'C'));
    ans += (8 * (c == 'O'));
    ans += (12 * (c == 'D'));
    ans += (20 * (c == 'I'));
  }

  cout << ans << '\n';

  return 0;
}
