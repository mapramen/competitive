#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map< string, int > m;
vector< vector<int> > v;

int main(){
  int n, l, ansx, ans;

  cin >> n >> l;

  while(n--){
    string s;
    int a;

    cin >> s >> a;

    if(m.find(s) == m.end())
      m.insert(MP(s, m.size()));

    v.resize(m.size());
    v[m[s]].PB(a);
  }

  for(int i = 0; i < v.size(); i++)
    sort(v[i].begin(), v[i].end(), greater<int>());

  ansx = ans = 0;

  for(auto it : m){
    string r = it.first;
    reverse(r.begin(), r.end());

    auto jt = m.find(r);

    if(jt == m.end())
      continue;

    int i = it.second, j = jt->second;

    if(i > j)
      continue;

    int s1 = 0, s2 = 0, s = 0;

    if(i == j){
      for(int k = 0; k < v[i].size(); k++){
        s += v[i][k];

        if(k % 2)
          s2 = max(s2, s);
        else
          s1 = max(s1, s);
      }
    }
    else{
      for(int k = 0; k < min(v[i].size(), v[j].size()); k++){
        s += v[i][k] + v[j][k];
        s2 = max(s2, s);
      }
    }

    ans += s2;
    ansx = max(ansx, s1 - s2);
  }

  cout << ans + ansx << '\n';

  return 0;
}
