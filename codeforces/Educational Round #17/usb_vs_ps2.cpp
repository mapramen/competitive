#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int totalNo;
ll totalCost;

void TakeMouse(int a, priority_queue<int, vector<int>, greater<int> >& mouses){
  for( ; mouses.size() > 0 && a > 0; a--){
    totalNo++;
    totalCost += mouses.top();
    mouses.pop();
  }
}

int main(){
  int m, a, b, c, i, j, cost;
  priority_queue<int, vector<int>, greater<int> > usb, ps2;
  char s[5];

  scanf("%d%d%d", &a, &b, &c);

  scanf("%d", &m);

  while(m--){
    scanf("%d", &cost);
    scanf("%s", s);

    if(s[0] == 'U')
      usb.push(cost);
    else
      ps2.push(cost);
  }

  TakeMouse(a, usb);
  TakeMouse(b, ps2);

  while(!ps2.empty()){
    usb.push(ps2.top());
    ps2.pop();
  }

  TakeMouse(c, usb);

  cout << totalNo << ' ' << totalCost << '\n';

  return 0;
}
