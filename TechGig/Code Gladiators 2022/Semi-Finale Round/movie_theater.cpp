#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int s, t, q;
  scanf("%d%d%d", &s, &t, &q);

  set<int> S;
  while(t--){
    int x;
    scanf("%d", &x);
    S.insert(x);
  }

  while(q--){
    int x;
    scanf("%d", &x);
    printf("%c\n", S.count(x) != 0 ? 'N' : 'Y');
  }
  
  return 0;
}