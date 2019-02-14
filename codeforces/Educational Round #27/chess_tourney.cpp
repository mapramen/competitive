#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= 2 * n; ++i)
    cin >> a[i];

  sort(a + 1, a + 2 * n + 1);

  if(a[n] < a[n + 1])
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
