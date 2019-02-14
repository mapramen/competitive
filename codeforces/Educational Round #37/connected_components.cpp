#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

set<int> s[N], S;

int DFS(int i){
  S.erase(i);
  int ans = 1, k = -1;
  while(true){
    auto it = S.upper_bound(k);
    if(it == S.end())
      break;
    k = *it;
    if(s[i].find(k) != s[i].end())
      continue;
    ans += DFS(k);
  }
  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    s[j].insert(i);
    s[i].insert(j);
  }

  for(int i = 1; i <= n; ++i)
    S.insert(i);

  vector<int> u;
  while(S.size())
    u.PB(DFS(*S.begin()));

  sort(u.begin(), u.end());

  cout << u.size() << '\n';
  for(auto x : u)
    cout << x << ' ';
  cout << '\n';

  return 0;
}
