#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0, cnt = 0, cs = 400;
  stack<int> p;

  scanf("%d", &n);

  p.push(400);
  while(n--){
    int t, ns;
    scanf("%d", &t);

    if(t == 1 || t == 3)
      scanf("%d", &ns);

    if(t == 1)
      cs = ns;
    else if(t == 2)
      ans += cnt, cnt = 0;
    else if(t == 3)
      p.push(ns);
    else if(t == 4)
      cnt = 0;
    else if(t == 5){
      while(p.size() > 1)
        p.pop();
    }
    else
      cnt++;

    while(p.top() < cs){
      p.pop();
      ans++;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}
