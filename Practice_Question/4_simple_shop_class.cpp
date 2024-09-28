#include <iostream>

using namespace std;

class arr
{
    private:
        int itemid[10];
        int itemcost[10];
        int itemprice[10];
        string itemname[10];
        static int count;

    public:
        void initial_count() { count = 0; };
        void adding_item();
        void display_item();
};

void arr ::adding_item()
{
    cout << "Enter the Name of Item: ";
    cin >> itemname[count];
    cout << "Enter the ID of the Item: ";
    cin >> itemid[count];
    cout << "Enter the Cost of Item: ";
    cin >> itemcost[count];
    cout << "Enter the Price of Item: ";
    cin >> itemprice[count];
    count++;
}
int arr ::count;

void arr ::display_item()
{
    cout << "\t\t==============SHOP==================" << endl;

    cout << "Name  ID  Cost  Price" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << itemname[i] << " " << itemid[i] << "    " << itemcost[i] << "     " << itemprice[i] << endl;
    }
}
int main()
{
    arr shop;
    shop.adding_item();
    shop.display_item();

    return 0;
}