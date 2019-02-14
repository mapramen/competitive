#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 501

int maxX, maxY, inf = INT_MAX / 2;
vector<int> H, V;
vector< pii > points;
vector< tiii > segments;

void AddSegment(int x, int y, int val){
  if(x < 1 || x > maxX || y < 1 || y > maxY)
    return ;
  segments.PB(MT(x, y, val));
}

void AddHorizontalPoint(int x){
  if(x < 1 || x > maxX)
    return ;
  H.PB(x);
}

void AddVerticalPoint(int y){
  if(y < 1 || y > maxY)
    return ;
  V.PB(y);
}

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedX(int x){
  return lower_bound(H.begin(), H.end(), x) - H.begin();
}

int GetCompressedY(int y){
  return lower_bound(V.begin(), V.end(), y) - V.begin();
}

void CompressXY(){
  RemoveDuplicates(H);
  RemoveDuplicates(V);
  sort(segments.begin(), segments.end());
  for(int i = 0; i < segments.size(); ++i){
    int x, y, z;
    tie(x, y, z) = segments[i];
    segments[i] = MT(GetCompressedX(x), GetCompressedY(y), z);
  }
}

bool Check(int t){
  AddHorizontalPoint(1);
  AddHorizontalPoint(maxX);

  AddVerticalPoint(1);
  AddVerticalPoint(maxY);

  for(auto point : points){
    int x, y;
    tie(x, y) = point;
    int x1 = max(1, x - t), x2 = min(maxX, x + t);
    int y1 = max(1, y - t), y2 = min(maxY, y + t);

    AddSegment(x1, y1, 1);
    AddSegment(x1, y2 + 1, -1);
    AddSegment(x2 + 1, y1, -1);
    AddSegment(x2 + 1, y2 + 1, 1);

    AddHorizontalPoint(x1 - 1);
    AddHorizontalPoint(x1);
    AddHorizontalPoint(x2);
    AddHorizontalPoint(x2 + 1);

    AddVerticalPoint(y1 - 1);
    AddVerticalPoint(y1);
    AddVerticalPoint(y2);
    AddVerticalPoint(y2 + 1);
  }

  CompressXY();

  int n = H.size(), m = V.size(), l = segments.size(), X1 = inf, X2 = -1, Y1 = inf, Y2 = -1;
  vector<int> C(m), D(m);

  for(int j = 0; j < m; ++j)
    C[j] = 0;

  for(int i = 0, k = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
      D[j] = 0;

    for( ; k < l; ++k){
      int x, y, z;
      tie(x, y, z) = segments[k];
      if(x != i)
        break;
      D[y] += z;
    }

    for(int j = 0; j < m; ++j){
      if(j)
        D[j] += D[j - 1];
      C[j] += D[j];
      if(C[j] == 0)
        X1 = min(X1, i), X2 = max(X2, i), Y1 = min(Y1, j), Y2 = max(Y2, j);
    }
  }

  bool check = 0;

  if(X2 == -1 || Y2 == -1)
    check = 1;
  else{
    int tx = (max(H[X2] - H[X1], V[Y2] - V[Y1]) + 1) / 2;
    check = (tx <= t);
  }

  segments.clear();
  H.clear();
  V.clear();

  return check;
}

int BinarySearch(){
  int x = 0, y = inf, z = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  int k;

  scanf("%d%d%d", &maxX, &maxY, &k);
  while(k--){
    int x, y;
    scanf("%d%d", &x, &y);
    points.PB(MP(x, y));
  }

  printf("%d\n", BinarySearch());

  return 0;
}
