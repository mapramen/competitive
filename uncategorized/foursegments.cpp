#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

ll s[N];

int main(){
  int n, x = 0, y = 0, z = 0;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> s[i];
    s[i] += s[i - 1];
  }

  for(int i = 0; i <= n; ++i){
    for(int j = i, k = i; k <= n; ++k){
      if(s[k] < s[j])
        j = k;
      if(s[i] + s[k] - s[j] > s[x] + s[z] - s[y])
        x = i, y = j, z = k;
    }
  }

  cout << x << ' ' << y << ' ' << z << '\n';

  return 0;
}
