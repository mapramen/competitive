#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Area(int x1, int y1, int x2, int y2){
  return 1ll * max(0, x2 - x1 + 1) * max(0, y2 - y1 + 1);
}

ll Solve(){
  int n;
  string s;

  cin >> n >> s;

  int D = n - 1, R = n - 1;
  for(char c: s){
    D -= (c == 'D');
    R -= (c == 'R');
  }

  int d = 0, r = 0;
  int px1 = 0, py1 = 0, px2 = 0, py2 = 0;
  int x = 1, y = 1;
  
  ll ans = 0;
  for(char c: s){
    int cx1 = x, cy1 = y;

    if(c == 'D'){
      ++x, ++d;
    }
    else{
      ++y, ++r;
    }
    
    int cx2 = x, cy2 = y;
    if(d != 0){
      cx2 += D;
    }

    if(r != 0){
      cy2 += R;
    }

    ans += (Area(cx1, cy1, cx2, cy2) - Area(cx1, cy1, px2, py2));
    px1 = cx1, py1 = cy1, px2 = cx2, py2 = cy2;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}