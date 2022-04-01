#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n;
  scanf("%d", &n);

  string ans;
  for(int x = n % 3 == 1 ? 1 : 2; n != 0; n -= x, x = 3 - x){
    ans.push_back('0' + x);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}