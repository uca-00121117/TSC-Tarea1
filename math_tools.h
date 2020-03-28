#include <vector>
#include <stdlib.h>
#include<math.h>
#include <iostream>

using namespace std;

typedef vector<float> Vector;

typedef vector<Vector> Matrix;

//      Parte 1 - Vector
// //Zeroes para vectores
void zeroes(Vector &v,int n){
    for (int i = 0; i < n; i++)
    {
        v.push_back(0.0);
    } 
}

//Zeroes para matrices
void zeroes(Matrix &M,int n ){
    for (int i = 0; i < n; i++)
    {
        //Crea un vector con caracteristicas de : dimension,valor
        Vector row(n,0.0);
        M.push_back(row);
    } 
}


//Copiar Vector

void copyVector(Vector v ,Vector &copy){
    zeroes(copy,v.size());
    for (int i = 0; i < v.size(); i++)
    {
        copy.at(i) = v.at(i);
    }
    

}

//Copiar Matriz


void copyMatrix(Matrix A ,Matrix &copy){
    zeroes(copy,A.size());
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.at(0).size(); j++)
        {
            copy.at(i).at(j) = A.at(i).at(j);
        }
        
    }
    

}

///Multiplicar un vector con una matriz

void productMatrixVector(Matrix A,Vector v,Vector &R){
    for (int fila = 0; fila < A.size(); fila++)
    {
        float cell=0.0;
        for (int col = 0; col <v.size() ; col++)
        {
            cell += A.at(fila).at(col) * v.at(col);

        }
        R.at(fila)+=cell;
    }
    
}

//Multiplica un numero por un real

void productRealMatrix(float real,Matrix M,Matrix &R)
{
    zeroes(R,M.size());
    for(int i=0;i<M.size();i++)
    {
        for (int j=0; j < M.at(0).size(); j++)
        {
            R.at(i).at(j) =real * M.at(i).at(j);
        }
        
    }
}

//Sumar 2 vectores

Vector sumVector(Vector A,Vector B,int n)
{
    Vector R;
    zeroes(R,n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        R.at(i) = A.at(i)+B.at(i);
    }
    return R;
}

// Sumar 2 Matrices 

Matrix sumMatrix(Matrix A,Matrix B,int n,int m)
{
    Matrix R;
    zeroes(R,n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        for (int j = 0; j < m; j++)
        {
            R.at(i).at(i)=A.at(i).at(i) + B.at(i).at(i);
        }
        
    }
    return R;
    
};

// Transponer una Matriz

void transpose(Matrix M,Matrix&T)
{
    zeroes(T,M.size());
   // cout<<T.size();
    for (int i = 0; i < M.size(); i++)
    {
        /* code */
        for (int j = 0; j < M.at(0).size(); j++)
        {
            /* code */
            T.at(j).at(i)=M.at(i).at(j);
        }
        
    }
    

}

//Determinante

void getMinor(Matrix &M,int i, int j)
{
    M.erase(M.begin()+i);
    for (int i = 0; i < M.size(); i++)
    {
        /* code */
        M.at(i).erase(M.at(i).begin()+j);
    }
    
}

float determinant(Matrix M)
{
    if(M.size()== 1)
    {
        return M.at(0).at(0);
    }
    else
    {
        float det=0.0;
        for (int i = 0; i < M.at(0).size(); i++)
        {
            /* code */
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);
            det+=pow(-1,i)*M.at(0).at(i)*determinant(minor);

        }
        return det;
    }

}


//La funcion recibe saca el cofactor de una matriz.
//La funcion recibe: Una matriz y la matriz que contendra los cofactores de la primera.

void cofactors(Matrix M, Matrix &Cof){
    //Se prepara la matriz de cofactores para que sea de las mismas
    //dimensiones de la matriz original
    zeroes(Cof,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            //Se calcula el cofactor de la posicion actual
            //      alternante * determinante del menor de la posicion actual
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void inversa(Matrix m_invertir,Matrix &invers)
{
    if(determinant(m_invertir)!=0){
        Matrix cof,adj;

        cofactors(m_invertir,cof);
        transpose(cof,adj);

        productRealMatrix(1/determinant(m_invertir),adj,invers);


    }
    else{
        exit(EXIT_FAILURE);

    };

};