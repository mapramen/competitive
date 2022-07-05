#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ftype;
typedef complex<ftype> point;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define x real
#define y imag
#define N 10000001

ftype dot(point a, point b) {
  return (conj(a) * b).x();
}

ftype f(point a,  ftype x) {
  return dot(a, {x, 1});
}

point line[4 * N];

void AddLine(point nw, int v = 1, int l = 0, int r = N){
  int m = (l + r) / 2;
  
  bool lef = f(nw, l) > f(line[v], l);
  bool mid = f(nw, m) > f(line[v], m);
  
  if(mid){
    swap(line[v], nw);
  }

  if(r - l == 1){
    return;
  }
  
  if(lef != mid){
    AddLine(nw, 2 * v, l, m);
  }
  else{
    AddLine(nw, 2 * v + 1, m, r);
  }
}

ftype Query(int x, int v = 1, int l = 0, int r = N) {
  if(r - l == 1){
    return f(line[v], x);
  }

  int m = (l + r) / 2;
  return max(f(line[v], x), x < m ? Query(x, 2 * v, l, m) : Query(x, 2 * v + 1, m, r));
}

int main(){
  int n;
  scanf("%d", &n);

  AddLine({0, 0});

  for(int i = 1; i <= n; ++i){
    int a, d;
    scanf("%d%d", &a, &d);
    AddLine({-d, a + Query(i - 1) + 1ll * d * (i - 1)});
  }

  printf("%lld\n", Query(n));

  return 0;
}