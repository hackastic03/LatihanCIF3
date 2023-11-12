#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#include <chrono>
#include <vector>

using namespace std;

typedef struct {
    double h;
    double s;
    double v;
} HSV;

double max(double a, double b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

double min(double a, double b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}


vector <vector <HSV>> convertImagetoHSV(const string& filename) {
    int width, height, channel;
    const char* c = filename.c_str();
    unsigned char* img = stbi_load(c, &width, &height, &channel, 3);
    stbi_write_png("tes1.png", width, height, channel, img, width * channel);
    vector <double> imgVector(img, img + width * height * channel);
    vector <vector <HSV>> hsv(height, vector <HSV>(width));
    int i, j, k = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            double r = static_cast<double>(imgVector[k]) / 255;
            double g = static_cast<double>(imgVector[k + 1]) / 255;
            double b = static_cast<double>(imgVector[k + 2]) / 255;
            double cmax = max(r, max(g, b));
            double cmin = min(r, min(g, b));
            double delta = cmax - cmin;
            double h;
            if (delta == 0) {
                h = 0;
            }
            else if (cmax == r) {
                double temp = ((g - b) / delta);
                int temp2 = (int)temp;
                h = 60 * ((temp2 % 6) + (temp - (double)temp2));
            }
            else if (cmax == g) {
                h = 60 * (((b - r) / delta) + 2);
            }
            else {
                h = 60 * (((r - g) / delta) + 4);
            }

            double s, v;
            if (cmax == 0) {
                s = 0;
            }
            else {
                s = (delta / cmax);
            }

            v = cmax;

            hsv[i][j].h = h;
            hsv[i][j].s = s;
            hsv[i][j].v = v;
            k += 3;
        }
    }
    free(img);
    return hsv;

}


void displayMatrix(vector <vector <HSV>> mat) {
    int i, j, k;
    for (i = 0; i < mat.size(); i++) {
        for (j = 0; j < mat[0].size(); j++) {
            cout << "[";
            cout << mat[i][j].h << ", ";
            cout << mat[i][j].s << ", ";
            cout << mat[i][j].v << "";

            cout << "], ";
        }
        cout << endl;
    }
}


double cos(vector <int> &A, vector <int> &B) {
    int i;
    long long int sum = 0;
    double lenA = 0.0, lenB = 0.0;
    for (i = 0; i < A.size(); i++) {
        cout << A[i] << " " << B[i] << " | ";
        sum += A[i] * B[i];
        cout << sum << endl;
        lenA += A[i] * A[i];
        lenB += B[i] * B[i];
    }
    if (lenA == 0 || lenB == 0) {
        return 0;
    }
    else {
        return sum / (sqrt(lenA) * sqrt(lenB));
    }
}


double cosBlockGlobal(vector <vector <HSV>> &mat, vector <vector <HSV>> &mat2, int bins) {
    vector <int> histogram(bins * 3, 0);
    vector <int> histogram2(bins * 3, 0);
    int i, j;
    double total = 0;
    for (i = 0; i < mat.size(); i++) {
        for (j = 0; j < mat[0].size(); j++) {
            int binH1 = (int)(mat[i][j].h / (360 / bins));
            int binS1 = (int)(mat[i][j].s * 100 / (100 / bins));
            int binV1 = (int)(mat[i][j].v * 100 / (100 / bins));
            histogram[binH1]++;
            histogram[binS1 + bins]++;
            histogram[binV1 + bins * 2]++;

            int binH2 = (int)(mat2[i][j].h / (360 / bins));
            int binS2 = (int)(mat2[i][j].s * 100 / (100 / bins));
            int binV2 = (int)(mat2[i][j].v * 100 / (100 / bins));
            histogram2[binH2]++;
            histogram2[binS2 + bins]++;
            histogram2[binV2 + bins * 2]++;

        }
    }
    cout << "Histogram 1: " << endl;

    return (cos(histogram, histogram2));
}


int main() {
    string path, path2;
    cout << "Masukkan path:";
    cin >> path;
    path = "D:/Python/tubes2_algeo/src/client/src/app/api/archive/dataset/" + path;
    cout << "Masukkan path2:";
    cin >> path2;
    path2 = "D:/Python/tubes2_algeo/src/client/src/app/api/archive/dataset/" + path2;
    auto start = chrono::high_resolution_clock::now();
    auto *mat1 = new vector <vector <HSV>>;
    *mat1 = convertImagetoHSV(path.c_str());
    auto *mat2 = new vector <vector <HSV>>;
    *mat2 = convertImagetoHSV(path2.c_str());
    cout << "Persentase kemiripan: " << cosBlockGlobal(*mat1, *mat2, 10) * 100 << endl;
    auto stop = chrono::high_resolution_clock::now();
    cout << "Waktu eksekusi: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " ms" << endl;
    return 0;




}