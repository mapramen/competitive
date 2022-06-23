#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> intervals;

void AddInterval(int l, int r){
  if(l > r){
    return;
  }
  intervals[l] = r;
}

void Split(int x){
  auto it = prev(intervals.upper_bound(x));
  if(it->second < x){
    return;
  }

  int l = it->first, r = it->second;
  intervals.erase(it);
  
  AddInterval(l, x - 1);
  AddInterval(x, x);
  AddInterval(x + 1, r);
}

int main(){
  AddInterval(0, 0);
  AddInterval(1, 2E9);

  int q;
  scanf("%d", &q);

  while(q--){
    int t, x;
    scanf("%d%d", &t, &x);

    Split(x);

    if(t == 2){
      AddInterval(x, x);
      continue;
    }

    x = intervals.lower_bound(x)->first;
    Split(x);
    intervals.erase(x);

    printf("%d\n", x);
  }
  
  return 0;
}