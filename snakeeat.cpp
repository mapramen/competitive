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
    int n, q;
    vector<int> a(1);
    map< int, int > M;

    scanf("%d%d", &n, &q);

    for(int x = 1; x <= n; x++){
      int i;
      scanf("%d", &i);
      a.PB(i);
    }

    sort(a.begin() + 1, a.end());

    while(q--){
      int k, ans;
      scanf("%d", &k);

      if(M.find(k) == M.end()){
        int i = 0, j = lower_bound(a.begin() + 1, a.end(), k) - a.begin();
        ans = n - j + 1;
        for(--j; i + k - a[j] < j; ans++, i += (k - a[j]), j--);
        M[k] = ans;
      }
      else
        ans = M[k];

      printf("%d\n", ans);
    }
  }

  return 0;
}
