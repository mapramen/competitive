#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k;
  vector<int> v;

  cin >> n >> k;

  for(int i = 2; i <= n; i++){
    while(n % i == 0){
      v.PB(i);
      n /= i;
    }
  }

  if(n > 1)
    v.PB(n);

  if(v.size() < k)
    printf("-1\n");
  else{
    for(int i = 0, j = 1; j <= k; i++, j++){
      int ans = 1;
      if(j == k)
        for( ; i < v.size(); i++)
          ans *= v[i];
      else
        ans = v[i];
      cout << ans << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}
