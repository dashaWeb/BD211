#include <iostream>
using namespace std;
//Створіть структуру, що описує простий дріб.Реалізуйте арифметичні операції з дробами : суму, різницю,
//множення, ділення.
//Врахувати можливість скорочення дробів і перетво -
//рення з неправильного дробу на простий.
struct  Fract
{
    int num, denum;
    int inter = 0;
};

void print(Fract obj)
{
    if (obj.inter != 0)
        cout << "(" << obj.inter << ") ";
    if (obj.num == 0) return;
    cout << obj.num << "/" << obj.denum;
}

// 1/3 + 2/5 
// 1 * 5 / 3 * 5 +2 * 3 / 5 * 3
// 5/15 + 6/15
// 11/15
// 45/15
Fract sum(Fract one, Fract two) {
    Fract tmp;// {(one.num * two.denum) + (two.num * one.denum),(one.denum * two.denum)};
    tmp.denum = (one.denum * two.denum);
    tmp.num = (one.num * two.denum) + (two.num * one.denum);
    return tmp;
}

Fract toShort(Fract& obj)
{
    int end = obj.num < obj.denum ? obj.num : obj.denum;
    for (size_t i = end; i > 1; i--)
    {
        if (obj.num % i == 0 && obj.denum % i == 0) {
            obj.num /= i;
            obj.denum /= i;
        }
    }
    return obj;
}
Fract toTrue(Fract& obj) {
    obj.inter = obj.num / obj.denum;
    obj.num %= obj.denum;
    return obj;
}
int main()
{
    Fract one{ 1,3 };
    Fract two{ 2,5 };
    Fract res = sum(one, two);
    cout << "\t";
    print(one);
    cout << " + ";
    print(two);
    cout << " = ";
    print(res);
    cout << endl;

    Fract test{ 13,3 };
    print(test);
    cout << " --- > ";
    toShort(test);
    print(test);
    cout << endl;
    toTrue(test);
    print(test);
}


