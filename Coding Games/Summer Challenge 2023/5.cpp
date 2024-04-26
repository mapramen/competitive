#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <cstring>
#include <iostream>
#include <locale>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& color, int i, bool c) {
  if (visited[i]) {
    return color[i] == c;
  }

  bool valid = true;
  visited[i] = true;
  color[i] = c;
  for (int j : adj[i]) {
    valid &= dfs(adj, visited, color, j, !c);
  }
  return valid;
}

/**
 * @param n_gears An integer representing the number of gears in the system (numbered from 0 to N-1).
 * @param connections An array representing all pairs of gears connected together.
 * @return An array of two integers representing the number of gears rotating clockwise and counterclockwise respectively, or [-1, -1] if the configuration is invalid.
 */
vector<int> gearBalance(int n_gears, vector<vector<int>> connections) {
  // Write your code here
  vector<vector<int>> adj(n_gears);
  for (auto& c : connections) {
    adj[c[0]].push_back(c[1]);
    adj[c[1]].push_back(c[0]);
  }

  vector<bool> visited(n_gears, false);
  vector<bool> color(n_gears, false);

  bool valid = true;
  for (int i = 0; i < n_gears; i++) {
    if (!visited[i]) {
      valid &= dfs(adj, visited, color, i, false);
    }
  }

  if (!valid) {
    return {-1, -1};
  }

  int clockwise = 0;
  int counterclockwise = 0;
  for (int i = 0; i < n_gears; i++) {
    if (!color[i]) {
      clockwise++;
    } else {
      counterclockwise++;
    }
  }

  return {clockwise, counterclockwise};
}

/* Ignore and do not change the code below */

void trySolution(vector<int> output) {
  Json::Value output_json;

  output_json = Json::Value(Json::arrayValue);
  Json::Value current_value;
  for (int i = 0; i < output.size(); i++) {
    current_value = Json::Value(output[i]);
    output_json.append(current_value);
  }

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
  int n_gears = parsed_json.asInt();
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  vector<vector<int>> array;
  for (int i = 0; i < parsed_json.size(); i++) {
    vector<int> array2;
    for (int j = 0; j < parsed_json[i].size(); j++) {
      array2.push_back(parsed_json[i][j].asInt());
    }
    array.push_back(array2);
  }
  vector<vector<int>> connections = array;

  vector<int> output = gearBalance(n_gears, connections);
  trySolution(output);
}
/* Ignore and do not change the code above */
