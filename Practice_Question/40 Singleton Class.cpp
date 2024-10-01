#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* instance;
    int width, height;

    // Private constructor
    Singleton(int a = 0, int b = 0) : width(a), height(b) {}

public:
    static Singleton* getInstance(int a = 0, int b = 0)
    {
        if (instance == nullptr)
        {
            instance = new Singleton(a, b);
        }
        return instance;
    }

    int area()
    {
        cout << "Singleton class area: " << width * height << endl;
        return width * height;
    }
};

// Initialize static member of class Singleton
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s = Singleton::getInstance(10, 3);
    s->area();

    Singleton* s2 = Singleton::getInstance();
    s2->area(); // Will use the same instance as `s`

    return 0;
}
