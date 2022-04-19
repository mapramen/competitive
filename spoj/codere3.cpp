#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> GetLISLengths(vector<int>& a){
  vector<int> v, ans;

  for(int x: a){
    int ansx;
    if(v.empty() || v.back() < x){
      ansx = v.size();
      v.push_back(x);
    }
    else{
      ansx = lower_bound(v.begin(), v.end(), x) - v.begin();
      v[ansx] = x;
    }
    ans.push_back(ansx + 1);
  }

  return ans;
}

vector<int> GetLDSLengths(vector<int>& a){
  reverse(a.begin(), a.end());
  vector<int> ans = GetLISLengths(a);

  reverse(a.begin(), a.end());
  reverse(ans.begin(), ans.end());

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> lis_lengths = GetLISLengths(a), lds_lengths = GetLDSLengths(a);

  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, lis_lengths[i] + lds_lengths[i] - 1);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}