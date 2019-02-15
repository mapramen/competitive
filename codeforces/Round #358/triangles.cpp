// https://web.stanford.edu/~liszt90/acm/notebook.html#file8
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define REMOVE_REDUNDANT

double PI = 4*atan(1);

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};


double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}

double areaTriangle(PT a, PT b, PT c){
  return abs(cross(b - a, c - a));
}

int main(){
  int n, i, j, k, m;
  PT a, b, c, M;
  ll temp;
  double maxArea = 0;
  
  cin >> n >> temp;

  vector< PT > pts;

  while(n--){
    scanf("%d%d", &i, &j);
    pts.PB(PT(i,j));
  }

  ConvexHull(pts);

  n = pts.size();

  for(i = 0; i < n; i++){
    j = (i + 1) % n;
    k = (j + 1) % n;
    m = 1;

    while(m){
      m = 0;
      
      while(areaTriangle(pts[i],pts[j],pts[(k + 1) % n]) > areaTriangle(pts[i], pts[j], pts[k])){
        k = (k + 1) % n;
        m++;
      }

      while(areaTriangle(pts[i],pts[(j + 1) % n],pts[k]) > areaTriangle(pts[i], pts[j], pts[k])){
        j = (j + 1) % n;
        m++;
      }
    }

    if(areaTriangle(pts[i], pts[j], pts[k]) > maxArea){
      maxArea = areaTriangle(pts[i], pts[j], pts[k]);
      a = pts[i];
      b = pts[j];
      c = pts[k];
    }
  }

  M = a + b + c;

  a = M - a * 2;
  b = M - b * 2;
  c = M - c * 2;

  printf("%d %d\n", (int)(a.x), int(a.y));
  printf("%d %d\n", (int)(b.x), int(b.y));
  printf("%d %d\n", (int)(c.x), int(c.y));

  return 0;
}