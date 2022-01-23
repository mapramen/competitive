#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define N 300001

char s[N];
int grp[N];
vector<vector<pil>> V;
stack<pair<char,int>> S;
stack<pair<int,ll>> C;

int GetGroup(int i){
  if(grp[i] == -1){
    V.push_back(vector<pil>(1));
    return V.size() - 1;
  }
  return grp[i];
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s);

  for(int i = 0; i <= n; ++i){
    grp[i] = -1;
  }

  for(int i = 1; i <= n; ++i){
    char x = s[i - 1];
    if(x == '('){
      S.push({x, i});
      continue;
    }

    if(S.empty() || S.top().first == ')'){
      continue;
    }

    int j = S.top().second;
    S.pop();

    ll ans = 1, m = 0;
    while(!C.empty() && C.top().first > j){
      ans += C.top().second, ++m;
      C.pop();
    }

    ans += (m * (m - 1) / 2);

    C.push({i, ans});

    int k = GetGroup(j - 1);
    V[k].push_back({i, ans});
    grp[i] = k;
  }

  for(vector<pil>& v: V){
    ll s = 0;
    for(pil& p: v){
      s += p.second;
      p.second = s;
    }
  }

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    vector<pil>& v = V[grp[r]];
    int j = lower_bound(v.begin(), v.end(), make_pair(r, 0ll)) - v.begin();
    int i = lower_bound(v.begin(), v.end(), make_pair(l, 0ll)) - v.begin();

    ll ans = v[j].second - v[i - 1].second, m = j - i + 1;
    ans += (m * (m - 1) / 2);
    printf("%lld\n", ans);
  }

  return 0;
}