#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;

  cin >> n;

  int ansx = 1, ansy = 0, maxY = 0, maxM = 0, minK = (n == 1) ? 0 : INT_MAX;
  for(int i = 2; i <= n; ++i){
    if(n % i != 0){
      continue;
    }

    int k = 0;
    for( ; n % i == 0; n /= i, ++k);

    int m = 1, y = 0;
    for(m = 1; m < k; m *= 2, ++y);

    ansx *= i;
    maxY = max(maxY, y);
    maxM = max(maxM, m);
    minK = min(minK, k);
  }

  ansy = maxY + (maxM != minK);

  cout << ansx << ' ' << ansy << '\n';

  return 0;
}
