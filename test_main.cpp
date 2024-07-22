#include <gtest/gtest.h>
#include "sorting.h"
#include <set>
#include <vector>

TEST(test_sorting, test_store_descending) {
    std::set<int, std::greater<int>> data({1,2,3,4,5,6,7,8,9,10});    
    for(auto it = data.begin(); it != data.end(); it++){
        ASSERT_EQ(*it, 10 - std::distance(data.begin(), it));
    }
}

TEST(test_sorting, test_insertion_sort_range_based) {
    std::vector<int> data = {1,2,3,4,5,6,7,8,9,10};
    sorting::insertion_sort(data.begin(), data.end(), std::less());
    std::vector<int> expected = {10,9,8,7,6,5,4,3,2,1};
    ASSERT_EQ(data, expected);
}

TEST(test_sorting, test_insertion_sort) {
    std::vector<int> data = {1,2,3,4,5,6,7,8,9,10};
    sorting::insertion_sort(data.data(), data.size(), std::less());
    std::vector<int> expected = {10,9,8,7,6,5,4,3,2,1};
    ASSERT_EQ(data, expected);
}
