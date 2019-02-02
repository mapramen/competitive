#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int a[24];
int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> v;

int main(){
  int n;

  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  for(int i = 0; i < 400; ++i){
    if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
      d[1] = 29;
    else
      d[1] = 28;
    for(int j = 0; j < 12; ++j)
      v.PB(d[j]);
  }

  int m = v.size();
  for(int i = 0; i < m; ++i)
    v.PB(v[i]);

  for(int i = 0; i < m; ++i){
    int c = 0;
    for(int j = i, k = 0; k < n && v[j] == a[k]; ++j, ++k, ++c);
    if(c == n){
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");

  return 0;
}
