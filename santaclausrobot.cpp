#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

char s[N];

int main(){
  int n, i, xdir, ydir, ans;

  scanf("%d", &n);
  scanf("%s", s);

  for(i = ans = 0, xdir = ydir = -1; i < n; i++){
    if(s[i] == 'U' && ydir != 0 && ydir != 'U')
      xdir = 0, ydir = 0, ans++;

    if(s[i] == 'D' && ydir != 0 && ydir != 'D')
      xdir = 0, ydir = 0, ans++;

    if(s[i] == 'L' && xdir != 0 && xdir != 'L')
      xdir = 0, ydir = 0, ans++;

    if(s[i] == 'R' && xdir != 0 && xdir != 'R')
      xdir = 0, ydir = 0, ans++;

    if(s[i] == 'U' || s[i] == 'D')
      ydir = s[i];
    else
      xdir = s[i];
  }

  printf("%d\n", ans);

  return 0;
}
