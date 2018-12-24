/*
 * created by Danil Kireev, PFUR NFI-201, 4.12.18, 09:00
 */
#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

/*
 *  №6
 *  Дан массив с числами integer.
 *  Вам нужно написать функцию, которая на входе получает исходны массив,
 *  а на выходе вернёт массив, в котором каждое значение получено путём произведения всех
 *  значений исходного массива  с отличным от текущего инлексом
 */

int main() {
    random_device rd;
    mt19937_64 gen(rd());
    
    std::uniform_int_distribution<> dis(-100, 100);
    
    int  n, *a, choice, res, tmp_int;
    cout << "Программа " << endl;
    cout << "введите размер массива: ";
    cin >> n;
    while(n <= 2) {
        cout << "введите размер списка не меньше 1: ";
        cin >> n;
    }
    a = new int[n];
    cout << "Выберите тип ввода:\n- *0:заполнение случайными числами*\n-  1:заполнение вручную" << endl;
    cin >> choice;
    switch(choice) {
        case 0: {
            for (int i = 0; i < n; ++i) {
                tmp_int = dis(gen);
                cout << "значение " << i+1 << "-го элемента: " << tmp_int << endl;
                a[i] = tmp_int;
            }
            break;
        }
        case 1: {
            for (int i = 0; i < n; ++i) {
                cout << "значение " << i+1 << "-го элемента: ";
                cin >> a[i];
            }
            break;
        }
        default:break;
    }
    cout << "полученый список: " << endl;
    for (int i = 0; i < n; ++i) cout << "значение " << i+1 << "-го элемента: " << a[i] << endl;
    
    //sort
    qsort (a, n, sizeof(int), [](const void* a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        
        if(arg1 < arg2) return -1;
        else if(arg1 > arg2) return 1;
        else return 0;
    });
    qsort (a, n, sizeof(int), [](const void* a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        arg1 = abs(arg1);
        arg2 = abs(arg2);
        
        if(arg1 < arg2) return -1;
        else if(arg1 > arg2) return 1;
        else return 0;
    });
    int am_of_neg=0, out, tmp;
    cout << "отсортированный массив: " << endl;
    for(int i = 0; i < n; ++i) cout << "значение " << i+1 << "-го элемента: " << a[i] << endl;
    res = a[n-1] * a[n-2] * a[n-3];
    if(res >= 0) out=res;
    else {
        if(a[n-1] < 0) {am_of_neg++;}
        if(a[n-2] < 0) {am_of_neg++;}
        if(a[n-3] < 0) {am_of_neg++;}
        switch(am_of_neg) {
            case 3: {
                for(int i = n-1; i >= 0; --i) {
                    if(a[i] > 0) {
                        tmp = i;
                        break;
                    }
                }
                out =  a[n-1]*a[n-2]*a[tmp];
            }
            case 1: {
                if(a[n-1] < 0) {
                    for(int i = n-1; i >= 0; --i) {
                        if(a[i] < 0) {
                            tmp = i;
                            break;
                        }
                    }
                    out =  a[n-1]*a[n-2]*a[tmp];
                }
                if(a[n-2] < 0) {
                    for(int i = n-1; i >= 0; --i) {
                        if(a[i] > 0) {
                            tmp = i;
                            break;
                        }
                    }
                    out =  a[n-1]*a[n-2]*a[tmp];
                }
                if(a[n-3] < 0) {
                    for(int i = n-1; i >= 0; --i) {
                        if(a[i] > 0) {
                            tmp = i;
                            break;
                        }
                    }
                    out =  a[n-1]*a[n-2]*a[tmp];
                }
                break;
            }
            default:break;
        }
    }
    cout << "результат: " <<out << endl;
    return 0;
}
