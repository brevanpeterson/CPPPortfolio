#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

std::vector<double> rgb_hsv(double R, double G, double B);
std::vector<double> hsv_rgb(double H, double S, double V);

int main()
{
    std::vector<double> colors{};
    colors = rgb_hsv(129, 88, 47);
    hsv_rgb(colors[0], colors[1], colors[2]);

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

std::vector<double> hsv_rgb(double H, double S, double V) {
    std::cout << "H: " << H << " S: " << S << " V: " << V << std::endl;
    
    // Reducing Ranges
    S = S / 100;
    V = V / 100;
    
    // Calculating Values
    double C = V * S;
    double X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
    double M = V - C;

    double R = 0;
    double G = 0;
    double B = 0;

    if (H < 60) {
        R = C;
        G = X;
        B = 0;
    }
    else if (H >= 60 && H < 120) {
        R = X;
        G = C;
        B = 0;
    }
    else if (H >= 120 && H < 180) {
        R = 0;
        G = C;
        B = X;
    }
    else if (H >= 180 && H < 240) {
        R = 0;
        G = X;
        B = C;
    }
    else if (H >= 240 && H < 300) {
        R = X;
        G = 0;
        B = C;
    }
    else if (H >= 300 && H < 360) {
        R = C;
        G = 0;
        B = X;
    }

    R = (R + M) * 255;
    G = (G + M) * 255;
    B = (B + M) * 255;

    std::vector<double> hsv{ R,G,B };
    std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;
    return hsv;
}