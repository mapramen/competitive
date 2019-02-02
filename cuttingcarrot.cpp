#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, h;

  scanf("%d%d", &n, &h);

  for(int i = 1; i < n; i++){
    double ans = i;
    ans /= n;
    ans = sqrt(ans) * h;
    printf("%.12lf ", ans);
  }
  printf("\n");

  return 0;
}
