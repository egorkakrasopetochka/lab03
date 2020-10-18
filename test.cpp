#include "histogram.h"

#include <cassert>
void test_bin_opacity()
{
    double bin=5;
    size_t max_count=10;
    assert(bin_opacity17(bin,max_count)==0.5);
}
void test_bin_opacity2()
{
    double bin=0;
    size_t max_count=10;
    assert(bin_opacity17(bin,max_count)==0.0);
}
void test_bin_opacity3()
{
    double bin=0;
    size_t max_count=0;
    assert(bin_opacity17(bin,max_count)==0);
}
void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1,2,3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1,-2,-3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({1,1,1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_one_number()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

int
main()
{
    test_bin_opacity();
    test_bin_opacity2();
    test_bin_opacity3();
    test_positive();
    test_negative();
    test_equal();
    test_one_number();
    test_empty();
}
