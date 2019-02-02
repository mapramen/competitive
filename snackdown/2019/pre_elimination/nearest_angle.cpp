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

int main(){
  int t;
  cin >> t;

  while(t--){
    int n;
    tiii ans = MT(0, 0, 0);

    cin >> n >> P >> Q;

    for(int i = 1; i <= n; ++i){
      cin >> a[i];
    }

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

    int i, j, k;
    tie(i, j, k) = ans;

    if(k == 0){
      cout << "-1\n";
    }
    else{
      cout << k << ' ' << i << ' ' << j << '\n';
    }
  }

  return 0;
}
