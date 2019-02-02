#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int c[N];

int main(){
  int n;
  c[0] = 1;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    if(c[j])
      --c[j];
    ++c[i];
  }

  int ans = 0;
  for(int i = 0; i <= n; ++i)
    ans += c[i];

  printf("%d\n", ans);

  return 0;
}
