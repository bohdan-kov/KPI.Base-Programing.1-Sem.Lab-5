#include <iostream>
#include <cmath>


using namespace std;

float x, xc, point_a, point_b;

float func_x(float param) {
    return (tan(param) + 2);
}



float chord_method(float* a, float* b, int* precision) {
    cout << endl << "#2 Chord Algoritm";
    float point_c, val_x0, val_a, val_b;

    float point_a = *a;
    float point_b = *b;

    int i = 0;

    do {
        val_a = func_x(point_a);
        val_b = func_x(point_b);

        point_c = point_a - ((val_a * (point_b - point_a) / (val_b - val_a)));
        if (val_a * func_x(point_c) < 0)
            point_b = point_c;
        else
            point_a = point_c;

        i++;
    } while (abs(func_x(point_c)) > pow(10, *precision) && i < 100);
    cout << endl << "Found for " << i << " iterations";
    return point_c;
}

float sorting_algo(float* a, float* b, float* h) {
    cout << endl << "#1 Sorting Algoritm";
    x = *a;
    int i = 0;

    while (x <= *b) {
        float fx = func_x(x);
        float fxc = func_x(x + *h);

        if (fx * fxc <= 0) {
            cout << endl << "Found for " << i << " iterations" << endl;
            cout << endl << "x: " << x << " fx: " << fx << endl;
            cout << "x: " << x + *h << " fxc: " << fxc << endl;
            return x;
        }
        x += *h;
        i++;
    }
}


int main()
{
    float left, right, step;
    int precision;

    cout << "Input [a, b] (a - start, b - finish, c - step)" << endl;
    cout << "Start (Recommend 2): ";
    cin >> left;
    cout << "Finish: ";
    cin >> right;
    cout << "Step (Affects the accuracy of algorithm #1): ";
    cin >> step;
    cout << endl << "Precision (Format coutns zero after coma)" << endl << "Affects the accuracy of algorithm #2): ";
    cin >> precision;

    float* pl = &left;
    float* pr = &right;
    float* ps = &step;
    int* precis = &precision;


    sorting_algo(pl, pr, ps);

    cout << endl << "RESULT X: " << chord_method(pl, pr, precis) << endl;

}