#include <string>
#include <iostream>
using namespace std;

#include "LinkedBag.h"

int main(){
    LinkedBag<string> newBag;

    newBag.add("Erin");
    newBag.add("Keith");

    vector<string> bagVector = newBag.toVector();
    
    for (int i = 0; i < (int)bagVector.size(); i++){
        cout << bagVector.at(i) <<endl;
    }

    return 0;
}