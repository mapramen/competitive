#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

string Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  string ans;
  for(int i = n, m = 0; i != 0; --i){
    if(a[i] <= m){
      ans.push_back('1');
      continue;
    }

    if(m < q){
      ans.push_back('1');
      ++m;
      continue;
    }

    ans.push_back('0');
  }
  reverse(ans.begin(), ans.end());

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