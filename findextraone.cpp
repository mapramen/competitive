#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, c = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    if(x > 0)
      ++c;
  }

  if(c <= 1 || c >= n - 1)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
