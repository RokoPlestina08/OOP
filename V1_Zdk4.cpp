#include <iostream>
#include <string>

char* at(char C[]) {
    char &ref = C[1];
    return &ref;
}

int main()
{
    char C[] = {'a','b','c','d'};
    char* Znak = at(C);
    std::cout<<"Rezultat je " << Znak + 1 << std::endl;

    return 0;
}