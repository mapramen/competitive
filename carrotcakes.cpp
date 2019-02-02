#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int GetTime(int t1, int t2, int n, int k, int t){
  while(n > 0){
    t1 += t;
    n -= k;
    if(t1 > t2)
      swap(t1, t2);
  }

  if(t2 == INT_MAX)
    return t1;
  else
    return max(t1, t2);
}

int main(){
  int n, t, k, d;

  cin >> n >> t >> k >> d;

  if(GetTime(0, INT_MAX, n, k, t) <= GetTime(0, d, n, k, t))
    cout << "NO\n";
  else
    cout << "YES\n";

  return 0;
}
