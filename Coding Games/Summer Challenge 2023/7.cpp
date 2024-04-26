#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <cstring>
#include <iostream>
#include <locale>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @param wish_a The first wish.
 * @param wish_b The second wish.
 * @return The hybrid wish you created.
 */
string mixWishes(string wish_a, string wish_b) {
  // Write your code here
  int n = wish_a.size(), m = wish_b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i <= n; ++i) {
    dp[i][0] = i;
  }

  for (int j = 0; j <= m; ++j) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = wish_a[i - 1] == wish_b[j - 1]
                     ? dp[i - 1][j - 1]
                     : 1 + min(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  string ans;
  for (int i = n, j = m; i > 0 || j > 0;) {
    if (i == 0) {
      ans.push_back(wish_b[--j]);
      continue;
    }

    if (j == 0) {
      ans.push_back(wish_a[--i]);
      continue;
    }

    if (wish_a[i - 1] == wish_b[j - 1]) {
      ans.push_back(wish_a[--i]);
      --j;
      continue;
    }

    if (dp[i][j] == dp[i - 1][j] + 1) {
      ans.push_back(wish_a[--i]);
    } else {
      ans.push_back(wish_b[--j]);
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

/* Ignore and do not change the code below */

void trySolution(string mixed_ab) {
  Json::Value output_json;
  output_json = Json::Value(mixed_ab);

  Json::FastWriter fastWriter;
  std::string output_str = fastWriter.write(output_json);
  cout << "" << output_str.c_str();
}

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  Json::Reader reader;
  string line;
  Json::Value parsed_json;
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);
  string wish_a = parsed_json.asString();
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);
  string wish_b = parsed_json.asString();

  string output = mixWishes(wish_a, wish_b);
  trySolution(output);
}
/* Ignore and do not change the code above */
