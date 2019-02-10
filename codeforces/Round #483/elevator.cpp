#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define node tuple< int, int, int, vector<int> >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 2000
#define F 9
#define M 4

set< node > S;
int a[N], b[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d%d", &a[i], &b[i]);
    --a[i];
    --b[i];
  }

  queue< node > Q;
  queue< int > D;

  S.insert(MT(0, 0, 0, vector<int>()));
  Q.push(MT(0, 0, 0, vector<int>()));
  D.push(0);

  while(!Q.empty()){
    int doneCount, nextIndex, currentFloor, d;
    vector<int> v;

    tie(doneCount, nextIndex, currentFloor, v) = Q.front();
    d = D.front();

    Q.pop();
    D.pop();

    // printf("%d %d %d: ", doneCount, nextIndex, currentFloor);
    // for(auto i : v)
    //   printf("%d ", i);
    // printf("\n%d\n", d);

    if(doneCount == n){
      printf("%d\n", d);
      break;
    }

    for(int diffFloor = -1; diffFloor < 2; ++diffFloor){
      int nextFloor = currentFloor + diffFloor, _doneCount = doneCount, _nextIndex = nextIndex, _d = d;
      vector<int> u(v);

      if(nextFloor != currentFloor){
        if(nextFloor < 0 || nextFloor >= F){
          continue;
        }

        _d += 1;
      }
      else{
        u.clear();
        bool dirty = 0;

        for(auto i : v){
          if(i == currentFloor && dirty == 0){
            ++_doneCount;
            ++_d;
            dirty = 1;
          }
          else{
            u.PB(i);
          }
        }

        if(!dirty && _nextIndex < n && a[_nextIndex] == currentFloor && u.size() < M){
          u.PB(b[_nextIndex]);
          ++_nextIndex;
          ++_d;
        }

        if(_nextIndex != nextIndex){
          sort(u.begin(), u.end());
        }
      }

      node child = MT(_doneCount, _nextIndex, nextFloor, u);

      if(S.find(child) == S.end()){
        S.insert(child);
        Q.push(child);
        D.push(_d);
      }
    }
  }

  return 0;
}
