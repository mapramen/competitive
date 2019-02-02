#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int c[N];

int main(){
  int n;

  cin >> n;
  for(int i = 0; i < n; ++i){
    int k;
    cin >> k;
    while(k--){
      int x;
      cin >> x;
      ++c[x];
    }
  }

  for(int i = 1; i < N; ++i){
    if(c[i] == n){
      cout << i << " ";
    }
  }
  cout << "\n";

  return 0;
}
