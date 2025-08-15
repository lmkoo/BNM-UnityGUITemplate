#pragma once

#include <vector>
#include "Style.hpp"

class Styles {
public:
    inline static std::vector<Style> allStyles = {
            Style{
                    .styleName = "default",
                    .titleColor = "white",
                    .pointerColor = "white",
                    .enabledColor = "lime",
                    .disabledColor = "white"
            },
            Style{
                    .styleName = "rainbow"
            },
            Style{
                    .styleName = "red",
                    .titleColor = "red",
                    .pointerColor = "white",
                    .enabledColor = "lime",
                    .disabledColor = "red"
            },
            Style{
                    .styleName = "blue",
                    .titleColor = "blue",
                    .pointerColor = "white",
                    .enabledColor = "green",
                    .disabledColor = "blue"
            },
            Style{//Can delete these styles if you want and make your own
                    .styleName = "lmko",
                    .titleColor = "magenta",
                    .pointerColor = "white",
                    .enabledColor = "blue",
                    .disabledColor = "magenta"
            },
            Style{
                    .styleName = "mre",
                    .titleColor = "black",
                    .pointerColor = "black",
                    .enabledColor = "black",
                    .disabledColor = "black"
            },
            Style{
                    .styleName = "jae",
                    .titleColor = "lime",
                    .pointerColor = "lime",
                    .enabledColor = "blue",
                    .disabledColor = "lime"
            }
    };
};
