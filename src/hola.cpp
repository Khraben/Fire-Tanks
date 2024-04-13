#include <iostream>
#include <stdio.h>
#include "Tanque.hpp"
using namespace std;
int main() {
    Tanque *t = new Tanque("tank",100,23);
    string nombre = t->GetNombre();
    cout<<nombre<<endl;
    return 0;
}