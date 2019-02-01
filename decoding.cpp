#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

int a[N];

int main(){
  int n, i, j, k;
  string s;

  cin >> n;
  cin >> s;

  if(n % 2){
    j = (n + 1) / 2;
    a[j] = 1;
  }

  for(i = 1 + (n % 2), j = n / 2; j > 0; i += 2, j--)
    a[j] = i;

  for(i = 2 + (n % 2), j = (n + 1) / 2 + 1; j <= n; i += 2, j++)
    a[j] = i;

  for(i = 1; i <= n; i++)
    cout << s[a[i] - 1];
  cout << '\n';

  return 0;
}
