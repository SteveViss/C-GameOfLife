import subprocess
import sys
import tkDisplay

subpName = sys.argv[1]
display = None
golProc = subprocess.Popen(subpName, stdout=subprocess.PIPE)

line = ""
grid = []
while True:
    line = golProc.stdout.readline()
    line = line.rstrip()
    if line == "NA":
        break
    elif line != '':
        grid.append(line)
    else:
        if display is None:
            display = tkDisplay.tkDisplay( (len(grid[0]), len(grid)), grid)
        else:
            display.update(grid)
        grid = []
raw_input("Press enter to exit")

