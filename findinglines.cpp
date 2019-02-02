#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAXX 1E8

vector<int> diagonalPoints, horizontalLines, verticalLines;

int QueryPoint(int x, int y){
  int d;
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &d);
  return d;
}

void FindDiagonalPoints(int lo, int hi){
  if(hi < lo)
    return ;

  int mid = lo + (hi - lo) / 2;
  int d = QueryPoint(mid, mid);

  if(d == 0)
    diagonalPoints.PB(mid);

  d = max(1, d);

  FindDiagonalPoints(lo, mid - d);
  FindDiagonalPoints(mid + d, hi);
}

int main(){
  int referencePoint = 0;
  FindDiagonalPoints(-MAXX, MAXX);

  sort(diagonalPoints.begin(), diagonalPoints.end());
  diagonalPoints.erase(unique(diagonalPoints.begin(), diagonalPoints.end()), diagonalPoints.end());

  for(int i = 0; i < diagonalPoints.size(); i++)
    referencePoint += (diagonalPoints[i] == referencePoint);

  for(auto x : diagonalPoints){
    if(QueryPoint(x, referencePoint) == 0)
      verticalLines.PB(x);
    if(QueryPoint(referencePoint, x) == 0)
      horizontalLines.PB(x);
  }

  printf("1 %lu %lu\n", verticalLines.size(), horizontalLines.size());

  for(auto x : verticalLines)
    printf("%d ", x);
  printf("\n");

  for(auto y : horizontalLines)
    printf("%d ", y);
  printf("\n");

  fflush(stdout);

  return 0;
}
