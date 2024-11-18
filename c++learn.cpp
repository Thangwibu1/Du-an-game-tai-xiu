#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;

    void is_running() {
        cout << "Student is running...";
    }
};

int main () {
    Student student_1{"Thang", 18};
    cout << student_1. name << " " << student_1.age;
    student_1.is_running();
    return 0;
}
