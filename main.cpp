
#include "Vector.h"

int main(int argc, char** argv) {

    Vector<int> v;
    for (int i = 0; i < 12; i++){
        v.push_back(i);
    }
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    cout << "v:    " << v << endl;

    //regular testing
    Vector <string> vs1;
    vs1.push_back("Mr. Shi");
    vs1.push_back("Ms. Shin");
    vs1.push_back("Mr. Goddard");
    vs1.pop_back();
    cout << "vs1:  " << vs1 << endl;

    //regular testing
    Vector <string> vs2;
    vs2.push_back("Mr. Berry");
    vs2.push_back("Mr. Schellin");
    vs2.push_back("Mr. Bo");
    cout << "vs2:  " << vs2 << endl;

    //testing the copy constructor
    Vector <string> vs3(vs2);
    cout << "vs3:  " << vs3 << endl;

    //testing the assignment operator
    vs3 = vs1;
    vs3.push_back("Mr. Goddard");
    cout << "vs3:  " << vs3 << endl;
    
    //testing the overloaded operator []
    vs3[1] = "It's Julie";
    cout << "vs3:  " << vs3 << endl;
    
    //testing the at() function
    cout << "Look who's occupying vs3[1]: "<< vs3.at(1) << endl;
    


    cout << "=========================" << endl;

    return 0;
}

