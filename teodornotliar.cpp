#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> LongestNonDecreasingLengths(vector<int> a, bool suffix = 0){
  if(suffix){
    reverse(a.begin(), a.end());
  }

  vector< pii > v;
  vector<int> ans;

  for(int i = 0; i < a.size(); ++i){
    pii p = MP(a[i], i);
    if(v.size() == 0 || v.back() < p){
      ans.PB(v.size());
      v.PB(p);
    }
    else{
      int k = lower_bound(v.begin(), v.end(), p) - v.begin();
      ans.PB(k);
      v[k] = p;
    }
  }

  if(suffix)
    reverse(ans.begin(), ans.end());

  return ans;
}

void Print(vector<int> a){
  for(auto x : a)
    cout << x << ' ';
  cout << '\n';
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  vector<int> a(m);

  while(n--){
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    ++a[l];
    if(r < m)
      --a[r];
  }

  for(int i = 1; i < m; ++i)
    a[i] += a[i - 1];

  vector<int> prefix = LongestNonDecreasingLengths(a), suffix = LongestNonDecreasingLengths(a, 1);

  int ans = 0;
  for(int i = 0; i < m; ++i)
    ans = max(ans, 1 + prefix[i] + suffix[i]);

  printf("%d\n", ans);

  return 0;
}
