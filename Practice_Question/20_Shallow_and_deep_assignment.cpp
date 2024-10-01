// #include <iostream>

// using namespace std;

// class exam
// {
//     int *first;
//     double *second;

// public:
//     exam()
//     {
//         first = new int;
//         second = new double;
//     }
//     exam(int v1, double v2)
//     {
//         first = new int(v1);
//         second = new double(v2);
//     }
//     ~exam()
//     {
//         delete first;
//         delete second;
//     }
//     int getf() const { return *first; }
//     double gets() const { return *second; }
//     void setd(int v1, double v2)
//     {
//         first = new int(v1);
//         second = new double(v2);
//     }
// };

// int main()
// {
//     exam obj(5, 3.25);
//     cout << obj.getf() << " " << obj.gets() << endl;
//     exam obj2 = obj;
//     obj.setd(565, 5.34);
//     cout << obj.getf() << " " << obj.gets() << endl;
//     cout << obj2.getf() << " " << obj2.gets() << endl;

//     return 0;
// }

// // Problem Statement 1:
// // Implement a copy constructor for a class that represents a customer.
// // The Customer class has two member variables: "name", which is a dynamically allocated string, and "address",
// // which is a statically allocated char array.
// // Test your implementation by creating two instances of the Customer class and
// // using the copy constructor to create a deep copy of one of them.

// #include <iostream>
// #include <string.h>

// using namespace std;

// class Customer
// {
//     string *name;
//     char address[20];

// public:
//     Customer(string cname, char caddress[])
//     {
//         name = new string(cname);
//         // name = cname;
//         strcpy(address, caddress);
//     }
//     ~Customer()
//     {
//         delete name;
//     }

//     Customer(const Customer &obj)
//     {
//         name = new string;
//         name = new string;
//         *name = *obj.name;
//         strcpy(address, obj.address);
//     }
//     void display()
//     {
//         cout << "Name: " << *name << ", Address: " << address << endl;
//     }
// };

// int main()
// {
//     char address[] = "Lahore";
//     Customer c1("Haseeb", address);

//     c1.display();
//     Customer c2 = c1;
//     c2.display();

//     return 0;
// }

// == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =

// // Problem Statement 2:
// // Implement a shallow copy constructor for a class that represents a playlist.
// // The Playlist class contains an array of songs which has a name and a duration.
// // Test your implementation by creating two instances of the Playlist class and
// // using the copy constructor to create a shallow copy of one of them.

// #include <iostream>

//                                                                                                                                                                                   using namespace std;

// class Songs
// {
//     string name;
//     int duration;

// public:
//     Songs() {}
//     Songs(string n, int d)
//     {
//         name = n;
//         duration = d;
//     }
//     void setsongs(string n, int d)
//     {
//         name = n;
//         duration = d;
//     }
//     string get_name()
//     {
//         return name;
//     }
//     int get_duration()
//     {
//         return duration;
//     }
// };

// class Playlist
// {
//     Songs songs[5];

// public:
//     Playlist() {}

//     void set_song(int i, const Songs &song)
//     {
//         songs[i] = song;
//     }
//     Playlist(Playlist &obj)
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             songs[i] = obj.songs[i];
//         }
//     }

//     void print()
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             cout << "Song " << i + 1 << ": " << songs[i].get_name() << ", Duration: " << songs[i].get_duration() << endl;
//         }
//     }
// };

// int main()
// {
//     Playlist playlist1;

//     playlist1.set_song(4, Songs("zzzz", 3));
//     playlist1.set_song(3, Songs("qqqqq", 2));
//     playlist1.set_song(0, Songs("wwwww", 24));
//     playlist1.set_song(2, Songs("ssss", 5));
//     playlist1.set_song(1, Songs("sdc", 65));

//     Playlist playlist2 = playlist1;

//     cout << "Playlist :" << endl;
//     playlist1.print();

//     cout << "Playlist 2:" << endl;
//     playlist2.print();

//     return 0;
// }

// == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

// // Problem Statement 3:
// // Implement a deep copy constructor for a class that represents a calendar.
// // The Calendar class contains an array of Event, each of event has id, name, start time, and end time.
// // Demonstrate the concept of shallow copy and Deep copy by taking event id as a pointer.
// // Test your implementation by creating two instances of the Calendar class and
// // using the copy constructor to create a deep copy of one of them.

