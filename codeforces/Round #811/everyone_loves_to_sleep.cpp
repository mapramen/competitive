#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MINS_IN_HOUR 60
#define HOURS_IN_DAY 24
#define MINS_IN_DAY (MINS_IN_HOUR * HOURS_IN_DAY)

int ReadTime(){
  int h, m;
  scanf("%d%d", &h, &m);
  return h * MINS_IN_HOUR + m;
}

void Solve(){
  int n;
  scanf("%d", &n);

  int a = ReadTime(), ans = INT_MAX;
  while(n--){
    int b = ReadTime();
    int ansx = (MINS_IN_DAY + b - a) % MINS_IN_DAY;
    ans = min(ans, ansx);
  }

  printf("%d %d\n", ans / MINS_IN_HOUR, ans % MINS_IN_HOUR);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}