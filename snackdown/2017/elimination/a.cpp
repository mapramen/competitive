#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple

vector< tiiii > Method1(vector<int> p){
  int n = p.size();
  vector<int> s(n, 1);
  vector< tiiii > ans;

  for(int k = n - 1; k > 0; --k){
    int i = p[k];
    s[i] += s[k];
    int n = s[i], m = s[k];
    for(int x = n; x > 1; --x){
      for(int y = min(x - 1, m); y > 0; --y){
        ans.PB(MT(i, k, x - y, y));
      }
    }
  }

  sort(ans.begin(), ans.end());

  return ans;
}

vector< tiiii > Method2(vector<int> p){
  int n = p.size();
  vector<int> s(n, 1);
  vector< tiiii > ans;

  for(int k = n - 1; k > 0; --k){
    int i = p[k];
    for(int x = 1; x <= s[i]; ++x){
      for(int y = 1; y <= s[k]; ++y){
        ans.PB(MT(i, k, x, y));
      }
    }
    s[i] += s[k];
  }

  sort(ans.begin(), ans.end());

  return ans;
}

void Print(vector< tiiii > v){
  printf("%lu\n", v.size());
  for(auto t : v){
    int i, k, x, y;
    tie(i, k, x, y) = t;
    printf("(%d, %d, %d, %d)\n", i + 1, k + 1, x, y);
  }
  printf("\n");
}

void StressTest(){
  srand(1);
  while(true){
    int n = rand() % 10 + 1;
    vector<int> p(1);
    for(int i = 1; i < n; ++i){
      p.PB(rand() % i);
    }

    auto ans1 = Method1(p);
    auto ans2 = Method2(p);

    bool found = 0;

    for(int i = 0; i < ans1.size() && i < ans2.size() && found == 0; ++i){
      if(ans1[i] != ans2[i]){
        found = 1;
      }
    }

    if(found){
      cout << n << '\n';
      for(int i = 1; i < n; ++i){
        cout << p[i] + 1 << ' ';
      }
      cout << '\n';
      Print(ans1);
      Print(ans2);
      break;
    }
  }
}

int main(){
  StressTest();
  return 0;
}
