#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int ans = 2 * (t1 - t2) + s * (v1 - v2);
  if(ans == 0)
    cout << "Friendship\n";
  else if(ans < 0)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}
