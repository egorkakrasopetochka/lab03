#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <string>
using namespace std;
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(const vector<size_t>& bins);
double bin_opacity17(double bin, size_t max_count);
#endif // SVG_H_INCLUDED
