#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define L 10

char ss[L];

int main(){
  int n, ans = 0, nxt = 1;
  stack<int> s;

  scanf("%d", &n);
  n *= 2;
  while(n--){
    scanf("%s", ss);
    if(ss[0] == 'a'){
      int x;
      scanf("%d", &x);
      s.push(x);
    }
    else{
      if(s.empty() || s.top() == nxt){
        if(!s.empty())
          s.pop();
      }
      else{
        ans++;
        while(!s.empty())
          s.pop();
      }
      nxt++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
