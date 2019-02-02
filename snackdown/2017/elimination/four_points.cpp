#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple

pii p[4];

int TwiceAreaTriangle(pii a, pii b, pii c){
  int x1 = b.first - a.first, y1 = b.second - a.second, x2 = c.first - a.first, y2 = c.second - a.second;
  return abs(x1 * y2 - x2 * y1);
}

tiii GetLine(pii a, pii b, pii c){
  int ma = - (b.second - a.second), mb = (b.first - a.first);
  return MT(ma, mb, - (ma * c.first + mb * c.second));
}

pdd IntersectionPoint(tiii l1, tiii l2){
  int a1, b1, c1, a2, b2, c2;
  tie(a1, b1, c1) = l1;
  tie(a2, b2, c2) = l2;

  double p = b1 * c2 - b2 * c1, q = a1 * c2 - a2 * c1, r = a1 * b2 - a2 * b1;

  if(p != 0){
    p /= r;
  }

  if(q != 0){
    q /= (-r);
  }

  return MP(p, q);
}

bool CheckPointInsideTriangle(pii a, pii b, pii c, pii d){
  int A = TwiceAreaTriangle(a, b, c), A1 = TwiceAreaTriangle(a, b, d), A2 = TwiceAreaTriangle(a, c, d), A3 = TwiceAreaTriangle(b, c, d);
  return (A == A1 + A2 + A3);
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    vector< pdd > ans;
    for(int i = 0; i < 4; ++i){
      scanf("%d%d", &p[i].first, &p[i].second);
    }

    for(int i = 0; i < 4 && ans.size() == 0; ++i){
      vector< pii > q;
      for(int j = 0; j < 4; ++j){
        if(i != j){
          q.PB(p[j]);
        }
      }

      if(TwiceAreaTriangle(q[0], q[1], q[2]) == 0){
        sort(q.begin(), q.end());
        for(int j = 0; j < q.size(); ++j){
          if(j != 1){
            ans.PB(MP(1.0 * q[j].first, 1.0 * q[j].second));
          }
        }
        ans.PB(MP(1.0 * p[i].first, 1.0 * p[i].second));
      }
    }

    if(ans.size() == 0){
      if(CheckPointInsideTriangle(p[0], p[1], p[2], p[3]) || CheckPointInsideTriangle(p[0], p[1], p[3], p[2]) || CheckPointInsideTriangle(p[0], p[2], p[3], p[1]) || CheckPointInsideTriangle(p[1], p[2], p[3], p[0])){
        printf("NO\n");
        continue;
      }
      else{
        tiii l1 = GetLine(p[0], p[1], p[0]), l2 = GetLine(p[0], p[3], p[0]), l3 = GetLine(p[1], p[3], p[2]);
        ans.PB(IntersectionPoint(l1, l2));
        ans.PB(IntersectionPoint(l2, l3));
        ans.PB(IntersectionPoint(l1, l3));
      }
    }

    printf("YES ");
    for(auto p : ans){
      printf("%.9lf %.9lf ", p.first, p.second);
    }
    printf("\n");
  }

  return 0;
}
