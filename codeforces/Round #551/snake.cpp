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

int queryCount = 0;

void PrintToInteractive(char c, int x1, int y1, int x2, int y2, bool invertRowColumn){
  if(invertRowColumn){
    swap(x1, y1);
    swap(x2, y2);
  }
  
  printf("%c %d %d %d %d\n", c, x1, y1, x2, y2);
  fflush(stdout);
}

bool Query(int x1, int y1, int x2, int y2, bool invertRowColumn){
  PrintToInteractive('?', x1, y1, x2, y2, invertRowColumn);
  int c;
  scanf("%d", &c);
  return (c % 2);
}

void PrintAns(int x1, int y1, int x2, int y2, bool invertRowColumn){
  PrintToInteractive('!', x1, y1, x2, y2, invertRowColumn);
}

int SearchInRow(int n, int x, bool invertRowColumn){
  int y;
  for(int y1 = 1, y2 = n; y1 <= y2; ){
    int yMid = y1 + (y2 - y1) / 2;
    if(Query(x, y1, x, yMid, invertRowColumn)){
      y = yMid, y2 = yMid - 1;
    }
    else{
      y1 = yMid + 1;
    }
  }
  return y;
}

bool SearchGrid(int n, bool invertRowColumn){
  vector<int> u, v;

  for(int x = 1; x <= n; ++x){
    u.push_back(x);
  }

  random_shuffle(u.begin(), u.end());

  for(int x : u){
    if(Query(x, 1, x, n, invertRowColumn)){
      v.push_back(x);
    }

    if(v.size() == 2){
      break;
    }
  }

  if(v.empty()){
    return false;
  }

  int x1 = v.front(), x2 = v.back();
  int y1 = SearchInRow(n, x1, invertRowColumn), y2 = SearchInRow(n, x2, invertRowColumn);

  PrintAns(x1, y1, x2, y2, invertRowColumn);
  
  return true;
}

int main(){
  int n;
  scanf("%d", &n);
  (SearchGrid(n, false) || SearchGrid(n, true));
  return 0;
}