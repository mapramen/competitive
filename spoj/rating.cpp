#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

pii a[N];
int T[N], ans[N];

void Update(int i){
  for( ; i < N; i += (i & -i)){
    ++T[i];
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    v.push_back(i);
  }

  sort(v.begin(), v.end(), [](int i, int j) { return a[i] < a[j]; });

  int c = 0;
  pii previous = {INT_MIN, INT_MIN};
  for(int i: v){
    if(a[i] != previous){
      c = 0;
    }

    ans[i] = Query(a[i].second) - c;
    
    Update(a[i].second);
    previous = a[i], ++c;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d\n", ans[i]);
  }

  return 0;
}