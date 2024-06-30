#include "header.h"

class Student
{
private:
    
    int id; 
    int value;
    const char* data;
    
public:
    static const string class_name; // Cada clase tiene un static llamado : class_name
    Student() : id(0), value(0), data("") {}
    Student(int _key, int _value, const char* _data) : id(_key), value(_value), data(_data){}
    ~Student(){};

    friend ostream& operator<<(ostream& os, Student s)
    {
        os << "Student Object: " << s.id << " , " << s.value << " , " << s.data << endl;
        return os;
    }
};

const string Student::class_name = "StudentClass";

int main() 
{
    
    CacheManager <Student> my_cache(3);

    my_cache.insert("0", Student(0, 22, "student1"));
    my_cache.insert("1", Student(1, 23, "student2"));
    my_cache.insert("2", Student(2, 25, "student3"));
    my_cache.insert("3", Student(3, 29, "student4"));
   
    my_cache.show_cache();
    

    cout<<"- - - - - - - - - -- - -- - -- - -- - - UPDATE - - - - - - - - - - - - - -- - - -- - - - "<<endl;
    my_cache.insert("2", Student(22, 222, "EZE"));
    
    my_cache.show_cache();
    
    my_cache.show_memory();

    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    Student return_obj = my_cache.get("2"); // in cache
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    cout<<return_obj<<endl;
    
    
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    return_obj = my_cache.get("0"); // not in cache but in filesystem
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    cout<<return_obj;
    
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    my_cache.show_cache();
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
       
     
    my_cache.insert("9", Student(1, 5, "nine"));
    my_cache.insert("9", Student(22, 66, "nine"));

    my_cache.show_cache();
    
    my_cache.show_memory();

    my_cache.insert("12", Student(32, 8, "matias"));
    
    my_cache.show_cache();
    my_cache.show_memory();

    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    return_obj = my_cache.get("13"); // not in cache and not in filesystem
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    cout<<return_obj;

    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    return_obj = my_cache.get("1"); // not in cache but in filesystem
    cout<<"< < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < <"<<endl;
    cout<<return_obj;

    my_cache.show_cache();
    

    return EXIT_SUCCESS;
}