#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< pii > a, b;
set<int> m;
vector<int> compressX, T;

void PreProcess(){
  for(auto p : a){
    int x, y;
    tie(x, y) = p;
    m.insert(x);
    m.insert(y + 1);
  }

  compressX.PB(INT_MIN);
  for(auto x : m)
    compressX.PB(x);

  T.resize(compressX.size());

  b.resize(a.size());

  for(int i = 0; i < a.size(); i++)
    b[i] = a[i];

  sort(b.begin(), b.end());
}

int GetCompressedValue(int i){
  return lower_bound(compressX.begin(), compressX.end(), i) - compressX.begin();
}

int GetOriginalValue(int i){
  return compressX[i];
}

void Update(int i, int x){
  for( ; i < T.size(); i += (i&-i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

int BinarySearch(int l, int k){
  int x = GetCompressedValue(l) + 1, y = T.size() - 1, z = y;

  while(x <= y){
    int mid = x + (y - x) / 2;

    if(Query(mid) >= k)
      x = mid + 1;
    else{
      z = mid;
      y = mid - 1;
    }
  }

  return GetOriginalValue(z) - 1;
}

int main(){
  int n, k;
  pii ans = MP(0, INT_MIN);

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    a.PB(MP(x, y));
  }

  PreProcess();
  
  for(auto p : b){
    int l = p.first, i = GetCompressedValue(l);

    Update(i, 1);
    Update(GetCompressedValue(p.second + 1), -1);

    if(Query(i) >= k){
      int r = BinarySearch(l, k);
      ans = max(ans, MP(r - l + 1, l));
    }
  }

  int l, r;

  if(ans.first == 0){
    printf("0\n");
    while(k--)
      printf("%d ", k + 1);
  }
  else{
    l = ans.second, r = l + ans.first - 1;
    printf("%d\n", ans.first);
    for(int i = 0; i < n && k; i++){
      if(a[i].first <= l && r <= a[i].second){
        printf("%d ", i + 1);
        k--;
      }
    }
  }

  printf("\n");

	return 0;
}
