#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vd vector<double>
#define vvd vector< vector<double> >
#define PB push_back
#define MP make_pair

const int MAX_ITER = 100;
const double ROOT2 = sqrt(2);
const double ROOT3 = sqrt(3);

vvd GetCornerPoints(){
  vvd P(3, vd(4));
  P[0][0] = P[0][1] = P[0][2] = P[0][3] = 0.5;
  P[1][0] = P[1][1] = P[2][0] = P[2][3] = -0.5;
  P[1][2] = P[1][3] = P[2][1] = P[2][2] = 0.5;
  return P;
}

vvd GetFaceCenterPoints(){
  vvd P(3, vd(3));

  P[0][0] = 0.5;
  P[1][1] = 0.5;
  P[2][2] = 0.5;

  return P;
}

void PrintPoints(vvd P){
  for(int j = 0; j < P[0].size(); ++j){
    for(int i = 0; i < P.size(); ++i){
      printf("%.15lf ", P[i][j]);
    }
    printf("\n");
  }
}

double GetSinFromCos(double cs){
  return sqrt(abs(1 - cs * cs));
}

vvd GetRotationMatrixY(double cosy = 1.0){
  double siny = GetSinFromCos(cosy);
  vvd R(3, vd(3));

  R[0][0] = cosy;
  R[0][2] = siny;
  R[1][1] = 1;
  R[2][0] = -siny;
  R[2][2] = cosy;

  return R;
}

vvd GetRotationMatrixX(double cosx = 1.0){
  double sinx = GetSinFromCos(cosx);
  vvd R(3, vd(3));

  R[0][0] = 1;
  R[1][1] = cosx;
  R[1][2] = -sinx;
  R[2][1] = sinx;
  R[2][2] = cosx;

  return R;
}

vvd MatrixMultiplication(vvd A, vvd B){
  int n = A.size(), m = B.size(), p = B[0].size();
  vvd C(n, vd(p));

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < p; ++j)
      for(int k = 0; k < m; ++k)
        C[i][j] += A[i][k] * B[k][j];

  return C;
}

double Area(vvd P){
  double a = abs(P[0][0]), b = 0, c = abs(abs(P[0][1]) - a);

  for(int i = 0; i < P[0].size(); ++i)
    for(int j = 0; j < P[0].size(); ++j)
      b = max(b, abs(P[1][i] - P[1][j]) / 2);

  double area = 2 * b * (2 * a + c);

  return area;
}

vvd RectangleAreaSearch(double area){
  // printf("RectangleAreaSearch\n");
  double cosX = 1, cosY = 1 / ROOT2;
  vvd P = GetCornerPoints(), ans = GetRotationMatrixX(cosX);

  for(int iter = 0; iter < MAX_ITER; ++iter){
    double cosMid = (cosX + cosY) / 2;
    // printf("cosX = %.15lf cosY = %.15lf cosMid = %.15lf\n", cosX, cosY, cosMid);
    vvd R = GetRotationMatrixX(cosMid);
    vvd Q = MatrixMultiplication(R, P);
    if(Area(Q) <= area){
      ans = R;
      cosX = cosMid;
    }
    else
      cosY = cosMid;
  }

  return ans;
}

vvd HexagonAreaSearch(double area){
  // printf("HexagonAreaSearch\n");
  double cosX = 1, cosY = ROOT2 / ROOT3;
  vvd P = GetCornerPoints(), ans = GetRotationMatrixY(cosX);
  P = MatrixMultiplication(GetRotationMatrixX(0), P);

  for(int iter = 0; iter < MAX_ITER; ++iter){
    double cosMid = (cosX + cosY) / 2;
    // printf("cosX = %.15lf cosY = %.15lf cosMid = %.15lf\n", cosX, cosY, cosMid);
    vvd R = GetRotationMatrixY(cosMid);
    vvd Q = MatrixMultiplication(R, P);
    if(Area(Q) <= area){
      ans = R;
      cosX = cosMid;
    }
    else
      cosY = cosMid;
  }

  ans = MatrixMultiplication(GetRotationMatrixX(0), ans);

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    double area;
    vvd ans;

    scanf("%lf", &area);
    if(area <= ROOT2)
      ans = RectangleAreaSearch(area);
    else
      ans = HexagonAreaSearch(area);

    ans = MatrixMultiplication(ans, GetFaceCenterPoints());

    printf("Case #%d:\n", k);
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        printf("%.15lf ", ans[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
