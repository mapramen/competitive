#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> GetScribers(vector<int> a, ll m){
  reverse(a.begin(), a.end());

  vector<vector<int>> ans;
  vector<int> v;
  ll s = 0;

  for(int i = 0, n = a.size(); i < n; ++i){
    if(a[i] > m){
      return {};
    }

    if(s + a[i] > m){
      ans.push_back(v);

      v.clear();
      s = 0;
    }

    s += a[i];
    v.push_back(a[i]);
  }

  if(!v.empty()){
    ans.push_back(v);
  }

  return ans;
}

vector<vector<int>> BinarySearch(vector<int>& a, int k){
  ll x = 1, y = 1E10;
  vector<vector<int>> ans;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    vector<vector<int>> ansx = GetScribers(a, mid);
    if(ansx.empty() || ansx.size() > k){
      x = mid + 1;
    }
    else{
      ans = ansx, y = mid - 1;
    }
  }

  return ans;
}

vector<vector<int>> Resize(vector<vector<int>>& V, int k){
  vector<vector<int>> ans;

  while(!V.empty()){
    vector<int>& v = V.back();

    if(ans.size() + V.size() == k || v.size() == 1){
      reverse(v.begin(), v.end());
      ans.push_back(v);
      V.pop_back();
      continue;
    }

    ans.push_back({v.back()});
    v.pop_back();
  }

  return ans;
}

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<vector<int>> ans = BinarySearch(a, k);
  ans = Resize(ans, k);
  
  bool add_separator = false;
  for(vector<int>& v: ans){
    if(add_separator){
      printf("/ ");
    }
    for(int x: v){
      printf("%d ", x);
    }
    add_separator = true;
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}