#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N], p[N], c[N];

int main(){
  int n, m, valid = 1;

  cin >> n >> m;
  for(int i = 1; i <= m; i++)
    cin >> a[i];

  for(int i = 1; i < m; i++){
    int j = a[i], k = (n + a[i + 1] - a[i]) % n;
    if(k == 0)
      k = n;
    p[j] = k;
    c[k]++;
  }

  for(int i = 1, j = 1; i <= n && j <= n; i++){
    if(p[i])
      continue;

    for( ; j <= n && c[j] != 0; j++);
    if(j <= n){
      p[i] = j;
      c[j]++;
      j++;
    }
  }

  for(int i = 1; i <= n; i++)
    c[i] = 0;

  for(int i = 1; i <= n; i++)
    c[p[i]]++;

  for(int i = 1; i <= n && valid == 1; i++)
    valid = (c[i] == 1);

  for(int i = 1; i < m && valid == 1; i++){
    int j = a[i], k = (j + p[j] - 1) % n + 1;
    valid = (k == a[i + 1]);
  }

  if(valid){
    for(int i = 1; i <= n; i++)
      cout << p[i] << ' ';
    cout << '\n';
  }
  else
    cout << "-1\n";

  return 0;
}
