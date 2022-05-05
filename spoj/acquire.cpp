#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

struct line{
  long long a , b;
  double xleft;
  bool type;
  line(long long _a , long long _b){
    a = _a;
    b = _b;
    type = 0;
  }
  bool operator < (const line &other) const{
    if(other.type){
      return xleft < other.xleft;
    }
    return a > other.a;
  }
};

double meet(line x , line y){
  return 1.0 * (y.b - x.b) / (x.a - y.a);
}

struct cht{
  set < line > hull;
  cht(){
    hull.clear();
  }
  typedef set < line > :: iterator ite;
  bool hasleft(ite node){
    return node != hull.begin();
  }
  bool hasright(ite node){
    return node != prev(hull.end());
  }
  void updateborder(ite node){
    if(hasright(node)){
      line temp = *next(node);
      hull.erase(temp);
      temp.xleft = meet(*node , temp);
      hull.insert(temp);
    }
    if(hasleft(node)){
      line temp = *node;
      temp.xleft = meet(*prev(node) , temp);
      hull.erase(node);
      hull.insert(temp);
    }
    else{
      line temp = *node;
      hull.erase(node);
      temp.xleft = -1e18;
      hull.insert(temp);
    }
  }
  bool useless(line left , line middle , line right){
    double x = meet(left , right);
    double y = x * middle.a + middle.b;
    double ly = left.a * x + left.b;
    return y > ly;
  }
  bool useless(ite node){
    if(hasleft(node) && hasright(node)){
      return useless(*prev(node) , *node , *next(node));
    }
    return 0;
  }
  void addline(long long a , long long b){
    line temp = line(a , b);
    auto it = hull.lower_bound(temp);
    if(it != hull.end() && it -> a == a){
      if(it -> b > b){
        hull.erase(it);
      }
      else{
        return;
      }
    }
    hull.insert(temp);
    it = hull.find(temp);
    if(useless(it)){
      hull.erase(it);
      return;
    }
    while(hasleft(it) && useless(prev(it))){
      hull.erase(prev(it));
    }
    while(hasright(it) && useless(next(it))){
      hull.erase(next(it));
    }
    updateborder(it);
  }
  long long getbest(long long x){
    if(hull.empty()){
      return 1e18;
    }
    line query(0 , 0);
    query.xleft = x;
    query.type = 1;
    auto it = hull.lower_bound(query);
    it = prev(it);
    return it -> a * x + it -> b;
  }
};

vector<pii> ReadRectangles(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  return a;
}

vector<pii> RemoveRedundant(vector<pii> a){
  sort(a.begin(), a.end());

  map<int,int> M;
  for(pii p: a){
    int x = p.first, y = p.second;

    while(!M.empty() && M.begin()->first <= y){
      M.erase(M.begin());
    }

    M[y] = x;
  }

  a.clear();
  for(pii p: M){
    a.push_back({p.second, p.first});
  }

  sort(a.begin(), a.end());
  return a;
}

int main(){
  vector<pii> a = RemoveRedundant(ReadRectangles());

  int n = a.size();
  vector<ll> dp(n + 1);

  cht cht;
  for(int i = 1; i <= n; ++i){
    cht.addline(a[i - 1].second, dp[i - 1]);
    dp[i] = cht.getbest(a[i - 1].first);
  }

  printf("%lld\n", dp[n]);

  return 0;
}