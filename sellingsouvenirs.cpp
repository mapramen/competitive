#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define plll pair< ll, pll >
#define PB push_back
#define MP make_pair
#define B 4

vector< vector<ll> > s(B, vector<ll>(1));
vector<ll> b;

void PreProcess(){
  for(int i = 1; i < B; i++){
    sort(s[i].begin() + 1, s[i].end(), greater<ll>());
    for(int j = 1; j < s[i].size(); j++)
      s[i][j] += s[i][j - 1];
  }
}

int main(){
  int n, m;
  ll ans = 0;

  scanf("%d%d", &n, &m);

  while(n--){
    ll w, c;
    scanf("%lld%lld", &w, &c);
    s[w].PB(c);
  }

  PreProcess();

  b.resize(m + 1);

  for(ll i = 1, w = 0, c = 0, i1 = 0, i2 = 0, n1 = s[1].size() - 1, n2 = s[2].size() - 1; i <= m; i++){
    if(w == i - 2){
      if(i2 < n2){
        i2++;
        c = s[1][i1] + s[2][i2];
        w = i;
      }
    }
    else{
      ll c1 = 0, c2 = 0;

      if(i1 < n1)
        c1 = s[1][i1 + 1] + s[2][i2];

      if(i1 > 0 && i2 < n2)
        c2 = s[1][i1 - 1] + s[2][i2 + 1];

      if(c1 >= c2 && c1 != 0){
        c = c1;
        i1++;
        w = i;
      }

      if(c2 > c1 && c2 != 0){
        c = c2;
        i1--;
        i2++;
        w = i;
      }
    }

    b[i] = max(b[i - 1], c);
  }

  for(int i = 0, n3 = min((int)s[3].size() - 1, m / 3); i <= n3; i++)
    ans = max(ans, s[3][i] + b[m - 3 * i]);

  printf("%lld\n", ans);

  return 0;
}
