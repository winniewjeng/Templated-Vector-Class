
#include "Vector.h"

//#include <cstdlib>
//#include <iostream>
//#include <string>
//
//using namespace std;

int main(int argc, char** argv) {

    Vector<double> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);
    //    cout<<v<<endl;
    v.print_list();


    Vector <string> vs;
    vs.push_back("Mr. Shi");
    vs.push_back("Ms. Shin");
    vs.push_back("Mr. Goddard");


    vs.print_list();
    //    cout<<vs<<endl;

    cout << "=========================" << endl;

    return 0;
}

