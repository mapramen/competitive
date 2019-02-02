#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

vector< pii > points;
vector< vector<int> > hor(N + 1), ver(N + 1), diag(2 * N + 1);

int GetPosition(vector<int>& v, int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

bool Check(vector<int>& v, int x){
  int i = GetPosition(v, x);
  return (i < v.size() && v[i] == x);
}

int GetAns(vector<int>& v, int x, int y, int z, int k){
  int ans = 0;
  for(int i = GetPosition(v, k) + 1; i < v.size(); i++){
    int d = v[i] - k;
    ans += (Check(ver[x], y + d) && Check(hor[y], x + d) && Check(diag[z], x + d));
  }
  return ans;
}

int Compute(pii p){
  int x, y, z, n1, n2, n3, n, ans = 0;
  tie(x, y) = p;
  z = x + N - y;

  n1 = ver[x].size() - GetPosition(ver[x], y) - 1;
  n2 = hor[y].size() - GetPosition(hor[y], x) - 1;
  n3 = diag[z].size() - GetPosition(diag[z], x) - 1;
  n = min(n1, min(n2, n3));

  if(n != 0){
    if(n1 == n)
      ans = GetAns(ver[x], x, y, z, y);
    else if(n2 == n)
      ans = GetAns(hor[y], x, y, z, x);
    else
      ans = GetAns(diag[z], x, y, z, x);
  }

  return ans;
}

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  while(n--){
    int x, y, z;
    scanf("%d%d", &x, &y);
    z = x + N - y;

    points.PB(MP(x, y));
    hor[y].PB(x);
    ver[x].PB(y);
    diag[z].PB(x);
  }

  for(int x = 0; x <= N; x++)
    sort(ver[x].begin(), ver[x].end());

  for(int y = 0; y <= N; y++)
    sort(hor[y].begin(), hor[y].end());

  for(int z = 0; z <= 2 * N; z++)
    sort(diag[z].begin(), diag[z].end());

  for(auto p : points)
    ans += Compute(p);

  printf("%lld\n", ans);

  return 0;
}
