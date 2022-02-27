#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 1000001
#define M (1 << 21)

char qs[20];
set<tiii> S;
ll lazyValues[N], T[N];

void Update(int i, ll x){
  for( ; i > 0 && i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int l, int r, ll x){
  Update(l, x), Update(r + 1, -x);
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

tiii GetContainingInterval(int i){
  return *prev(S.lower_bound(make_tuple(i + 1, 0, 0)));
}

void AddInterval(int l, int r, int c){
  if(l > r){
    return;
  }
  
  Update(l, r, -lazyValues[c]);
  S.insert({l, r, c});
}

void RemoveInterval(int l, int r, int c){
  if(l > r){
    return;
  }

  Update(l, r, lazyValues[c]);
  S.erase({l, r, c});
}

void SplitInterval(int i){
  auto [l, r, c] = GetContainingInterval(i);
  RemoveInterval(l, r, c);
  AddInterval(l, i - 1, c), AddInterval(i, i, c), AddInterval(i + 1, r, c);
}

void UpdateColor(int l, int r, int c){
  SplitInterval(l), SplitInterval(r);

  int lx = l, rx, cx;
  while(lx <= r){
    tie(lx, rx, cx) = GetContainingInterval(lx);
    RemoveInterval(lx, rx, cx);
    lx = rx + 1;
  }

  AddInterval(l, r, c);
}

int GetColor(int i){
  auto [l, r, c] = GetContainingInterval(i);
  return c;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  AddInterval(0, 0, 0), AddInterval(1, n, 1), AddInterval(n + 1, n + 1, 0);

  while(m--){
    scanf("%s", qs);

    if(qs[0] == 'C'){
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);
      UpdateColor(l, r, c);
    }
    else if(qs[0] == 'A'){
      int c, val;
      scanf("%d%d", &c, &val);
      lazyValues[c] += val;
    }
    else{
      int i;
      scanf("%d", &i);
      printf("%lld\n", Query(i) + lazyValues[GetColor(i)]);
    }
  }

  return 0;
}