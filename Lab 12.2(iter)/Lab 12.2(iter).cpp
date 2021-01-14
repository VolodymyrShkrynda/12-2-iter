#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};
void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
int PrintandSearch(Elem* L, int count, int x);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    Info info, N;

    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть дані: "; cin >> info;
        Enqueue(first, last, info);
    }

    cout << "Елементи списку: ";
    Print(first); cout << endl;
    int x;
    cout << "Введіть шуканий елемент: ";
    cin >> x;
    cout << "Кількість шуканих елементів: " << PrintandSearch(first, 0,x) << endl;
    return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}
void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
}
int PrintandSearch(Elem* L, int count, int x)
{
    count = 0;
    while (L != NULL)
    {
        if (L->info == x)
            count++;

        L = L->link;
    }
    return count;
}
