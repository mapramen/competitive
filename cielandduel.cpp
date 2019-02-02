#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Compute1(vector<int> a, vector<int> d, vector<int> c){
  int i, j, k, ans;

  for(j = k = 0; j < d.size(); j++, k++){
    for( ; k < c.size() && c[k] <= d[j]; k++);

    if(k == c.size())
      break;
    else
      c[k] = 0;
  }

  for(i = k = ans = 0; i < a.size(); i++, k++){
    for( ; k < c.size() && c[k] < a[i]; k++)
      ans += c[k];

    if(k == c.size())
      break;
    else
      ans += (c[k] - a[i]);
  }

  if(i < a.size() || j < d.size())
    ans = INT_MIN;
  else
    for( ; k < c.size(); k++)
      ans += c[k];

  return ans;
}

int Compute2(vector<int> a, vector<int> c){
  int n = c.size(), m = a.size();
  vector< vector<int> > dp(n + 1);

  a.PB(0), c.PB(0);
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());

  for(int i = 0; i <= n; i++)
    dp[i].resize(m + 1);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(c[i] >= a[j])
        dp[i][j] = dp[i - 1][j - 1] + (c[i] - a[j]);
      dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
    }
  }

  return dp[n][m];
}

int main(){
  int n, m;
  vector<int> a, d, c;

  cin >> n >> m;

  while(n--){
    int i;
    string s;
    cin >> s >> i;
    if(s == "ATK")
      a.PB(i);
    else
      d.PB(i);
  }

  while(m--){
    int i;
    cin >> i;
    c.PB(i);
  }

  sort(a.begin(), a.end());
  sort(d.begin(), d.end());
  sort(c.begin(), c.end());

  cout << max(Compute1(a, d, c), Compute2(a, c)) << '\n';

  return 0;
}
