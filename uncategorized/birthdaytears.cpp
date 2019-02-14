#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int inf = 1E9;

int Solve(string &s, int l, int r){
  int n = r - l + 1;
  bool check = 1;

  for(int i = l + 1; i <= r && check == 1; i++)
    check = (s[i] == s[i - 1]);

  if(check == 1)
    return 0;

  if(n % 2 == 1)
    return inf;

  int mid = l + (r - l) / 2;
  return 1 + min(Solve(s, l, mid), Solve(s, mid + 1, r));
}

int main(){
  int t;

  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int ans = Solve(s, 0, (int)s.size() - 1);
    if(ans >= inf)
      ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
