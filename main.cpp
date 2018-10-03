
#include "Vector.h"

//#include <cstdlib>
//#include <iostream>
//#include <string>
//
//using namespace std;



int main(int argc, char** argv) {
    
    Vector<double> v;
    v.push_back(4);
    v.push_back(5);
//    cout<<v<<endl;
//    v.print_list();
    

    Vector <string> vs;
    vs.push_back("Mr. Shi");
    vs.push_back("Ms. Shin");
    vs.push_back("Mr. Goddard");
    
    vs.print_list();
//    cout<<vs<<endl;

    cout << "=========================" << endl;

    return 0;
}

