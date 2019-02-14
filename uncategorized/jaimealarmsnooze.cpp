#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define TOTAL_MINUTES 24 * 60

bool IsTimeLucky(int minutes){
  int hour = minutes / 60;
  minutes %= 60;
  return (hour % 10 == 7 || minutes % 10 == 7);
}

int main(){
  int x, h, m;

  cin >> x >> h >> m;

  int t = 60 * h + m;
  int ans = 0;

  while(!IsTimeLucky(t)){
    ++ans;
    t -= x;
    if(t < 0)
      t += TOTAL_MINUTES;
  }

  cout << ans << '\n';

  return 0;
}
