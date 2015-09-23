# SquirrelJump

### Problem:
Find the highest number of jumps a squirrel can make in a bar graph. The bar graph is represented by a vector of integer values.

Rules:
- You choose on which bar the squirrel starts
- The squirrel may only jump to a lower bar height
- The squirrel can jump a maximum of two bars away

Example:
- Bars: [6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12]
- Solution: The longest jump sequence is five jumps long: From 12 to 10 to 9 to 8 to 6 to 4.

### Solution:
This solution uses a recursive function, that takes an index to a bar, which will call for itself as long as there is a possible jump to another bar. The function returns the maximal depth.
