#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <unistd.h>

using namespace std;
typedef float T;

class Point
{
public:
    T x;
    T y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    void GetVal()
    {
        cout << "x = " << x << "\ny = " << y << endl;
    }

    T GetX()
    {
        return this->x;
    }
    T GetY()
    {
        return this->y;
    }
};

class Figure
{
public:
    int numb;
    Point a;
    Point b;

    Figure()
    {
        Point u(0, 0);
        this->a = u;
        this->b = u;
    }
    Figure(T x1, T y1, T x2, T y2)
    {
        Point t1(x1, y1), t2(x2, y2);
        this->a = t1;
        this->b = t2;
    }
    void Show(){
        this->a.GetVal();
        this->b.GetVal();
    }

    Point GeomCenter()
    {
        /* T angle = 3.14 / 180.0 * (360 / this->numb);
        T po = sqrt((this->a.GetX() - this->b.GetX())+(this->a.GetY() - this->b.GetY()));
        T r = sin(angle)*po/2; */

        T r, angle = 3.14 / 180.0 * (360 / this->numb);
        T x1 = this->a.GetX();
        T y1 = this->a.GetY();
        T x2 = this->b.GetX();
        T y2 = this->b.GetY();
        T xc = abs(this->a.GetX() - this->b.GetX()) / 2;
        T yc = r * cos(angle);

        for (int i = 0; i < this->numb; i++)
        {
            xc += round(x1);
            yc += round(y1);

            T nextX = ((x2 - x1) * cos(angle) + (y2 - y1) * -sin(angle)) + x2;
            T nextY = ((x2 - x1) * sin(angle) + (y2 - y1) * cos(angle)) + y2;
            x1 = x2;
            y1 = y2;
            x2 = nextX;
            y2 = nextY;
        }

        xc = xc / this->numb;
        yc = yc / this->numb;
        Point center(xc, yc);
        printf("Геометрическим центром вашего %d-угольника является точка:\n", this->numb);
        printf("(%f, %f)\n", xc, yc);
        return center;
    }
    void FindElsePoints()
    {
        T x1 = this->a.GetX();
        T y1 = this->a.GetY();
        T x2 = this->b.GetX();
        T y2 = this->b.GetY();

        T angle = 3.14 / 180.0 * (360 / this->numb);
        for (int i = 0; i < this->numb; i++)
        {
            printf("Вершина %d = (%.0f, %.0f);\n", i + 1, x1, y1);

            T nextX = ((x2 - x1) * cos(angle) + (y2 - y1) * -sin(angle)) + x2;
            T nextY = ((x2 - x1) * sin(angle) + (y2 - y1) * cos(angle)) + y2;
            x1 = x2;
            y1 = y2;
            x2 = nextX;
            y2 = nextY;
        }
    }
    T SofFig()
    {
        T po = sqrt((this->a.GetX() - this->b.GetX()) * (this->a.GetX() - this->b.GetX()) + (this->a.GetY() - this->b.GetY()) * (this->a.GetY() - this->b.GetY()));
        T angle = 3.14 / 180.0 * (360 / this->numb);
        T h = cos(angle / 2) / sin(angle / 2) * (po / 2);
        T s = (po * h * this->numb) / 2;
        printf("Площадь вашего %d-угольника = %.0f \n", this->numb, s);
        return s;
    }
    T S()
    {
        T po = sqrt((this->a.GetX() - this->b.GetX()) * (this->a.GetX() - this->b.GetX()) + (this->a.GetY() - this->b.GetY()) * (this->a.GetY() - this->b.GetY()));
        T angle = 3.14 / 180.0 * (360 / this->numb);
        T h = cos(angle / 2) / sin(angle / 2) * (po / 2);
        T s = (po * h * this->numb) / 2;
        return s;
    }

};

class EightSquare : public Figure
{
public:
    EightSquare() : Figure()
    {
        this->numb = 8;
    };
    EightSquare(T x1, T y1, T x2, T y2) : Figure(x1, y1, x2, y2)
    {
        this->numb = 8;
    };
    void FindElsePoints()
    {
        cout << "Фигура - Восьмиугольник" << endl;
        Figure ::FindElsePoints();
    }
};

class Square : public Figure
{
public:
    Square() : Figure()
    {
        this->numb = 4;
    };
    Square(T x1, T y1, T x2, T y2) : Figure(x1, y1, x2, y2)
    {
        this->numb = 4;
    };
    void FindElsePoints()
    {
        cout << "Фигура - Квадрат" << endl;
        Figure ::FindElsePoints();
    }
};

