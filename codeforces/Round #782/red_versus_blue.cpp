#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, r, b;
  scanf("%d%d%d", &n, &r, &b);

  int x = r / (b + 1), y = r % (b + 1);

  string ans;
  for(int i = 0; i <= 2 * b; ++i){
    int z = i % 2 == 0 ? x + min(1, y) : 1;
    char c = i % 2 == 0 ? 'R' : 'B';
    y = max(0, y - (i % 2 == 0));

    while(z--){
      ans.push_back(c);
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