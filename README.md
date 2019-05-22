# fillit
Fillit is a tetris-like solver algorithm in C that takes up to 26 tetris shapes as inputs and finds the smallest square possible in which they can fit, and displays it.

The disposition must be as such that it returns the first possible solution when placing them recursively from the top left.

# Compiling
Run make, an executable called fillit should compile directly. Please submit an issue if you run into any.

# Usage
./fillit [file]

# Example:

<~ ./fillit samples/test_8

.AABB..\n
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.>

Look at fillit.en.pdf for more information about the project.
