#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], b[N];
ll c[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; ++i){
      scanf("%d", &b[i]);
    }

    for(int i = 1; i <= n; ++i){
      c[i] = b[i] - a[i];
    }

    for(int i = 1; i <= n - 2; ++i){
      if(c[i] < 0){
        break;
      }
      c[i + 1] -= 2 * c[i];
      c[i + 2] -= 3 * c[i];
      c[i] = 0;
    }

    bool valid = 1;
    for(int i = 1; i <= n && valid == 1; ++i){
      valid = (c[i] == 0);
    }

    printf("%s\n", valid ? "TAK" : "NIE");
  }

  return 0;
}
