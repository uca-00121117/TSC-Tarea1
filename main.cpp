#include <iostream>
#include "math_tools.h"
#include "display_tools.h"

 using namespace std;
int main(void){
    //Tarea 1
    //  Hacer una función que permita calcular la Inversa de una Matriz
    Matrix m_inversa,m_invertir;

    zeroes(m_invertir,3);

    m_invertir.at(0).at(0) =2; m_invertir.at(0).at(1) =2;  m_invertir.at(0).at(2) =3;
    m_invertir.at(1).at(0) =4; m_invertir.at(1).at(1) =5;  m_invertir.at(1).at(2) =6;
    m_invertir.at(2).at(0) =7; m_invertir.at(2).at(1) =8;  m_invertir.at(2).at(2) =9;

    inversa(m_invertir,m_inversa);
    showMatrix(m_inversa);

    return 0;
}