// #include <iostream>
// using namespace std;
// class LFC
// {
// public:
//     int x;
// };
// int main()
// {
//     LFC *p = new LFC();

//     (*p).x = 5;

//     cout << (*p).x << " " << p->x << " ";

//     p->x = 10;

//     cout << (*p).x << " " << p->x;

//     return 0;
// }

// // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{

    int *li = (int*) malloc(3 * sizeof(int));
    int j = 3;

    for (int i = 0; i < 3; i++)
    {
        li[i] = 1 + i;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << li[i] << " ";
    }
    free(li);

    return 0;
}