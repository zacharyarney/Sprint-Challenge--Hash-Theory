# Hash Tables Sprint Challenge

For the hash tables portion of the sprint challenge, you'll be working through some algorithm problems that can be solved much more efficiently using a hash table. You know the drill at this point. Navigate into each exercise's directory, read the instructions for the exercise laid out in the README, implement your solution in the skeleton file, then make sure your code passes the tests by running the test script.

## Note

Python is a lot pickier than JS when it comes to checking whether a hash table contains a key. In JS, we can check if a hash table contains a key like so:
```js
const value = hash[key];
if (!value) {
  // handle the case where `value` is undefined
}
```
However, Python doesn't like this. The way to check a hash table for key membership in Python is to use a `try-except` block like so:
```python
try:
  value = hash[key]
except KeyError:
  # handle the case where `value` is undefined
```