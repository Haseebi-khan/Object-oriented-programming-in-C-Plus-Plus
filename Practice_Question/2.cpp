#include <iostream>
using namespace std;
/*
    id:

    01------->BSCS
    02------->BBA
    03------->BS(Aviation)
    04------->BS(ECO)
*/
int std_size = 5;
int teach_size = 5;
int mang_size = 5;

struct teacher
{
    string teach_name[&teach_size];
    int teach_id[&teach_size];
    long salary[&teach_size];
    string email[&teach_size];

};
struct mangement 
{
    string mang_name[&mang_size];
    int mang_id[&mang_size];
    long salary[&mang_size];
};
struct student
{
    string std_name[&std_size];
    int id[&std_size];
}; 


class person_info
{
private:
    teacher;
    mangement;
public:
    person_info(/* args */);
    ~person_info();
};

person_info::person_info(/* args */)
{
}

person_info::~person_info()
{
}




int main()
{
    

    
    return 0;
}