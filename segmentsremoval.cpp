#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200002

int a[N];
map<int,int> M;
priority_queue< pii > Q;

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ){
    int j = i;
    for(; j <= n && a[j] == a[i]; ++j);
    int k = j - i;
    M[i] = k;
    Q.push(MP(k, -i));
    i = j;
  }
  M[0] = 0;
  M[n + 1] = 0;

  int ans = 0;
  while(M.size() > 2){
    int k, i;
    tie(k, i) = Q.top();
    Q.pop();
    i = -i;

    if(M.find(i) == M.end() || (M[i] != k))
      continue;

    ++ans;

    auto it = M.find(i);
    --it;
    int x = it->first;
    ++it;
    ++it;
    int y = it->first;
    M.erase(i);

    if(a[y] == a[x]){
      M[x] += M[y];
      M.erase(y);
      Q.push(MP(M[x], -x));
    }
  }

  printf("%d\n", ans);

  return 0;
}
