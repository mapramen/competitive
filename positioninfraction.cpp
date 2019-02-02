#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

bool visited[N];

int main(){
  int a, b, c;

  cin >> a >> b >> c;

  for(int i = 1, r = a; ; ++i, r %= b){
    if(visited[r])
      break;

    visited[r] = 1;
    r *= 10;
    int d = 0;
    for(int s = 0; s <= r; s += b, ++d);
    --d;
    if(d == c){
      cout << i << '\n';
      return 0;
    }
  }

  cout << "-1\n";

  return 0;
}
