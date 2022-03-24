#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppv pair<pii,vector<int>>

ordered_set S;

vector<ppv> ReadIntervals(int n){
  map<pii,vector<int>> M;

  for(int i = 0; i < n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    M[{l, r}].push_back(i);
  }

  vector<ppv> V;
  for(auto it: M){
    V.push_back(it);
  }
  return V;
}

vector<int> CalculateContains(int n, vector<ppv>& V){
  vector<int> ans(n);

  sort(V.begin(), V.end(), [](ppv& a, ppv& b) { return make_pair(a.first.second, b.first.first) < make_pair(b.first.second, a.first.first); });
  S.insert({INT_MIN, 0});

  for(auto &[p, v]: V){
    auto [l, r] = p;
    
    int ansx = (v.size() - 1) + S.size() - S.order_of_key({l, 0});
    for(int i: v){
      ans[i] = ansx;
      S.insert({l, i});
    }
  }

  S.clear();
  return ans;
}

vector<int> CalculateContained(int n, vector<ppv>& V){
  vector<int> ans(n);

  sort(V.begin(), V.end(), [](ppv& a, ppv& b) { return make_pair(a.first.first, b.first.second) < make_pair(b.first.first, a.first.second); });
  S.insert({INT_MIN, 0});

  for(auto &[p, v]: V){
    auto [l, r] = p;
    
    int ansx = (v.size() - 1) + S.size() - S.order_of_key({r, 0});
    for(int i: v){
      ans[i] = ansx;
      S.insert({r, i});
    }
  }

  S.clear();
  return ans;
}

void Print(vector<int> ans){
  for(int ansx: ans){
    printf("%d ", ansx);
  }
  printf("\n");
}

int main(){
  int n;
  scanf("%d", &n);

  vector<ppv> V = ReadIntervals(n);
  Print(CalculateContains(n, V));
  Print(CalculateContained(n, V));

  return 0;
}