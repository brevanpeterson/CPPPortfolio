#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

std::vector<double> rgb_hsv(double R, double G,double B);

int main()
{
    rgb_hsv(129, 88, 47);
    return 0;
}

std::vector<double> rgb_hsv(double R, double G, double B) {
    std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;

    // Reducing the range of RGB from 0-255 to 0-1
    R = R / 255;
    G = G / 255;
    B = B / 255;

    // Calculating Max and Min values
    double cmax = std::max(R, std::max(G, B));
    double cmin = std::min(R, std::min(G, B));
    double diff = cmax - cmin;
    double H = -1;
    double S = -1;

    // Calculating Hue
    if (cmax == cmin)
        H = 0;
    else if (cmax == R)
        H = fmod((60 * ((G - B) / diff) + 360), 360);
    else if (cmax == G)
        H = fmod((60 * ((B - R) / diff) + 120), 360);
    else if (cmax == B)
        H = fmod((60 * ((R - G) / diff) + 240), 360);

    // Calculating Saturation
    if (cmax == 0)
        S = 0;
    else
        S = (diff / cmax) * 100;

    // Calculating Value
    double V = cmax * 100;

    std::cout << "H: " << static_cast<int>(H) << " S: " << static_cast<int>(S) << " V: " << static_cast<int>(V) << std::endl;
    std::vector<double> hsv{ H,S,V };

    return hsv;
}
