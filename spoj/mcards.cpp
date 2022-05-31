#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int LIS(vector<int> a){
  vector<int> v;

  for(int x: a){
    if(v.empty() || v.back() < x){
      v.push_back(x);
    }
    else{
      int i = lower_bound(v.begin(), v.end(), x) - v.begin();
      v[i] = x;
    }
  }

  return v.size();
}

vector<int> GetCharacteristicArray(int m, vector<int>& color_order, vector<pii>& original_cards){
  map<pii,int> final_cards;

  int k = 0;
  for(int color: color_order){
    for(int j = 1; j <= m; ++j){
      final_cards[{color, j}] = ++k;
    }
  }

  vector<int> a;
  for(pii& p: original_cards){
    a.push_back(final_cards[p]);
  }

  return a;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> cards(n * m);
  for(pii& p: cards){
    scanf("%d%d", &p.first, &p.second);
  }

  vector<int> color_order(n);
  iota(color_order.begin(), color_order.end(), 1);

  int ans = 0;
  do{
    ans = max(ans, LIS(GetCharacteristicArray(m, color_order, cards)));
  } while(next_permutation(color_order.begin(), color_order.end()));

  ans = n * m - ans;
  printf("%d\n", ans);

  return 0;
}