#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], prefix[N], suffix[N];
vector<int> T;

void Update(int i, int x, bool invert){
  if(invert)
    i = T.size() - i;
  for( ; i < T.size(); i += (i & -i))
    T[i] = max(T[i], x);
}

int Query(int i, bool invert){
  if(invert)
    i = T.size() - i;
  int ans = 0;
  for(i = min((int)T.size() - 1, i); i > 0; i -= (i & -i))
    ans = max(ans, T[i]);
  return ans;
}

void PreProcess(int n){
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    a[i] -= i;
    v.PB(a[i]);
    v.PB(a[i] + 1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 1; i <= n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  T.resize(v.size() + 1);
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    prefix[i] = 1 + Query(a[i], 0);
    Update(a[i], prefix[i], 0);
  }

  fill(T.begin(), T.end(), 0);

  int ans = prefix[n - 1];
  for(int i = n - 1; i > 0; --i){
    a[i + 1] += 1;
    suffix[i + 1] = 1 + Query(a[i + 1], 1);
    Update(a[i + 1], suffix[i + 1], 1);
    int ansx = prefix[i - 1] + Query(a[i - 1], 1);
    ans = max(ans, ansx);
  }

  ans = n - 1 - ans;

  printf("%d\n", ans);

  return 0;
}
