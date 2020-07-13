#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

std::vector<float> rgb_hsi(float R, float G, float B);

int main()
{
    rgb_hsi(68, 138, 98);
    return 0;
}

std::vector<float> rgb_hsi(float R, float G, float B) {
    float H, S, I;
    std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;

    // Reducing the range of RGB from 0-255 to 0-1
    R = R / 255;
    G = G / 255;
    B = B / 255;

    // Calculating Intesity
    I = (B + G + R) / 3;

    // Calculating Saturation
    float min_val = 0;
    min_val = std::min(R, std::min(B, G));
    S = 1 - 3 * (min_val / (B + R + G));

    // Calculating Hue
    H = static_cast<float>(0.5) * ((R - G) + (R - B)) / sqrt(((R - G) * (R - G)) + ((R - B) * (G - B)));
    H = acos(H);
    if (B <= G) {
        H = H;
    }
    else {
        H = (static_cast<float>((360 * 3.14159265) / 180)) - H;
    }

    //Reformatting HSI and building Vector
    H = (H * static_cast<float>(180)) / static_cast<float>(3.14159265);
    S = S * 100;
    I = I * 100;
    std::cout << "H: " << static_cast<int>(H) << " S: " << static_cast<int>(S) << " I: " << static_cast<int>(I) << std::endl;
    std::vector<float> hsi{ H,S,I };

    return hsi;
}
