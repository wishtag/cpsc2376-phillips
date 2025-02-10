## Bugs and Fixes

### 1. sumRange()
**Bug:** The loop runs from `start` to `end - 1`, missing the last number.  
**Fix:** Changed loop condition to `i <= end` to include the final value.

### 2. containsNegative()
**Bug:** The loop checks `i <= numbers.size()`, causing an out-of-bounds read.  
**Fix:** Changed condition to `i < numbers.size()`.

**Bug:** The if statement checks `numbers[i] > 0`, causing positive numbers to incorrectly return `true`.  
**Fix:** Changed condition to `numbers[i] < 0`.

### 3. findMax()
**Bug:** Returns `0` for an empty vector, which wouldn't be true as the vector is empty.  
**Fix:** Throws `std::invalid_argument("Empty list")`.

**Bug:** The loop checks `i <= numbers.size()`, causing an out-of-bounds read.  
**Fix:** Changed condition to `i < numbers.size()`.

**Bug:** The if statement checks `numbers[i] >= maxVal`, causing values equal to `maxVal` to be set as the new value of `maxVal`. Realistically. this doesn't effect much but it is just unnecessary.  
**Fix:** Changed condition to `numbers[i] > maxVal`.