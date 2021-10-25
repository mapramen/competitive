#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define ppiii pair<pii,int>
#define pll pair<ll,ll>
#define N 20
#define M (1 << N)

string S[N];
vector<ppiii> psList[N];
int ps[M], minps[M], dp[M];

pii Process(string &s, vector<ppiii>& psList){
  int ps = 0, minps = INT_MAX;

  for(int i = 0, n = s.size(); i < n; ++i){
    ps += (s[i] == '(' ? 1 : -1);
    minps = min(minps, ps);
    psList.push_back({{ps, i}, i});
  }
  sort(psList.begin(), psList.end());

  int x = INT_MAX;
  for(auto &p: psList){
    x = min(x, p.second);
    p.second = x;
  }

  return {ps, minps};
}

int Calculate(int i, int ps, int c){
  ps = -ps;
  auto &v = psList[i];

  int k = lower_bound(v.begin(), v.end(), make_pair(make_pair(ps, 0), 0)) - v.begin();
  if(k >= v.size() || v[k].first.first != ps){
    return c;
  }
  
  int n = k != 0 ? v[k - 1].second : INT_MAX;

  return c + (lower_bound(v.begin() + k, v.end(), make_pair(make_pair(ps, n), n)) - (v.begin() + k));
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    cin >> S[i];
  }

  for(int i = 0; i < n; ++i){
    int mask = (1 << i);
    tie(ps[mask], minps[mask]) = Process(S[i], psList[i]);
  }

  int m = (1 << n);

  ps[0] = 0, minps[0] = INT_MAX;
  for(int mask = 1; mask < m; ++mask){
    int i = __builtin_ctz(mask);
    int imask = (1 << i);
    ps[mask] = ps[(mask ^ imask)] + ps[imask];
  }

  int ans = 0;
  for(int mask = 1; mask < m; ++mask){
    int ansx = 0, minpsx = -1e6;

    for(int tmask = mask, i = 0; tmask != 0; tmask ^= (1 << i)){
      i = __builtin_ctz(tmask);
      int rmask = mask ^ (1 << i);

      if(minps[rmask] < 0){
        continue;
      }

      int ansy = Calculate(i, ps[rmask], dp[rmask]);
      ans = max(ans, ansy);

      int minpsy = min(minps[rmask], ps[rmask] + minps[(mask ^ rmask)]);
      minpsx = max(minpsx, minpsy);

      if(minpsy >= 0){
        ansx = max(ansx, ansy);
      }
    }

    dp[mask] = ansx;
    minps[mask] = minpsx;
  }

  cout << ans << '\n';

  return 0;
}