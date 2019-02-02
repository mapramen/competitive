#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int QueryAndGetColor(int x){
  cout <<  x << " 1\n";
  fflush(stdout);

  string s;
  cin >> s;
  return s[0] == 'b';
}

int main(){
  int n;

  cin >> n;

  int baseColor = QueryAndGetColor(0), maxBaseColorCoordinate = 0;
  --n;

  for(int x = 1, y = (1 << n) - 1; x <= y; ){
    int mid = (x + y) / 2;
    int color = QueryAndGetColor(mid);
    if(color == baseColor){
      maxBaseColorCoordinate = max(maxBaseColorCoordinate, mid);
      x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  cout << maxBaseColorCoordinate << " 0 " << maxBaseColorCoordinate + 1 << " 2\n";

  return 0;
}
