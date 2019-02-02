#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

bool isHole[N], isBone[N];

int main(){
  int n, m, k, ans;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    int i;
    scanf("%d", &i);
    isHole[i] = 1;
  }

  isBone[1] = 1;

  while(k--){
    int i, j;
    scanf("%d%d", &i, &j);

    if(isBone[i] == 0)
      swap(i, j);

    if(isHole[i] == 0)
      swap(isBone[i], isBone[j]);
  }

  for(ans = 1; ans <= n && isBone[ans] == 0; ans++);

  printf("%d\n", ans);
  
  return 0;
}
