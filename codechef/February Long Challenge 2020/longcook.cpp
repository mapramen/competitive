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
#define N 400

const vector<int> t{0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
const vector<int> a{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int c[N];

int NumberDaysInMonth(int m, int y){
  if(m != 2){
    return a[m];
  }

  if(y % 400 == 0){
    return 29;
  }

  if(y % 100 == 0){
    return 28;
  }

  return 28 + (y % 4 == 0);
}

int DayFromDate(int d, int m, int y){
  y -= m < 3;
  return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; 
}

int FirstFriday(int m, int y){
  int d = 1, dm = NumberDaysInMonth(m, y);
  for(; DayFromDate(d, m, y) != 5; ++d);
  return d;
}

int PenultimateSunday(int m, int y){
  int dm = NumberDaysInMonth(m, y), d = dm, c = 0;
  for(; !(c == 1 && DayFromDate(d, m, y) == 0); --d){
    c += (DayFromDate(d, m, y) == 0);
  }
  return d;
}

bool IsYearIntersting(int y){
  const int m = 2;
  int a = FirstFriday(m, y), b = a + 9, c = PenultimateSunday(m, y);
  return a <= c && c <= b;
}

void Initialize(){
  for(int i = 1; i < N; ++i){
    c[i] = c[i - 1] + IsYearIntersting(i);
  }
}

int QueryYear(int y){
  if(y < 0){
    return 0;
  }

  return (y / N) * c[N - 1] + c[(y % N)];
}

int QueryMonthYear(int m, int y){
  return QueryYear(y - (m < 2));
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  while(t--){
    int m1, m2, y1, y2;
    scanf("%d%d%d%d", &m1, &y1, &m2, &y2);
    printf("%d\n", QueryMonthYear(m2, y2) - QueryMonthYear(m1 - 1, y1));
  }

  return 0;
}