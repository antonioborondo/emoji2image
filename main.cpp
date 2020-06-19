#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>

#include "emoji.h"

int main()
{
    auto text = emojicpp::emojize(":heavy_check_mark:");

    cv::Size canvas_size{640, 480};
    cv::Scalar canvas_color{255, 255, 255};
    cv::Mat image{canvas_size, CV_8UC3, canvas_color};

    auto free_type = cv::freetype::createFreeType2();
    free_type->loadFontData(R"(C:\Windows\Fonts\seguiemj.ttf)", 0);

    cv::Point text_position{10, 10};
    int font_height{100};
    cv::Scalar font_color{22, 198, 12};
    int thickness{-1};
    free_type->putText(image, text, text_position, font_height, font_color, thickness, cv::LINE_AA, false);

    cv::imwrite("image.jpg", image);

    return 0;
}
