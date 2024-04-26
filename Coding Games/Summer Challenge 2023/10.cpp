#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <cstring>
#include <iostream>
#include <locale>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const ll inf = 1E18;

struct Edge {
  int from, to, index;
  ll cap, flow;
  Edge(int from, int to, ll cap, ll flow, int index)
      : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge>> G;
  vector<ll> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N)
      : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}

  void AddEdge(int from, int to, ll cap) {
    G[from].push_back(Edge(from, to, cap, 0ll, G[to].size()));
    if (from == to) {
      G[from].back().index++;
    }
    // for undirected
    G[to].push_back(Edge(to, from, cap, 0ll, G[from].size() - 1));

    // for directed
    // G[to].push_back(Edge(to, from, 0ll, 0ll, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) {
      active[v] = true;
      Q.push(v);
    }
  }

  void Push(Edge& e) {
    ll amt = min(excess[e.from], e.cap - e.flow);
    if (dist[e.from] <= dist[e.to] || amt == 0) {
      return;
    }
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; ++v) {
      if (dist[v] < k) {
        continue;
      }
      count[dist[v]]--;
      dist[v] = max(dist[v], N + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2 * N;
    for (int i = 0; i < G[v].size(); ++i) {
      if (G[v][i].cap - G[v][i].flow > 0) {
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
      }
    }
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); ++i) {
      Push(G[v][i]);
    }
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) {
        Gap(dist[v]);
      } else {
        Relabel(v);
      }
    }
  }

  ll GetMaxFlow(int s, int t) {
    count[0] = N - 1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); ++i) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    ll totflow = 0;
    for (int i = 0; i < G[s].size(); ++i) {
      totflow += G[s][i].flow;
    }
    return totflow;
  }
};

struct unknown {
  string mutant;
  int priority;
  string squad;
};

struct unknown2 {
  string friend1;
  string friend2;
  int strength;
};

void addScore(map<pair<int, int>, ll>& scores, int i, int j, ll score) {
  if (i > j) {
    swap(i, j);
  }
  scores[make_pair(i, j)] += score;
}

/**
 * @param n_mutants The number of graduating mutants
 * @param wishlist_y The priority of mutants selected by Y-Men
 * @param wishlist_z The priority of mutants selected by Z-Men
 * @param wishlist_mutants The priorities of squads for each mutant
 * @param friendships The list of friendships between mutants
 * @return The best possible score across all configurations
 */
int maxScore(int n_mutants, map<int, double> wishlist_y, map<int, double> wishlist_z, vector<struct unknown> wishlist_mutants, vector<struct unknown2> friendships) {
  // Write your code here

  map<pair<int, int>, ll> scores;
  int n = n_mutants;
  int s = 0;
  int t = 2 * n + 1;
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    addScore(scores, s, i, inf);
    addScore(scores, i, n + i, wishlist_y[i - 1]);
    addScore(scores, n + i, t, wishlist_z[i - 1]);
    ans += wishlist_y[i - 1] + wishlist_z[i - 1];
  }

  for (auto& mutant_wish : wishlist_mutants) {
    int mutant = stoi(mutant_wish.mutant) + 1;

    int i, j;
    if (mutant_wish.squad == "Y-Men") {
      i = mutant, j = n + mutant;
    } else {
      i = n + mutant, j = t;
    }

    addScore(scores, i, j, mutant_wish.priority);
    ans += mutant_wish.priority;
  }

  for (auto& friendship : friendships) {
    int i = stoi(friendship.friend1) + 1;
    int j = stoi(friendship.friend2) + 1;

    addScore(scores, i, j, friendship.strength);
    addScore(scores, n + j, n + i, friendship.strength);
    ans += friendship.strength;
  }

  PushRelabel pr(2 * n + 2);
  for (auto& score : scores) {
    pr.AddEdge(score.first.first, score.first.second, score.second);
  }

  ans -= pr.GetMaxFlow(s, t);

  return ans;
}

/* Ignore and do not change the code below */

unknown parseUnknown(Json::Value json_object) {
  Json::Value current_value;
  unknown result;

  result.mutant = json_object["mutant"].asString();
  result.squad = json_object["squad"].asString();
  result.priority = json_object["priority"].asInt();
  return result;
}

unknown2 parseUnknown2(Json::Value json_object) {
  Json::Value current_value;
  unknown2 result;

  result.friend1 = json_object["friend1"].asString();
  result.friend2 = json_object["friend2"].asString();
  result.strength = json_object["strength"].asInt();
  return result;
}

void trySolution(int max_possible_score) {
  Json::Value output_json;
  output_json = Json::Value(max_possible_score);

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
  int n_mutants = parsed_json.asInt();
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  map<int, double> dict;
  for (Json::Value::const_iterator itr = parsed_json.begin(); itr != parsed_json.end(); itr++) {
    dict.insert(std::pair<int, double>(atoi(itr.key().asString().c_str()), (*itr).asDouble()));
  }
  map<int, double> wishlist_y = dict;

  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  map<int, double> dict_2;
  for (Json::Value::const_iterator itr = parsed_json.begin(); itr != parsed_json.end(); itr++) {
    dict_2.insert(std::pair<int, double>(atoi(itr.key().asString().c_str()), (*itr).asDouble()));
  }
  map<int, double> wishlist_z = dict_2;

  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  vector<struct unknown> array;
  for (int i = 0; i < parsed_json.size(); i++) {
    array.push_back(parseUnknown(parsed_json[i]));
  }
  vector<struct unknown> wishlist_mutants = array;
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  vector<struct unknown2> array_2;
  for (int i = 0; i < parsed_json.size(); i++) {
    array_2.push_back(parseUnknown2(parsed_json[i]));
  }
  vector<struct unknown2> friendships = array_2;

  int output = maxScore(n_mutants, wishlist_y, wishlist_z, wishlist_mutants, friendships);
  trySolution(output);
}
/* Ignore and do not change the code above */
