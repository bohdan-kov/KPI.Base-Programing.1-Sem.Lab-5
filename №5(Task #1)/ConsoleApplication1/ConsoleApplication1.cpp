#include <iostream>
#include <cmath>


using namespace std;


float y, y_stan, error, precision, x_start, x_fin, x_step;

//y - Сама функція для обрахунку за  формулою Тейлора
//y_stan - Звичайно підрахована функція 
//x_start - аргумент функції 
//error - похибка
//precision - точність



int fact(int n) {
    if (n <= 1) 
        return 1;
    return n * fact(n - 1);
}

float cal_taylor(float k, float p) {

    double sum = 1;
    double sum_old;
    int i = 1;

    do {
        sum_old = sum;
        sum += (pow(-1, i) * (pow(k, 2 * i) / fact(2 * i)));

        i++;

    } while(abs(sum - sum_old) > pow(10, p));

    cout << "Cout iterations: " << i << endl;
    return sum;
}

int main()
{

    cout << "Input precision " << endl << "(in quantity format 0 after the decimal point) (recom -3): ";
    cin >> precision;

    cout << "Input x [start] (recom -2): ";
    cin >> x_start;

    cout << "Input x [finish] (recom = 2): ";
    cin >> x_fin;

    cout << "Input x [step] (recom = 0.5): ";
    cin >> x_step;

    for (float x = x_start; x <= x_fin; x += x_step) {
        cout << endl << endl;
        cout << "X: " << x << endl;
        if (x > 0 && x <= 1) {

            y = pow(cal_taylor(x, precision), 2.0) - cal_taylor(x, precision);
            y_stan = pow(cos(x), 2) - cos(x);
            error = (abs(y - y_stan));

            cout << "Y (Taylor)   " << y << endl;
            cout << "Y (Standart) " << y_stan << endl;
            cout << "Error:" << error << " (%): " << error * 100 << "%" << endl << endl;
        }
        else if (x >= -2 && x <= 0) {

            y = cal_taylor(pow(x, 2), precision) + cal_taylor(x*2, precision);

            y_stan = cos(pow(x, 3)) + cos(2 * x);

            error = (abs(y - y_stan));

            cout << "Y (Taylor)   " << y << endl;
            cout << "Y (Standart) " << y_stan << endl;
            cout << "Error:" << error << " (%): " << error * 100 << "%" << endl << endl;
        }
        else {
            cout << "not define" << endl;
        }
    }
}
