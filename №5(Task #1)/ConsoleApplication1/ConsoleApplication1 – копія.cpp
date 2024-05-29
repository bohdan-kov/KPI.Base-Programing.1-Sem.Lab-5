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
    if (n < 0) {
        return 0; // Факториал отрицательного числа равен 0
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
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


    return sum;
}

int main()
{


    for (float x = x_start; x <= x_fin; x += x_step) {

        if (x > 0 && x <= 1) {

            y = pow(cal_taylor(x, precision), 2.0) - cal_taylor(x, precision);
            y_stan = pow(cos(x), 2) - cos(x);
            error = (abs(y - y_stan));

        }
        else if (x >= -2 && x <= 0) {

            y = cal_taylor(pow(x, 2), precision) + cal_taylor(x*2, precision);

            y_stan = cos(pow(x, 3)) + cos(2 * x);

            error = (abs(y - y_stan));

        }
        else {
            cout << "not define" << endl;
        }
    }
}
