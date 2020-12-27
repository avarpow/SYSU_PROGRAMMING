template <class Record>
void Sortable list<Record>::insert heap(const Record &current, int low, int high)
/* Pre: The entries of the Sortable list between indices low + 1 and high,
inclusive, form a heap. The entry in position low will be discarded.
Post: The entry current has been inserted into the Sortable list and the
entries rearranged so that the entries between indices low and high,
inclusive, form a heap.
Uses: The class Record, and the contiguous List implementation of Chapter 6.
*/
{
    int large;           // position of child of entry[low] with the larger key
    large = 2 * low + 1; // large is now the left child of low.
    while (large <= high)
    {
        if (large < high && entry[large] < entry[large + 1])
            large++; // large is now the child of low with the largest key.
        if (current >= entry[large])
            break; // current belongs in position low.
        else
        { // Promote entry[large] and move down the tree.
            entry[low] = entry[large];
            low = large;
            large = 2 * low + 1;
        }
    }
    entry[low] = current;
}
