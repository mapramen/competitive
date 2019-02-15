#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, ans, minIndex = 0;
  string s, t;

  cin >> n >> m >> s >> t;

  ans = n;
  for(int i = 0; i <= m - n; i++){
    int ansx = 0;
    for(int j = 0, k = i; j < n; j++, k++)
      ansx += (s[j] != t[k]);
    if(ansx < ans){
      ans = ansx, minIndex = i;
    }
  }

  cout << ans << '\n';
  for(int j = 0, k = minIndex; j < n; j++, k++)
    if(s[j] != t[k])
      cout << j + 1 << ' ';
  cout << '\n';

  return 0;
}
