#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];
vector< vector<int> > v(3);

int main(){
  int n, i, j, k, ans;

  scanf("%d%d", &n, &k);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(i = 1, ans = 0; i <= n; i = j){
    if(a[i] < 0){
      ans++;
      for(j = i; j <= n && a[j] < 0; j++, k--);
    }
    else{
      for(j = i; j <= n && a[j] >= 0; j++);

      if(i != 1){
        ans++;
        if(j != n + 1)
          v[2].PB(j - i);
        else
          v[1].PB(j - i);
      }
    }
  }

  for(j = 2; j > 0 && k > 0; j--){
    sort(v[j].begin(), v[j].end());

    for(auto i : v[j]){
      if(i <= k){
        ans -= j;
        k -= i;
      }
      else
        break;
    }
  }

  if(k < 0)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
