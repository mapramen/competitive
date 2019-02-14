#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100

int a[N], b[N];

int main(){
  int n, m;

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i + n] = a[i];
  }

  for(int i = 0; i < n; i++){
    cin >> b[i];
    b[i + n] = b[i];
  }

  for(int i = 0; i < 2 * n - 1; i++){
    a[i] = (a[i + 1] - a[i] + m) % m;
    b[i] = (b[i + 1] - b[i] + m) % m;
  }

  for(int i = 0; i < 2 * n; i++){
    int k;
    for(k = 0; k < n && i + k < 2 * n && a[i + k] == b[k]; k++);
    if(k == n){
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
