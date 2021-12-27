#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    system("cls");
    srand(time(NULL));
    int a;
    cout << "Enter array size : ";
    cin >> a;
    int d[a];
    for (int i = 0; i < a; i++)
    {
        // printf("Arr[%d] : ", i);
        // cin >> d[i];
        d[i] = rand() % (5 * a); // Auto input
    }
    return 0;
}