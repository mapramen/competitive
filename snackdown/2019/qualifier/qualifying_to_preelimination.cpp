#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  scanf("%d", &t);

  while(t--){
    int n, k;

    scanf("%d%d", &n, &k);

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
      scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end(), greater<int>());

    int ans = k;
    for( ; ans < n && a[ans] == a[k - 1]; ++ans);

    printf("%d\n", ans);
  }

  return 0;
}
