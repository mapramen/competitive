#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int n, a[N];
bool valid[N];
string t, p;

bool Check(int m){
  int ans = 0;

  for(int i = 1; i <= n; i++)
    valid[i] = 1;

  for(int i = 1; i <= m; i++)
    valid[a[i]] = 0;

  for(int i = 1; i <= n && ans < p.size(); i++)
    if(valid[i] && p[ans] == t[i - 1])
      ans++;

  return (ans == p.size());
}

int BinarySearch(){
  int x = 0, y = n, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid)){
      z = mid;
      x = mid + 1;
    }
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  cin >> t >> p;
  n = t.size();

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  cout << BinarySearch() << '\n';
  
  return 0;
}
