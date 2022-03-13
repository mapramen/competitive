#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
 
int a[N], idx[N];
 
int GetCount(int n, int x){
  return x <= 1 || x > n ? 0 : idx[x] < idx[x - 1];
}
 
int CollectCount(int n, vector<int>& v){
  int ans = 0;
  for(int x: v){
    ans += GetCount(n, x);
  }
  return ans;
}
 
int main(){
  int n, q;
  scanf("%d%d", &n, &q);
 
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] = x, idx[x] = i;
  }
 
  int ans = 1;
  for(int x = 1; x <= n; ++x){
    ans += GetCount(n, x);
  }
 
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
 
    int x = a[i], y = a[j];
    
    vector<int> v{x, x + 1, y, y + 1};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
 
    ans -= CollectCount(n, v);
 
    swap(a[i], a[j]);
    swap(idx[x], idx[y]);
 
    ans += CollectCount(n, v);
 
    printf("%d\n", ans);
  }
  
  return 0;
}