#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define tiii tuple< int, int, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 5001
#define B 7

vector<int> compressesdX(1);
int a[N], dp1[N][N], dp2[B][N];
vector< tiii > updates;

int PreProcess(int n){
  for(int i = 1; i <= n; i++)
    compressesdX.PB(a[i]);
  sort(compressesdX.begin(), compressesdX.end());
  compressesdX.erase(unique(compressesdX.begin(), compressesdX.end()), compressesdX.end());
  return (int)compressesdX.size() - 1;
}

int GetCompressedValue(int x){
  return lower_bound(compressesdX.begin(), compressesdX.end(), x) - compressesdX.begin();
}

int GetOriginalValue(int i){
  return compressesdX[i];
}

void ApplyUpdate(int ci, int cj, int k){
  int mi = GetOriginalValue(ci) % B;
  dp1[ci][cj] = max(dp1[ci][cj], k);
  dp2[mi][cj] = max(dp2[mi][cj], k);
}

void ApplyUpdates(){
  for(auto p : updates){
    int ci, cj, k;
    tie(ci, cj, k) = p;
    ApplyUpdate(ci, cj, k);
    ApplyUpdate(cj, ci, k);
  }
  updates.clear();
}

int main(){
  int n, m, ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  m = PreProcess(n);

  for(int i = 1; i <= n; i++){
    int ci = GetCompressedValue(a[i]);

    int cj = GetCompressedValue(a[i] - 1);
    if(GetOriginalValue(cj) == a[i] - 1){
      for(int ck = 1; ck <= m; ck++)
        updates.PB(MT(ci, ck, 1 + dp1[cj][ck]));
    }

    cj = GetCompressedValue(a[i] + 1);
    if(GetOriginalValue(cj) == a[i] + 1){
      for(int ck = 1; ck <= m; ck++)
        updates.PB(MT(ci, ck, 1 + dp1[cj][ck]));
    }

    int mi = a[i] % B;
    for(int cj = 1; cj <= m; cj++)
      updates.PB(MT(ci, cj, 1 + dp2[mi][cj]));

    ApplyUpdates();
  }

  for(int ci = 1; ci <= m; ci++)
    for(int cj = 1; cj <= m; cj++)
      ans = max(ans, dp1[ci][cj]);

  printf("%d\n", ans);
  
  return 0;
}
