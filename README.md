# CSE-5311-Hands-On11


## CH 17 HW

### (a) Aggregate Method

1. **Simple Insertions**:
   - Normally, each insertion just adds the item to the end of the array, which takes a very small, fixed amount of time (let's call this 1 unit of time).

2. **Doubling the Array**:
   - But sometimes, the array is full, so we need to double its size.
   - Doubling means creating a new array that's twice as big and copying everything over. This can take a lot of time, depending on how many items are in the array. For example, if there are 8 items, copying them all would take 8 units of time.

3. **Total Cost Calculation**:
   - When we look at all the insertions together, we realize that we don’t double the array every time—only occasionally, as it grows.
   - If you insert \( n \) items, even though doubling occasionally takes more time, it only happens about \(\log n\) times.
   - When we add up all the time spent on insertions (including copying), it turns out to be about \( O(n) \) for \( n \) items.

4. **Average (Amortized) Cost**:
   - So if the total cost for \( n \) insertions is \( O(n) \), the average cost per insertion is \( \frac{O(n)}{n} = O(1) \).
   - **In simple terms:** Each insertion, on average, costs a fixed amount of time, or \( O(1) \).

---

### (b) Accounting Method

1. **Adding Extra “Tokens”**:
   - For each insertion, let’s pretend we’re paying 3 "tokens" of time, even though most insertions only take 1 token of time.
   - The extra 2 tokens go into "savings" for future operations.

2. **Using Savings for Doubling**:
   - When the array doubles, we need to copy everything over, which costs time.
   - But, because we've been saving 2 tokens from every insertion, we have enough saved up to cover the cost of copying whenever we need to double the array.

3. **Amortized Cost**:
   - Since each insertion pays 3 tokens, and we’ve saved enough to handle the expensive operations (doubling), we can say that **each insertion effectively costs an average of 3 tokens, or \( O(1) \)**.

---
