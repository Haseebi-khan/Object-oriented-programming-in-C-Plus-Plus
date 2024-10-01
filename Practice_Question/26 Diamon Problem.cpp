#include <iostream>

using namespace std;


class A
{
    int a;
    public:
    A()
    {
        a = 10;
        cout << "A" << endl;
    }
    void display()
    {
        cout << "A = " << a <<endl;
    }
};

class B : public  A
{
    int b;
    public:
    B()
    {
        b = 10;
        cout << "B" << endl;
    }
    void display()
    {
        cout << "B = " << b <<endl;
    }
};
class C : public virtual A
{
    int c;
    public:
    C()
    {
        c = 10;
        cout << "C" << endl;
    }
    void display()
    {
        cout << "C = " << c <<endl;
    }
};
class D : public B, public C //, public virtual A
{
    int d;
    public:
    D()
    {
        d = 10;
        cout << "D" << endl;
    }
    void display()
    {
        cout << "D = " << d <<endl;
    }
    void displayall()
    {
        // A::display();
        // B::display();
        // C::display();
        // D::display();
    }
};

int main()
{
    D d;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;


class A
{
    int a;
    public:
    A()
    {
        a = 10;
        cout << "A" << endl;
    }
    void display()
    {
        cout << "A = " << a <<endl;
    }
};

class B : public virtual A
{
    int b;
    public:
    B()
    {
        b = 10;
        cout << "B" << endl;
    }
    void display()
    {
        cout << "B = " << b <<endl;
    }
};
class C : public  A
{
    int c;
    public:
    C()
    {
        c = 10;
        cout << "C" << endl;
    }
    void display()
    {
        cout << "C = " << c <<endl;
    }
};
class D : public B, public C //, public virtual A
{
    int d;
    public:
    D()
    {
        d = 10;
        cout << "D" << endl;
    }
    void display()
    {
        cout << "D = " << d <<endl;
    }
    void displayall()
    {
        // A::display();
        // B::display();
        // C::display();
        // D::display();
    }
};

int main()
{
    D d;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;


class A
{
    int a;
    public:
    A()
    {
        a = 10;
        cout << "A" << endl;
    }
    void display()
    {
        cout << "A = " << a <<endl;
    }
};

class B : public  A
{
    int b;
    public:
    B()
    {
        b = 10;
        cout << "B" << endl;
    }
    void display()
    {
        cout << "B = " << b <<endl;
    }
};
class C : public  A
{
    int c;
    public:
    C()
    {
        c = 10;
        cout << "C" << endl;
    }
    void display()
    {
        cout << "C = " << c <<endl;
    }
};
class D : public B, public C //, public virtual A
{
    int d;
    public:
    D()
    {
        d = 10;
        cout << "D" << endl;
    }
    void display()
    {
        cout << "D = " << d <<endl;
    }
    void displayall()
    {
        A::display();
        B::display();
        C::display();
        D::display();
    }
};

int main()
{
    D d;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;


class A
{
    int a;
    public:
    A()
    {
        a = 10;
        cout << "A" << endl;
    }
    void display()
    {
        cout << "A = " << a <<endl;
    }
};

class B : public  A
{
    int b;
    public:
    B()
    {
        b = 10;
        cout << "B" << endl;
    }
    void display()
    {
        cout << "B = " << b <<endl;
    }
};
class C : public  A
{
    int c;
    public:
    C()
    {
        c = 10;
        cout << "C" << endl;
    }
    void display()
    {
        cout << "C = " << c <<endl;
    }
};
class D : public B, public C , public virtual A
{
    int d;
    public:
    D()
    {
        d = 10;
        cout << "D" << endl;
    }
    void display()
    {
        cout << "D = " << d <<endl;
    }
    void displayall()
    {
        // A::display();
        // B::display();
        // C::display();
        // D::display();
    }
};

int main()
{
    D d;
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;


class A
{
    int a;
    public:
    A()
    {
        a = 10;
        cout << "A" << endl;
    }
    void display()
    {
        cout << "A = " << a <<endl;
    }
};

class B : public virtual A
{
    int b;
    public:
    B()
    {
        b = 10;
        cout << "B" << endl;
    }
    void display()
    {
        cout << "B = " << b <<endl;
    }
};
class C : public virtual  A
{
    int c;
    public:
    C()
    {
        c = 10;
        cout << "C" << endl;
    }
    void display()
    {
        cout << "C = " << c <<endl;
    }
};
class D : public B, public C //, public virtual A
{
    int d;
    public:
    D()
    {
        d = 10;
        cout << "D" << endl;
    }
    void display()
    {
        cout << "D = " << d <<endl;
    }
    void displayall()
    {
        // A::display();
        // B::display();
        // C::display();
        // D::display();
    }
};

int main()
{
    D d;
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
















