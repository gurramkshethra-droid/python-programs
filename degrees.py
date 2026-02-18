# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

ab = int(input().strip())
ac = int(input().strip())

angle = math.degrees(math.atan2(ab, ac))
print(f"{round(angle)}\u00B0")
