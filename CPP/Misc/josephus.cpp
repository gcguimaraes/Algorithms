/*
j(n, k) returns the 1-indexed survivor out of n people and step k.
Notice that the first dude to die is 'k'. Then, we recursively call
josephus to solve for the n-1 dudes remaining (starting from k+1),
add k to that indexing (so it becomes the indexing of the original circle),
subtract one to make it 0-indexed, apply mod and add one (for 1-indexing).
*/

int josephus(int n, int k) {
    if (n == 1) return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
