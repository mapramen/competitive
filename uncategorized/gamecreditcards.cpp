#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans1 = 0, ans2 = 0;
  string s, m;

  cin >> n >> s >> m;

  sort(s.begin(), s.end());
  sort(m.begin(), m.end());

  for(int i = 0, j = 0; i < n && j < n; i++, j++){
    for( ; j < n && m[j] < s[i]; j++)
      ans1++;
  }

  for(int i = 0, j = 0; i < n && j < n; i++, j++){
    for( ; j < n && m[j] <= s[i]; j++);
    if(j != n)
      ans2++;
  }

  cout << ans1 << '\n';
  cout << ans2 << '\n';
  
  return 0;
}
