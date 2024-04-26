#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <cstring>
#include <iostream>
#include <locale>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> parseFile(string& file_content) {
  vector<string> lines;

  string line;
  for (char c : file_content) {
    if (c == '\n') {
      lines.push_back(line);
      line.clear();
      continue;
    }
    line.push_back(c);
  }

  lines.push_back(line);
  return lines;
}

map<string, string> parseLine(string& line) {
  map<string, string> data;

  string key;
  string value;
  bool is_key = true;
  for (char c : line) {
    if (c == '=') {
      is_key = false;
      continue;
    }
    if (c == ';') {
      data[key] = value;
      key.clear();
      value.clear();
      is_key = true;
      continue;
    }
    if (is_key) {
      key.push_back(c);
    } else {
      value.push_back(c);
    }
  }

  data[key] = value;
  return data;
}

void addData(map<string, string>& dest, map<string, string> src) {
  for (auto& [key, value] : src) {
    if (key.empty() || key == "Name") {
      continue;
    }
    dest[key] = value;
  }
}

void addData(map<string, map<string, string>>& data, map<string, string> new_data) {
  if (new_data.empty()) {
    return;
  }

  string name = new_data["Name"];

  if (data.count(name) == 0) {
    data[name] = {};
  }

  addData(data[name], new_data);
}

void addString(string& dest, string src) {
  for (char c : src) {
    dest.push_back(c);
  }
}

string toString(map<string, map<string, string>>& data) {
  string result;
  for (auto& [name, name_data] : data) {
    if (!result.empty()) {
      result.push_back('\n');
    }

    addString(result, "Name");
    result.push_back('=');
    addString(result, name);
    result.push_back(';');

    for (auto& [key, value] : name_data) {
      addString(result, key);
      result.push_back('=');
      addString(result, value);
      result.push_back(';');
    }
    result.pop_back();
  }
  return result;
}

/**
 * @param file_contents A list of strings, where each string represents the contents of a file.
 * @return The contents of the merged file.
 */
string mergeFiles(vector<string> file_contents) {
  // Write your code here
  map<string, map<string, string>> data;

  for (string& file_content : file_contents) {
    for (string line : parseFile(file_content)) {
      addData(data, parseLine(line));
    }
  }

  return toString(data);
}

/* Ignore and do not change the code below */

void trySolution(string merged_file) {
  Json::Value output_json;
  output_json = Json::Value(merged_file);

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

  vector<string> array;
  for (int i = 0; i < parsed_json.size(); i++) {
    array.push_back(parsed_json[i].asString());
  }
  vector<string> file_contents = array;

  string output = mergeFiles(file_contents);
  trySolution(output);
}
/* Ignore and do not change the code above */
