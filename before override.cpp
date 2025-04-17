#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string f_name = "f_name";
    string l_name = "l_name";

public:
    virtual string GetName() {
        return f_name + l_name;
    }
};

class teacher : public person {
public:
    string GetName() {
        return "salam";
    }
};

int main() {
    teacher t;
    string n = t.GetName();
    cout << "Name: " << n << endl;
    return 0;
}
