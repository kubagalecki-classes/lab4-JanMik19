#include <iostream>

template <typename T> // zadanie 1
class Para
{
    T t1, t2;
public:
    Para() { t1 = 0; t2 = 0; }
    Para(T a, T b) : t1(a), t2(b) {}
    T suma() { return t1 + t2; } // zadanie 2
};

template <typename T, unsigned int N> // zadanie 3
class TablicaPar
{
public:
    Para<T> tab[N]; // public aby byl dostep w int main()
    TablicaPar() {}
    TablicaPar operator[](int i) { return tab[i]; } // zadanie 4
};

template <typename T>
struct S {
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S<double> {
    void print() { puts("Specjalizacja dla double"); }
};

template <typename T> // zadanie 8
T iloczyn(T tab[], int N)
{
    T result = tab[0];
    for (int i = 1; i < N; i++)
        result *= tab[i];
    return result;
}

template <typename T> // zadanie 9
T sumaPary(Para<T> obj)
{
    return obj.suma();
}

int main()
{
    Para<double> obj1(5.,6.5);
    cout << obj1.suma();
    
    TablicaPar<double, 3> tab;
    cout << sizeof(tab.tab); // zwraca rozmiar tablicy tab
    
    S<int> s_1; // zadanie 6
    S<double> s_2; // zadanie 6
    cout << endl;
    s_1.print();
    s_2.print();
    
    int tabela[] = { 1, 2, 3 }; // zadanie 8
    int silnia_3 = iloczyn<int>(tabela, 3); // BADZ int silnia_3 = iloczyn(tabela, 3);
    cout << iloczyn<int>(tabela, 3); // BADZ cout << iloczyn(tabela, 3);
    
    cout << endl << sumaPary(obj1); // zadanie 9
    
    return 0;
}
