#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  stack<int> S;
  S.push(0);

  while(n--){
    int x;
    scanf("%d", &x);

    if(S.top() != 0 && x + S.top() == 0){
      S.pop();
      continue;
    }

    S.push(x);
  }

  printf("%lu\n", S.size() - 1);

  return 0;
}