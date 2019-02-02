#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

pii a[3];

int main(){
  set< pii > origPoints;

  for(int i = 0; i < 3; i++){
    cin >> a[i].first >> a[i].second;
    origPoints.insert(a[i]);
  }

  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(k == i || k == j)
          continue;

        int x = a[i].first + a[j].first - a[k].first;
        int y = a[i].second + a[j].second - a[k].second;
        origPoints.insert(MP(x, y));
      }
    }
  }

  for(int i = 0; i < 3; i++)
    origPoints.erase(a[i]);

  cout << origPoints.size() << '\n';

  for(auto it : origPoints)
    cout << it.first << ' ' << it.second << '\n';

  return 0;
}