// #include <iostream>

// using namespace std;

// class Event
// {
// private:
//     int *id;
//     string name;
//     string starting_date;
//     string ending_date;

// public:
//     Event() : name(""), starting_date(""), ending_date("")
//     {
//         id = new int;
//     }
//     Event(int ids, string n, string s_date, string e_date)
//     {
//         id = new int;
//         *id = ids;
//         name = n;
//         starting_date = s_date;
//         ending_date = e_date;
//     }
//     ~Event()
//     {
//         delete id;
//     }
//     Event(const Event &obj)
//     {
//         id = new int(*obj.id);
//         name = obj.name;
//         starting_date = obj.starting_date;
//         ending_date = obj.ending_date;
//     }
//     int get_id()
//     {
//         return *id;
//     }
//     string get_name()
//     {
//         return name;
//     }
//     string get_s()
//     {
//         return starting_date;
//     }
//     string get_e()
//     {
//         return ending_date;
//     }
// };

// class Calender
// {
//     Event event[5];

// public:
//     Calender() {}
//     void set_event(int i, const Event &events)
//     {
//         event[i] = events;
//     }
//     Calender(Calender &obj)
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             event[i] = obj.event[i];
//         }
//     }
//     void display()
//     {
//         cout << "---------------------------" << endl;
//         for (int i = 0; i < 5; i++)
//         {
//             cout << "Id : " << event[i].get_id() << endl;
//             ;
//             cout << "Name: " << event[i].get_name() << endl;
//             cout << "Starting data: " << event[i].get_s() << endl;
//             cout << "Ending data: " << event[i].get_e() << endl;
//             cout << "---------------------------" << endl;
//         }
//     }
// };

// int main()
// {
//     Calender cal;

//     cal.set_event(0, Event(12, "School function", "22-04-24", "25-04-24"));
//     cal.set_event(1, Event(13, "College function", "1-04-24", "3-04-24"));
//     cal.set_event(2, Event(14, "University function", "5-04-24", "6-04-24"));
//     cal.set_event(3, Event(15, "Marrige function", "3-04-24", "4-04-24"));
//     cal.set_event(4, Event(132, "Brithday function", "3-04-24", "6-04-24"));

//     cal.display();

//     Calender cal2 = cal;
//     cout << "8888888888888888888888888888888888888888888" << endl;

//     cout << "Deep copy" << endl;
//     cout << "8888888888888888888888888888888888888888888" << endl;

//     cal2.display();

//     return 0;
// }

// == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =

// // Implement a deep copy constructor for a class that represents a school.
// // The School class contains a pointers to Student objects say school id pointer,
// // which represent the students enrolled in the school. Each Student object has a dynamically allocated array of Course objects,
// // which represent the courses that the student is taking.
// // Test your implementation by creating two instances of the School class and
// // using the copy constructor to create a deep copy of one of them.
#include <iostream>

using namespace std;

class School
{
    int *id;

public:
    School(int ids, string obj[])
    {
        id = new int;
        *id = ids;
        std1 = new Student();
        std1->set_courses(obj);
    }
    ~School()
    {
        delete id;
    }
    class Student
    {
        string *course;

    public:
        Student()
        {
            course = new string[5];
            for (int i = 0; i < 5; i++)
            {
                course[i] = "";
            }
        }
        ~Student()
        {
            delete[] course;
        }

        Student(const Student &other)
        {
            course = new string[5];
            for (int i = 0; i < 5; i++)
            {
                course[i] = other.course[i];
            }
        }

        void set_courses(const string obj[])
        {
            for (int i = 0; i < 5; i++)
            {
                course[i] = obj[i];
            }
        }
        void display()
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "Course " << i + 1 << " :" << course[i] << "." << endl;
            }
        }
    } *std1;

    int get_id()
    {
        return *id;
    }
    School(const School &copying_obj)
    {
        id = new int(*copying_obj.id);
        std1 = new Student(*copying_obj.std1);
    }
};

int main()
{
    string courses[5] = {"english", "urdu", "mathe", "cs", "opps"};
    School s1(23, courses);

    cout << "id:" << s1.get_id();
    cout << endl;
    s1.std1->display();

    School s2 = s1;

    cout << "id:" << s2.get_id();
    cout << endl;
    s2.std1->display();

    return 0;
}
