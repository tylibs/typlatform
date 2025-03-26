#ifndef BINARY_SEARCH_HPP_
#define BINARY_SEARCH_HPP_

#include "tiny/tiny-core-config.h"

#include <stdint.h>

namespace tiny {

class BinarySearch
{
public:
    /**
     * Performs binary search in a given sorted table array to find an entry matching a given key.
     *
     * @note This method requires the array to be sorted, otherwise its behavior is undefined.
     *
     * @tparam Key         The type of `Key` to search for.
     * @tparam Entry       The table `Entry` type.
     * @tparam kLength     The array length (number of entries in the array).
     *
     * The `Entry` class MUST provide the following method to compare the entry against a given key.
     *
     *    int Entry::Compare(const Key &aKey) const;
     *
     * The return value indicates the comparison result between @p aKey and the entry (similar to `strcmp()`), i.e.,
     * zero means perfect match, positive (> 0) indicates @p aKey is larger than entry, and negative indicates @p aKey
     * is smaller than entry.
     *
     * @note In the common use of this method as `Find(key, kTable)` where `kTable` is a fixed size array, the
     * template types/parameters do not need to be explicitly specified and can be inferred from the passed-in argument.
     *
     * @param[in] aKey    The key to search for within the table.
     * @param[in] aTable  A reference to an array of `kLength` entries of type `Entry`
     *
     * @returns A pointer to the entry in the table if a match is found, otherwise `nullptr` (no match in table).
     */
    template <typename Key, typename Entry, uint16_t kLength>
    static const Entry *Find(const Key &aKey, const Entry (&aTable)[kLength])
    {
        return static_cast<const Entry *>(
            Find(&aKey, &aTable[0], kLength, sizeof(aTable[0]), BinarySearch::Compare<Key, Entry>));
    }

    /**
     * Indicates whether a given table array is sorted based or not.
     *
     * Is `constexpr` and is intended for use in `static_assert`s to verify that a `constexpr` lookup table
     * array is sorted. It is not recommended for use in other situations.
     *
     * @tparam Entry       The table entry type.
     * @tparam kLength     The array length (number of entries in the array).
     *
     * The `Entry` class MUST provide the following `static` and `constexpr` method to compare two entries.
     *
     *    constexpr static bool Entry::AreInOrder(const Entry &aFirst, const Entry &aSecond);
     *
     * The return value MUST be TRUE if the entries are in order, i.e. `aFirst < aSecond` and FALSE otherwise.
     *
     * @param[in] aTable  A reference to an array of `kLength` entries on type `Entry`
     *
     * @retval TRUE   If the entries in @p aTable are sorted.
     * @retval FALSE  If the entries in @p aTable are not sorted.
     */
    template <typename Entry, uint16_t kLength> static constexpr bool IsSorted(const Entry (&aTable)[kLength])
    {
        return IsSorted(&aTable[0], kLength);
    }

private:
    typedef int (&Comparator)(const void *aKey, const void *aEntry);

    template <typename Entry> static constexpr bool IsSorted(const Entry *aTable, uint16_t aLength)
    {
        return (aLength <= 1) ? true : Entry::AreInOrder(aTable[0], aTable[1]) && IsSorted(aTable + 1, aLength - 1);
    }

    template <typename Key, typename Entry> static int Compare(const void *aKey, const void *aEntry)
    {
        return static_cast<const Entry *>(aEntry)->Compare(*static_cast<const Key *>(aKey));
    }

    static const void *Find(const void *aKey,
                            const void *aTable,
                            uint16_t    aLength,
                            uint16_t    aEntrySize,
                            Comparator  aComparator);
};

} // namespace tiny

#endif // BINARY_SEARCH_HPP_
