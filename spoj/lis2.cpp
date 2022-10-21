#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> C(N);
vector<vector<int>> T(N);
int a[N], b[N];

void SortAndDedup(vector<int>& v){
  v.push_back(INT_MIN);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedCoordinate(vector<int>& c, int x){
  return upper_bound(c.begin(), c.end(), x) - c.begin() - 1;
}

void CoordinateCompress(int n, int a[]){
  vector<int> c(a + 1, a + n + 1);
  SortAndDedup(c);

  for(int i = 1; i <= n; ++i){
    a[i] = GetCompressedCoordinate(c, a[i]);
  }
}

void Insert(int x, int y){
  for( ; x < N; x += (x & - x)){
    C[x].push_back(y);
  }
}

void Update(vector<int>& c, vector<int>& t, int i, int val){
  for(i = max(1, GetCompressedCoordinate(c, i)); i < t.size(); i += (i & -i)){
    t[i] = max(t[i], val);
  }
}

void Update(int x, int y, int val){
  for(x = max(1, x); x < N; x += (x & -x)){
    Update(C[x], T[x], y, val);
  }
}

int Query(vector<int>& c, vector<int>& t, int i){
  int ans = 0;
  for(i = GetCompressedCoordinate(c, i); i > 0; i -= (i & -i)){
    ans = max(ans, t[i]);
  }
  return ans;
}

int Query(int x, int y){
  int ans = 0;
  for( ; x > 0; x -= (x & -x)){
    ans = max(ans, Query(C[x], T[x], y));
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i], &b[i]);
  }

  CoordinateCompress(n, a);
  
  for(int i = 1; i <= n; ++i){
    Insert(a[i], b[i]);
  }

  for(int i = 0; i < N; ++i){
    SortAndDedup(C[i]);
    T[i].resize(C[i].size());
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int ansx = 1 + Query(a[i] - 1, b[i] - 1);
    Update(a[i], b[i], ansx);
    ans = max(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}