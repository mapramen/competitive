#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 8

int d[N], f1[N], f2[N];

bool Check(int f[], int a, int b, int c){
  return (f[1] + f[2] + f[3] + f[4] <= a)
  && (f[1] + f[2] + f[5] + f[6] <= b)
  && (f[1] + f[3] + f[5] + f[7] <= c);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    for(int i = 1; i < N; ++i){
      cin >> d[i];
    }

    bool groupSwapped = false;
    if(a2 + b2 + c2 < a1 + b1 + c1){
      swap(a1, a2);
      swap(b1, b2);
      swap(c1, c2);
      groupSwapped = true;
    }

    bool found = false;
    for(int x = 0, xmax = min(d[2], min(a1, b1)); x <= xmax && !found; ++x){
      for(int y = 0, ymax = min(d[3], min(a1 - x, c1)); y <= ymax && !found; ++y){
        for(int z = 0, zmax = min(d[5], min(b1 - x, c1 - y)); z <= zmax && !found; ++z){
          f1[2] = x, f1[3] = y, f1[5] = z;

          f1[1] = max(0, min(min(d[1], a1 - x - y), min(b1 - x - z, c1 - y - z)));
          
          f1[4] = min(d[4], max(0, a1 - x - y - f1[1]));
          f1[6] = min(d[6], max(0, b1 - x - z - f1[1]));
          f1[7] = min(d[7], max(0, c1 - y - z - f1[1]));

          f2[1] = d[1] - f1[1];
          f2[2] = d[2] - f1[2];
          f2[3] = d[3] - f1[3];
          f2[4] = d[4] - f1[4];
          f2[5] = d[5] - f1[5];
          f2[6] = d[6] - f1[6];
          f2[7] = d[7] - f1[7];

          found = Check(f2, a2, b2, c2);
        }
      }
    }

    if(!found){
      cout << "-1\n";
      continue;
    }

    for(int i = 1; i < N; ++i){
      cout << (groupSwapped ? d[i] - f1[i] : f1[i]) << ' ';
    }
    cout << '\n';
  }
  return 0;
}