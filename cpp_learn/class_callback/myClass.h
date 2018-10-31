#include <iostream>
#include <string>

using namespace std;
class eye {
public:
    eye(string name) {
        cout << "I am eye, my name is " << name << endl;
    }
};

class nose {
public:
    nose(string name) {
        cout << "I am nose is " << name<< endl;
    }

};

class face {
public:
    face(string name) {
        cout << "I am face is " << name<< endl;
    }

};

class myClass {
public:
    myClass(string eye, string nose, string face)
        : myEye_(eye),
        myNose_(nose),
        myFace_(face)
    {
        cout << "myClass here~" << endl;
    }

private:
    eye myEye_;
    nose myNose_;
    face myFace_;
};
