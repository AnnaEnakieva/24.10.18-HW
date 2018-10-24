/*Реализуйте структуру Array для работы с массивами выделенными в
динамической памяти. В программе должно присутствовать описание структуры
и программа показывающая работоспособность структуры.*/

#include <iostream>
using namespace std;

struct Array
{
    int n;
    double* data;
    Array (int a)
    {
        n = a;
        data = new double [a];
    };
    Array (const Array & A)
    {
        n = A.n;
        data = A.data;
    };
    ~Array ()
    {
        delete[]data;
    };
    void input ()
    {
        for (int i = 0; i < n; i++)
            cin >> *(data + i );
    };
    void output()
    {
        for (int i = 0; i < n; i++)
            cout << *(data + i) <<" ";
        cout << "\n";
    };
    double &operator [](int i)
    {
        return data[i];
    };
    double Max ()
    {
        double M = *data;
        for (int i = 0; i < n; i++)
            if (*(data + i) > M)
                M = *(data + i);
        return M;
    };
    double Min ()
    {
        double m = *data;
        for (int i = 0; i < n; i++)
            if (*(data + i) < m)
                m = *(data + i);
        return m;
    };
    double Avg ()
    {
        double s = 0;
        for (int i = 0; i < n; i++)
            s += *(data + i);
        return (s/n);
    };
};
void test (Array A)
{
    cout << "Copying constructor is working" << "\n";
}
int main()
{
    int N;
    cin >> N;

    Array kazino(N);
    kazino.input();
    cout << "\n";
    kazino.output();
    cout << "\n";

    cout << "Max value: " << kazino.Max() << "\n";
    cout << "Min value: " << kazino.Min() << "\n";
    cout << "Average value: " << kazino.Avg() << "\n";
    cout << "\n";

    cout << "First element: " << kazino[0] << "\n" << "Last element: " << [N-1] << "\n";
    cout << "\n";
    test (kazino);

    return 0;
}
