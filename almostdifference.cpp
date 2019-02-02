#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];
vector<int> C;
vector<ll> T1, T2;

void Update(vector<ll>& T, int i, int x){
  for( ; i != 0 && i < T.size(); i += (i & -i))
    T[i] += x;
}

ll Query(vector<ll>& T, int i){
  int j = i;
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

ll Query(vector<ll>& T, int i, int j){
  if(i < 0 || j < 0 || i > j)
    return 0ll;
  return Query(T, j) - Query(T, i - 1);
}

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

void PreProcess(int n){
  for(int i = 1; i <= n; ++i)
    for(int x = a[i] - 3; x < a[i] + 3; ++x)
      C.PB(x);

  RemoveDuplicates(C);

  T1.resize(C.size());
  T2.resize(C.size());
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  PreProcess(n);

  ull ans1 = 0, ans2 = 0;
  for(int i = 1, m = T1.size() - 1; i <= n; ++i){
    int ci = GetCompressedValue(a[i]);
    ans1 += Query(T1, 1, ci - 2) * a[i] - Query(T2, 1, ci - 2);
    ans2 += Query(T2, ci + 2, m) - Query(T1, ci + 2, m) * a[i];
    Update(T1, ci, 1);
    Update(T2, ci, a[i]);
  }

  if(ans1 >= ans2)
    printf("%llu\n", ans1 - ans2);
  else
    printf("-%llu\n", ans2 - ans1);

  return 0;
}
