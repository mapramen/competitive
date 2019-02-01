#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 1001

ll a[N], P, Q;
set< pli > S;

void AddToSet(int i){
  S.insert(MP(Q * a[i] * a[i], i));
}

void RemoveFromSet(int i){
  S.erase(MP(Q * a[i] * a[i], i));
}

pii Cos(tiii t){
  int i, j, k;
  tie(i, j, k) = t;

  if(k == 0){
    return MP(2, 1);
  }

  int x = a[i], y = a[j], z = a[k];
  return MP(x * x + y * y - z * z, 2 * x * y);
}

tiii UpdateAns(tiii t1, tiii t2){
  pii a = Cos(t1), b = Cos(t2);
  if(1ll * b.second * a.first <= 1ll * a.second * b.first){
    return t1;
  }
  else{
    return t2;
  }
}

tiii Solve(int n){
  tiii ans = MT(0, 0, 0);

  AddToSet(0);

  for(int i = 1; i <= n; ++i){
    AddToSet(i);
  }

  for(int i = 1; i <= n; ++i){
    RemoveFromSet(i);
    for(int j = i + 1; j <= n; ++j){
      RemoveFromSet(j);

      ll x = Q * a[i] * a[i] + Q * a[j] * a[j] - 2 * P * a[i] * a[j] + 1;

      int k = (*prev(S.lower_bound(MP(x, 0)))).second;

      if(a[k] > abs(a[i] - a[j])){
        ans = UpdateAns(ans, MT(i, j, k));
      }

      AddToSet(j);
    }
    AddToSet(i);
  }

  S.clear();

  return ans;
}

tiii Brute(int n){
  tiii ans = MT(0, 0, 0);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      for(int k = 1; k <= n; ++k){
        int s = a[i] + a[j] + a[k], m = max(a[i], max(a[j], a[k]));
        if(i == j || j == k || i == k || s <= 2 * m){
          continue;
        }
        tiii t = MT(i, j, k);
        pii p = Cos(t);
        if(1ll * p.first * Q <= 1ll * P * p.second){
          continue;
        }
        ans = UpdateAns(ans, t);
      }
    }
  }

  return ans;
}

void PrintAns(string s, tiii ans){
  cout << s << ":\n";
  int i, j, k;
  tie(i, j, k) = ans;
  cout << i << ' ' << j << ' ' << k << '\n';
  pii p = Cos(ans);
  printf("%d %d %.9lf\n", p.first, p.second, 1.0 * p.first / p.second);
}

void StressTest(){
  srand(0);
  while(true){
    int n = rand() % 100 + 1;
    for(int i = 1; i <= n; ++i){
      a[i] = 1 + rand() % 100;
    }
    Q = 1 + rand() % 10000, P = rand() % (2 * Q - 1) - (Q - 1);
    tiii ans1 = Brute(n), ans2 = Solve(n);
    if(ans2 != UpdateAns(ans2, ans1)){
      printf("%d %lld %lld\n", n, P, Q);
      for(int i = 1; i <= n; ++i){
        printf("%lld ", a[i]);
      }
      printf("\n");
      printf("Target Cos >= %.9lf\n", 1.0 * P / Q);
      PrintAns("Brute", ans1);
      PrintAns("Solve", ans2);
      break;
    }
  }
}

int main(){
  StressTest();
  return 0;
}
