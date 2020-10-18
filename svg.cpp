#include "svg.h"
#include <iostream>
double bin_opacity17(double bin, size_t max_count)
{
    if(max_count==0)
        return 0;
    return bin/max_count;
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black", double fill_opacity=1.0)
{
    cout << "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' fill-opacity='"<<fill_opacity<<"' />";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<<baseline<<"'>"<<text<<"</text>";

}
void show_histogram_svg(const vector<size_t>& bins)
{
    const size_t screen_width=80;
    const size_t width=screen_width-4;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto GRAPH_WIDTH = IMAGE_WIDTH-TEXT_WIDTH;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    string stroke="black";
    string fill="red";
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }

    const bool scaling_needed = max_count > width;

    if (scaling_needed)
    {
        const double scaling_multiplier = (double)width / max_count;
        if(max_count*BLOCK_WIDTH/GRAPH_WIDTH>1)
        {
            for (size_t bin : bins)
            {
                const double new_scaling_multiplier=(double)GRAPH_WIDTH/(max_count*BLOCK_WIDTH*scaling_multiplier);
                const size_t new_bin_width = (size_t)BLOCK_WIDTH*bin*scaling_multiplier*new_scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                svg_rect(TEXT_WIDTH, top, new_bin_width, BIN_HEIGHT,stroke,fill,bin_opacity17(bin,max_count));
                top += BIN_HEIGHT;
            }
        }
        else
        {
            for (size_t bin : bins)
            {
                const double bin_width = BLOCK_WIDTH*bin*scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,stroke,fill,bin_opacity17(bin,max_count));
                top += BIN_HEIGHT;
            }
        }
    }

    else
    {
        if(max_count*BLOCK_WIDTH/GRAPH_WIDTH>1)
        {
            for (size_t bin : bins)
            {
                const double new_scaling_multiplier=(double)GRAPH_WIDTH/(max_count*BLOCK_WIDTH);
                const size_t new_bin_width = (size_t)BLOCK_WIDTH*bin*new_scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                svg_rect(TEXT_WIDTH, top, new_bin_width, BIN_HEIGHT,stroke,fill,bin_opacity17(bin,max_count));
                top += BIN_HEIGHT;
            }
        }
        else
        {
            for (size_t bin : bins)
            {
                const double bin_width = BLOCK_WIDTH * bin;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
                svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,stroke,fill,bin_opacity17(bin,max_count));
                top += BIN_HEIGHT;
            }
        }
    }
    svg_end();
}
