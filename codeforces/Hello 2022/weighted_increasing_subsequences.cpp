#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

vector<int> T;

void Update(int i, int x){
  for( ; i < T.size(); i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

vector<int> GetPrefixIncreasingSubsequenceCounts(vector<int>& a){
  if(a.empty()){
    return vector<int>();
  }

  vector<int> C(a);
  C.push_back(INT_MIN);
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  T.clear();
  T.resize(C.size());

  vector<int> ans;
  for(int ai: a){
    int ci = lower_bound(C.begin(), C.end(), ai) - C.begin();
    int ansi = (1 + Query(ci - 1)) % MOD;
    Update(ci, ansi);
    
    ans.push_back(ansi);
  }

  return ans;
}

vector<int> GetSuffixIncreasingSubsequenceCounts(vector<int>& a){
  if(a.empty()){
    return vector<int>();
  }

  vector<int> b(a);

  int m = *max_element(b.begin(), b.end());
  for(auto& bi: b){
    bi = m - bi;
  }
  reverse(b.begin(), b.end());

  vector<int> ans = GetPrefixIncreasingSubsequenceCounts(b);
  reverse(ans.begin(), ans.end());
  
  return ans;
}

pair<vector<int>,vector<int>> ReadArray(int n){
  vector<pii> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &v[i].first);
    v[i].second = -i;
  }
  sort(v.begin(), v.end());

  vector<int> a(n), inv_a(n);
  for(int k = 0; k < n; ++k){
    int i = -v[k].second;
    a[i] = k;
    inv_a[k] = i;
  }

  return {a, inv_a};
}

void AddCounts(vector<int>& s, vector<int>& a, vector<int> c, int x){
  if(a.empty()){
    return;
  }

  for(int k = a.size() - 1; k != -1; --k){
    int i = a[k];
    s[i] = (s[i] + x * c[k]) % MOD;
    s[i] = (MOD + s[i]) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  auto [a, inv_a] = ReadArray(n);

  vector<int> prefixCounts(n), suffixCounts(n);
  vector<bool> lastGreaterPresent(n);

  AddCounts(prefixCounts, a, GetPrefixIncreasingSubsequenceCounts(a), 1);
  AddCounts(suffixCounts, a, GetSuffixIncreasingSubsequenceCounts(a), 1);

  for(int i = n - 1, p = 0; i != -1; --i){
    if(a[i] <= p){
      continue;
    }

    int c = a[i];

    vector<pii> v;
    for(int x = p; x < c; ++x){
      if(inv_a[x] < i){
        v.push_back({inv_a[x], x});
      }
    }
    sort(v.begin(), v.end());

    vector<int> b;
    for(auto [_, x]: v){
      b.push_back(x);
      lastGreaterPresent[x] = true;
    }

    AddCounts(suffixCounts, b, GetSuffixIncreasingSubsequenceCounts(b), -1);
    p = c;
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(lastGreaterPresent[i]){
      ans = (ans + 1ll * prefixCounts[i] * suffixCounts[i]) % MOD;
    }
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