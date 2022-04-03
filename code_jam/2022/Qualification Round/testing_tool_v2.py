# "Twisty Little Passages" local testing tool.
#
# Usage: `python3 local_testing_tool.py`

import sys
import random

NUM_CASES = 100
N = 100000
K = 8000
NEED_CORRECT = 90

class Error(Exception):
  pass

class WrongAnswer(Exception):
  pass

WRONG_NUM_TOKENS_ERROR = ("Wrong number of tokens: expected {}, found {}.".format)
NOT_INTEGER_ERROR = "Not an integer: {}.".format
INVALID_LINE_ERROR = "Couldn't read a valid line."
ADDITIONAL_INPUT_ERROR = "Additional input after all cases finish: {}.".format
OUT_OF_BOUNDS_ERROR = "Request out of bounds: {}.".format
TOO_FEW_CORRECT_ERROR = "Too few correct answers: {}.".format
INVALID_COMMAND_ERROR = "couldn't understand player command: {}.".format
DID_NOT_GIVE_AN_ESTIMATE_ERROR = "Player did not give an estimate after K rounds."


def ReadValues(line):
  t = line.split()
  return t

def ConvertToInt(token, min, max):
    try:
      v = int(token)
    except:
      raise Error(NOT_INTEGER_ERROR(token[:100]))
    if v < min or v > max:
      raise Error(OUT_OF_BOUNDS_ERROR(v))
    return v

def ConvertToAnyInt(token):
    try:
      v = int(token)
    except:
      raise Error(NOT_INTEGER_ERROR(token[:100]))
    return v

def Input():
  try:
    return input()
  except EOFError:
    raise
  except:
    raise Error(INVALID_LINE_ERROR)

def Output(line):
  try:
    print(line)
    sys.stdout.flush()
  except:
    try:
      sys.stdout.close()
    except:
      pass

def RunCases():
  Output("{}".format(NUM_CASES))
  correct = 0
  for case_number in range(NUM_CASES):
    # N = (case_number + 1) * 1000
    Output("{} {}".format(N, K))

    # Construct a graph in adj.
    dense_vertex_count = 20
    is_dense_vertex = [False for _ in range(N - dense_vertex_count)] + [True for _ in range(dense_vertex_count)]
    random.shuffle(is_dense_vertex)
    
    adj_set = [set() for _ in range(N)]
    adj = [[] for _ in range(N)]

    maximum_sparse_degree = 3
    minimum_dense_degree = N // 2
    
    for i in range(N):
      degree = random.randint(minimum_dense_degree, N - 1) if is_dense_vertex[i] else random.randint(1, maximum_sparse_degree)
      # print(f"i = {i} degree = {degree} len = {len(adj[i])}")
      if is_dense_vertex[i]:
        order = [x for x in range(N)]
        random.shuffle(order)
        while len(adj[i]) < degree:
          j = order.pop()
          if j == i or j in adj_set[i]:
            continue
          adj_set[i].add(j), adj_set[j].add(i)
          adj[i].append(j), adj[j].append(i)
      else:
        while len(adj[i]) < degree:
          j = random.randint(0, N - 1)
          if j == i or j in adj_set[i]:
            continue
          adj_set[i].add(j), adj_set[j].add(i)
          adj[i].append(j), adj[j].append(i)
      # if i % 1000 == 0:
      #   print(f"Satisfied {i}")

    correct_total_edges = sum([len(x) for x in adj]) // 2

    # Play the game.
    where = random.randint(0,N-1)
    for move_number in range(K+1):
      # Output current room number (1-based) and number of adjacent passages.
      Output("{} {}".format(where+1, len(adj[where])))

      # Get the user's move.
      try:
        move = ReadValues(Input())
      except EOFError:
        raise Error(INVALID_LINE_ERROR)
      except Error as error:
          raise error
      if len(move) == 0:
        raise Error(INVALID_LINE_ERROR)

      if move[0] == "E":
        # The user provided an estimate.
        if len(move) != 2:
          raise Error(WRONG_NUM_TOKENS_ERROR(2,len(move)))
        estimate = ConvertToAnyInt(move[1])
        lo = (correct_total_edges * 2 + 2) // 3
        hi = (correct_total_edges * 4) // 3
        ratio = estimate / correct_total_edges
        if lo <= estimate and estimate <= hi:
          print(f"Case #{case_number}: N = {N} Correct -- ratio = {ratio}; got {estimate}; exact answer is {correct_total_edges}.", file=sys.stderr)
          correct += 1
        else:
          print(f"Case #{case_number}: N = {N} Wrong -- ratio = {ratio}; got {estimate}; exact answer is {correct_total_edges}; acceptable range is [{lo}, {hi}].", file=sys.stderr)
        # Go to the next test case.
        break
      elif move_number == K:
        # The cave is now closed!
        raise Error(DID_NOT_GIVE_AN_ESTIMATE_ERROR)
      elif move[0] == "W":
        # The user took a random exit.
        if len(move) != 1:
          raise Error(WRONG_NUM_TOKENS_ERROR(1,len(move)))
        i = random.randint(0, len(adj[where]) - 1)
        where = adj[where][i]
      elif move[0] == "T":
        # The user teleported to a room.
        if len(move) != 2:
          raise Error(WRONG_NUM_TOKENS_ERROR(1,len(move)))
        where = ConvertToInt(move[1], 1, N)
        where -= 1
      else:
        raise Error(INVALID_COMMAND_ERROR(move[0][:1000]))

  # Check there is no extraneous input from the user.
  try:
    extra_input = Input()
    raise Error(ADDITIONAL_INPUT_ERROR(extra_input[:100]))
  except EOFError:
    pass

  # Finished.
  print(f"User got {correct} cases correct.", file=sys.stderr)
  if correct < NEED_CORRECT:
    raise WrongAnswer(TOO_FEW_CORRECT_ERROR(correct))

def main():
  if len(sys.argv) == 2 and int(sys.argv[1]) < 0:
    sys.exit(0)
  random.seed(12345)
  try:
    RunCases()
  except Error as error:
    print(error, file=sys.stderr)
    sys.exit(1)
  except WrongAnswer as error:
    print(error, file=sys.stderr)
    sys.exit(1)

if __name__ == "__main__":
  main()
