#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
  return (conj(a) * b).x();
}

ftype cross(point a, point b) {
  return (conj(a) * b).y();
}

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

const ll INF = 1E11;
vector<vector<pii>> adj(N);
ll d[N];
priority_queue<pll,vector<pll>,greater<pll>> Q;

void CheckAndPush(int i, ll di){
  if(di < d[i]){
    Q.push({di, i});
    d[i] = di;
  }
}

void Dijkstra(int n){
  for(int i = 1; i <= n; ++i){
    for(auto [j, w]: adj[i]){
      CheckAndPush(j, d[i] + w);
    }
  }

  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(auto [j, w]: adj[i]){
      CheckAndPush(j, d[i] + w);
    }
  }
}

vector<point> hull, vecs;

void add_line(ftype k, ftype b) {
  point nw = {k, b};
  while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0) {
    hull.pop_back();
    vecs.pop_back();
  }
  if(!hull.empty()) {
    point temp(0, 1);
    vecs.push_back(temp * (nw - hull.back()));
  }
  hull.push_back(nw);
}

ftype get(ftype x) {
  point query = {x, 1};
  auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
    return cross(a, b) > 0;
  });
  return dot(query, hull[it - vecs.begin()]);
}

void CHT(int n){
  hull.clear(), vecs.clear();

  for(int i = n; i != 0; --i){
    add_line(-2 * i, d[i] + 1ll * i * i);
  }

  for(int i = 1; i <= n; ++i){
    d[i] = min(d[i], 1ll * i * i + get(i));
  }
}

int main(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  for(int i = 1; i <= n; ++i){
    d[i] = INF;
  }

  d[1] = 0;
  Dijkstra(n);

  for(int i = 1; i <= k; ++i){
    CHT(n);
    Dijkstra(n);
  }

  for(int i = 1; i <= n; ++i){
    printf("%lld ", d[i]);
  }
  printf("\n");

  return 0;
}