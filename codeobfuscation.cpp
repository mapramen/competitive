#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;
  int ans = 0;

  cin >> s;

  for(int i = 0; i < s.size(); i++){
    int j = s[i] - 'a';
    if(j <= ans)
      ans = max(ans, j + 1);
    else
      ans = -1;
  }

  if(ans >= 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
