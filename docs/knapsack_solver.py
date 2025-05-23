from pulp import LpProblem, LpMaximize, LpVariable, lpSum, PULP_CBC_CMD
import sys
import time

start_time = time.time()

# Read input from file
with open(sys.argv[1], 'r') as f:
    lines = f.readlines()
    n = int(lines[0].strip())
    capacity = int(lines[1].strip())
    weights = list(map(int, lines[2].strip().split()))
    profits = list(map(int, lines[3].strip().split()))

# Setup LP problem
model = LpProblem("Knapsack", LpMaximize)
x = [LpVariable(f"x{i}", cat="Binary") for i in range(n)]

# Tiebreaker: maximize profit, then prefer fewer items
TIEBREAKER_WEIGHT = 1e-5
model += lpSum(x[i] * profits[i] for i in range(n)) - TIEBREAKER_WEIGHT * lpSum(x[i] for i in range(n)) - TIEBREAKER_WEIGHT * 1e-5 * lpSum(x[i] * i for i in range(n))

# Capacity constraint
model += lpSum(x[i] * weights[i] for i in range(n)) <= capacity

# Solve the problem
solver = PULP_CBC_CMD(msg=False, timeLimit=5)
model.solve()

# Collect selected item indices
selected = [str(i) for i in range(n) if x[i].varValue > 0.5]
total_profit = sum(profits[int(i)] for i in selected)
total_weight = sum(weights[int(i)] for i in selected)

end_time = time.time()
elapsed_time_ms = int((end_time - start_time) * 1000)  # milliseconds

# Write result to output file
with open(sys.argv[2], 'w') as f:
    f.write(f"{total_profit}\n")
    f.write(f"{total_weight}\n")
    f.write(" ".join(selected) + "\n")
    f.write(f"{elapsed_time_ms}\n")  # write time in ms