class Triangle : public Figure
{
public:
    Triangle() : Figure()
    {
        this->numb = 3;
    };
    Triangle(T x1, T y1, T x2, T y2) : Figure(x1, y1, x2, y2)
    {
        this->numb = 3;
    };
    void FindElsePoints()
    {
        cout << "Фигура - Треугольник" << endl;
        Figure ::FindElsePoints();
    }
};

void help()
{
    printf("Для выполнения операции введите соответствующую цифру:\n ");
    printf("\t 1 - Добавить фигуру в хранилище\n ");
    printf("\t 2 - Удалить последнюю добавленную фигуру из хранилища\n ");
    printf("\t 3 - Вывести Геом.Центр. для всех фигур\n ");
    printf("\t 4 - Вывести Координаты всех вершин для всех фигур\n ");
    printf("\t 5 - Вывести площади всех фигур\n ");
    printf("\t 6 - Вычислить общую площадь всех фигур\n ");
    printf("\t 7 - Удалить фигуру по индексу\n ");
    printf("\t 8 - Закрыть программу\n ");
    printf("\t 9 - Показать вектор\n ");
    printf("\t 0 - Вывести справку\n ");
}

int main()

{
    //freopen("test_02.txt", "r", stdin);
    char enter = -1;
    
    int c;
    T xl, xr, yl, yr;
    vector<Figure*> vec;
    help();
    cin >> enter;
    while (isdigit(enter))
    {
        //help();
        
        
        switch (enter-48)
        {
            case 1:
            {
                cout << "Введите слева-направо координаты двух нижних вершин вашей фигуры и кол-во вершин(на выбор: 3, 4, 8)." << endl;
                cin >> xl >> yl >> xr >> yr;
                cout << "Введите кол-во вершин." << endl;
                cin >> c;

                switch (c)
                {
                    case 3:
                    {
                        Triangle tr(xl, yl, xr, yr);
                        Triangle* ptr = new Triangle;
                        *ptr = tr;
                        vec.push_back(ptr);
                        ptr = NULL;
                        delete ptr;
                        break;
                    }
                    case 4:
                    {
                        Square a(xl, yl, xr, yr);
                        Square* pa = new Square;
                        *pa = a;
                        vec.push_back(pa);
                        pa = NULL;
                        delete pa;
                        break;
                    }
                    case 8:
                    {
                        EightSquare e(xl, yl, xr, yr);
                        EightSquare* pe = new EightSquare;
                        *pe = e;
                        vec.push_back(pe);
                        pe = NULL;
                        delete pe;
                        break;
                    }
                    default:
                    {
                    cout << "Введено неприемлимое кол-во вершин." << endl;
                    sleep(1);
                    cout << "Удаление диска через " << endl;
                    for (int i = 3; i > 0; --i)
                    {
                        sleep(1);
                        cout << i << endl;
                    }
                    sleep(1);
                    cout << " Шутка =)" << endl;
                    sleep(1);
                    return 0;
                    }
                }
                cout << "Эдемент вставлен." << endl;
                break;
            }
            case 2:
            {
                vec.pop_back();
                cout << "Фигура удалена\n Текущий размер хранилища :Size = " << vec.size() << endl;
                break;
            }
            case 3:
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    vec[i]->GeomCenter();
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    cout << "Фигура индекс №" << i << endl;
                    vec[i]->FindElsePoints();
                }
                break;
            }
            case 5:
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    vec[i]->SofFig();
                }
                break;
            }
            case 6:
            {
                T x;
                for (int i = 0; i < vec.size(); i++)
                {
                    x += vec[i]->S();
                }
                cout << "Общая площадь всех фигур = " << x <<endl;
                break;
            }
            case 7:
            {
                int del;
                cout << "Введите номер удаляемого элемента в векторе"<<endl;
                cin >> del;
                vec.erase(vec.begin() + del);
                break;
            }
            case 8:
            {
                return 0;
            }
            case 9:
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    printf("[%d]%d-угольник:\n", i,vec[i]->numb);
                    (*vec[i]).a.GetVal();
                    (*vec[i]).b.GetVal(); 
                    
                }
                break;                
            }
            case 0:
            {
                help();
                break;
            }
            default:
            {
                cout << "Некоректный ввод\n выход из программы..." << endl;
                return 0;
            }
        }
        cin >> enter;
    }
    cout << "Похоже введена буква, ну в другой раз не промахнётесь по клавиатуре \n\n" <<endl;
    return 0;
}
