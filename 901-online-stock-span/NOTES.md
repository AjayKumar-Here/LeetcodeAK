***You can refer to the same problem 739. Daily Temperatures.
​
Push every pair of <price, result> to a stack.
Pop lower price from the stack and accumulate the count.
​
One price will be pushed once and popped once.
So 2 * N times stack operations and N times calls.
I'll say time complexity is amortized O(1)