#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

char s[100];

string ReadString() {
  scanf("%s", s);
  return string(s);
}

string GetFinalMROCode(map<string, string>& old_to_new_mro_code_map, string mro_code) {
  auto it = old_to_new_mro_code_map.find(mro_code);
  if (it == old_to_new_mro_code_map.end()) {
    return mro_code;
  }

  string final_mro_code = GetFinalMROCode(old_to_new_mro_code_map, it->second);
  it->second = final_mro_code;
  return final_mro_code;
}

void Solve() {
  int n;
  scanf("%d", &n);

  map<string, string> recruit_to_mro_code_map;
  while (n--) {
    string recuit = ReadString();
    string mro_code = ReadString();
    recruit_to_mro_code_map[recuit] = mro_code;
  }

  int m;
  scanf("%d", &m);

  map<string, string> old_to_new_mro_code_map;
  while (m--) {
    string old_code = ReadString();
    string new_code = ReadString();
    old_to_new_mro_code_map[old_code] = new_code;
  }

  int q;
  scanf("%d", &q);

  while (q--) {
    string recuit = ReadString();
    printf("%s %s\n", recuit.c_str(), GetFinalMROCode(old_to_new_mro_code_map, recruit_to_mro_code_map[recuit]).c_str());
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}