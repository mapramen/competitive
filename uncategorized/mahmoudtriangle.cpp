#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
  int n;
  string ans = "NO";

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  sort(a + 1, a + n + 1);

  for(int i = n; i > 2; i--)
    if(a[i - 1] + a[i - 2] > a[i])
      ans = "YES";

  cout << ans << "\n";
  
  return 0;
}
