/*
  USAGE:
  sort(v.begin(); v.end()); // needed for iterating over all the sets
  do {
    // process here the current combination.
    // this function EDITS the first k elements, so it will be the desired combination.
  } while (next_combination(v.begin(), v.begin() + k, v.end()));
*/
#include <bits/stdc++.h>
template <typename Iterator>
bool next_combination(const Iterator first, Iterator k, const Iterator last) {
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator i1 = first;
   Iterator i2 = last;
   ++i1;
   if (last == i1)
      return false;
   i1 = last;
   --i1;
   i1 = k;
   --i2;
   while (first != i1)
   {
      if (*--i1 < *i2)
      {
         Iterator j = k;
         while (!(*i1 < *j)) ++j;
         std::iter_swap(i1,j);
         ++i1;
         ++j;
         i2 = k;
         std::rotate(i1,j,last);
         while (last != j)
         {
            ++j;
            ++i2;
         }
         std::rotate(k,i2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}
