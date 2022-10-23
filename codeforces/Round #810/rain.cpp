#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MAXM (1 << 22)

int a[N];
ll B[N];

void AddEvent(vector<pair<int,pii>>& events, int x, int y, int m, int c){
  events.push_back({x, {m, c}});
  events.push_back({y, {0, 0}});
  events.push_back({y + 1, {-m, -c}});
}

int left_endpoint[MAXM], right_endpoint[MAXM];
ll T[MAXM], T1[MAXM], T2[MAXM];

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    left_endpoint[k] = a[l], right_endpoint[k] = a[l];
    T[k] = B[l], T1[k] = B[l] - a[l], T2[k] = B[l] + a[l];
  }
  else{
    int mid = (l + r) / 2;
    int k1 = 2 * k + 1, k2 = 2 * k + 2;

    BuildSegmentTree(k1, l, mid);
    BuildSegmentTree(k2, mid + 1, r);

    left_endpoint[k] = left_endpoint[k1], right_endpoint[k] = right_endpoint[k2];

    T[k] = max(T[k1], T[k2]);
    T1[k] = max(T1[k1], T1[k2]);
    T2[k] = max(T2[k1], T2[k2]);
  }
}

ll Query(ll T[], int k, int l, int r){
  if(r < left_endpoint[k] || right_endpoint[k] < l){
    return LLONG_MIN;
  }

  if(l <= left_endpoint[k] && right_endpoint[k] <= r){
    return T[k];
  }

  int mid = (l + r) / 2;
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  
  return max(Query(T, k1, l, r), Query(T, k2, l, r));
}

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> v(n);
  for(pii& p: v){
    scanf("%d%d", &p.first, &p.second);
  }

  vector<pair<int,pii>> events;
  for(auto [x, p]: v){
    AddEvent(events, x - p, x - 1, 1, p - x);
    AddEvent(events, x, x + p, -1, p + x);
  }
  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  
  int len = 0;
  for(ll M = 0, C = 0; !events.empty(); ){
    int x = events.back().first;
    for( ; !events.empty() && events.back().first == x; events.pop_back()){
      M += events.back().second.first;
      C += events.back().second.second;
    }

    ++len;
    a[len] = x, B[len] = M * x + C;
  }

  BuildSegmentTree(0, 1, len);

  string ans;
  for(auto [x, p]: v){
    int x1 = x - p, x2 = x + p;
    ll val = max(Query(T, 0, INT_MIN, x1 - 1), Query(T, 0, x2 + 1, INT_MAX));
    val = max(val, Query(T1, 0, x1, x - 1) - (p - x));
    val = max(val, Query(T2, 0, x, x2) - (p + x));

    ans.push_back('0' + (val > m ? 0 : 1));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}