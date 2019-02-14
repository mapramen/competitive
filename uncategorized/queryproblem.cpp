#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define L 8

int main(){
  int n, m;
  unordered_map< string, int > M;

  scanf("%d%d", &m, &n);

  while(n--){
    string s;
    cin >> s;

    M[s]++;

    for(int i = 0; i < L; i++){
      char c = s[i];
      s[i] = '#';
      M[s]++;
      s[i] = c;
    }

    for(int i = 0; i < L; i++){
      char c1 = s[i];
      s[i] = '#';
      for(int j = i + 1; j < L; j++){
        char c2 = s[j];
        s[j] = '#';
        M[s]++;
        s[j] = c2;
      }
      s[i] = c1;
    }
  }

  while(m--){
    string s;
    int d, ans, ansx = 0, ansy = 0, ansz = 0;
    cin >> s;
    scanf("%d", &d);

    if(M.find(s) != M.end()) ansx = M[s];

    if(d == 0)
      ans = ansx;
    else{
      for(int i = 0; i < L; i++){
        char c = s[i];
        s[i] = '#';
        if(M.find(s) != M.end()) ansy += M[s];
        s[i] = c;
      }

      if(d == 1)
        ans = ansy - 8 * ansx;
      else{
        for(int i = 0; i < L; i++){
          char c1 = s[i];
          s[i] = '#';
          for(int j = i + 1; j < L; j++){
            char c2 = s[j];
            s[j] = '#';
            if(M.find(s) != M.end()) ansz += M[s];
            s[j] = c2;
          }
          s[i] = c1;
        }

        ansy -= 8 * ansx;
        ans = ansz - 28 * ansx - 7 * ansy;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
