#include <jsoncpp/json/json.h>
#include <cstring>
#include <iostream>
#include <locale>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const vector<string> moves{"FORWARD", "BACK", "TURN LEFT", "TURN RIGHT"};

vector<int> calculateTarget(vector<string>& instructions) {
  int x = 0, y = 0;
  int dx = 1, dy = 0;

  for (string instruction : instructions) {
    if (instruction == "FORWARD") {
      x += dx;
      y += dy;
    } else if (instruction == "BACK") {
      x -= dx;
      y -= dy;
    } else if (instruction == "TURN LEFT") {
      int tmp = dx;
      dx = -dy;
      dy = tmp;
    } else if (instruction == "TURN RIGHT") {
      int tmp = dx;
      dx = dy;
      dy = -tmp;
    }
  }

  return {x, y};
}

/**
 * @param instructions The list of instructions as memorized by the mutant.
 * @param target The coordinates (x, y) of the target.
 * @return A string respecting the given format to fix the mutant's path.
 */
string findCorrectPath(vector<string> instructions, vector<int> target) {
  // Write your code here

  for (int i = 0; i < instructions.size(); ++i) {
    string original_instruction = instructions[i];
    for (string new_instruction : moves) {
      instructions[i] = new_instruction;
      if (calculateTarget(instructions) == target) {
        return "Replace instruction " + to_string(i + 1) + " with " + new_instruction;
      }
    }
    instructions[i] = original_instruction;
  }

  return "UNEXPECTED";
}

/* Ignore and do not change the code below */

void trySolution(string recipe) {
  Json::Value output_json;
  output_json = Json::Value(recipe);

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
  vector<string> instructions = array;
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  vector<int> array_2;
  for (int i = 0; i < parsed_json.size(); i++) {
    array_2.push_back(parsed_json[i].asInt());
  }
  vector<int> target = array_2;

  string output = findCorrectPath(instructions, target);
  trySolution(output);
}
/* Ignore and do not change the code above */
