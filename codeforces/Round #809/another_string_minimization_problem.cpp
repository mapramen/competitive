#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  string ans = string(m, 'B');

  while(n--){
    int i;
    scanf("%d", &i);
    i = min(i, m - i + 1);

    if(ans[i - 1] != 'B'){
      ans[m - i] = 'A';
    }
    else{
      ans[i - 1] = 'A';
    }
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