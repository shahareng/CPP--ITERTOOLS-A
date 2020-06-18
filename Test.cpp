#include "doctest.h"
#include <iostream>
#include <vector>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"

using namespace itertools;
using namespace std;

// Id of collaborators 318590726 318511375

TEST_CASE("### demo: ###")
{       
        vector<int> ans = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        int index = 0;
        for (int i : range(1, 21))
                CHECK(i == ans[index++]);
        
        index = 0;
        for (int i : range(1, 21))
                CHECK(i == ans[index++]);
        
        index = 0;
        for (int i : range(1, 21))
                CHECK(i == ans[index++]);
        
        index = 0;
        for (int i : range(1, 21))
                CHECK(i == ans[index++]);
        
        index = 0;
        for (int i : range(1, 21))
                CHECK(i == ans[index++]);
}