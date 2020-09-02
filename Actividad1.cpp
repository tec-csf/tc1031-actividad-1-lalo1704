//Eduardo Galindo Rojas Loa
//A01028846
//Actividad1


#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>


using namespace std;

int genera_int()
{
    return rand() %10000;
}

template <typename T>
int busqueda (vector <T> elementos,T valor)
{
    int i=0;
    int encontrado = -1;

    long int size = elementos.size();

    while (encontrado==-1 && i<size)
    {
        if (elementos[i] == valor)
        {
            encontrado = i;
        }
        ++i;
    }
    return encontrado;
    cout<<endl;
}

template <typename T>
void busqueda_secuencial (vector <T> elementos, T num_buscado, T repetir)
{
for (int i=0;i<repetir;i++)


    {

    auto start = chrono::steady_clock::now();

    cout<<"Número buscado: "<<num_buscado<<endl;

    int result= busqueda(elementos, num_buscado);

    auto end = chrono::steady_clock::now();
    cout << "Tiempo de ejecución : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microsegundos" << endl; 

    if (result==-1)
    {
        cout<<"El valor no se encontró"<<endl;
        cout<<"-------------------------------------------------"<<endl;  
    }
    else
    {
        cout<<"El valor se encuentra en la posición: "<< result+1<<endl;
        cout<<"-------------------------------------------------"<<endl; 
    } 
    

    cout<<"-----------------------------------------------------------"<<endl;
    }
}
template <typename T>
void busqueda_secuencialMovFrente(vector <T> elementos, T num_buscado, T repetir)
{
for (int i=0;i<repetir;i++)
{
    auto start = chrono::steady_clock::now();

    cout<<"Número buscado: "<<num_buscado<<endl;
    int result= busqueda(elementos, num_buscado);

    auto end = chrono::steady_clock::now();
    cout << "Tiempo de ejecución : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microsegundos" << endl; 

    if (result==-1)
    {
        cout<<"El número no está en el vector"<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
    else
    {    
        cout<<"El número se encontraba en en la posición: "<< result+1 << ", ahora está en primero"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        
        int primero = elementos.at(result);
        for (int i=result; i>=1; --i)
        {
            elementos.at(i)=elementos.at(i-1);
        }
        elementos.at(0)=primero;
        cout<<endl; 
    }
    
}
}

template <typename T>
void busqueda_secuencialTransposicion(vector <T> elementos, T num_buscado, T repetir)
{
    for (int i=0;i<repetir;i++)
    {
    cout<<"Número buscado: "<<num_buscado<<endl;
    auto start = chrono::steady_clock::now();
    int result= busqueda(elementos, num_buscado);

    auto end = chrono::steady_clock::now();
    cout << "Tiempo de ejecución : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microsegundos" << endl; 

    if (result==-1)
    {
        cout<<"El número no está en el vector"<<endl;
        cout<<"-------------------------------------------------"<<endl;

    }
    else
    {     
        cout<<"El número se encontraba en en la posición: "<< result+1 << " y se intercambió con el de la primera"<<endl;
        cout<<"-------------------------------------------------"<<endl;

        int primero = elementos.at(1);
        int num = elementos.at(result);

        elementos.at(0)= num;
        elementos.at(result)=primero;

        cout<<endl;
    }     
}
}
template <typename T>
void busqueda_secuencialOrdenamiento(vector <T> elementos, T num_buscado, T repetir)
{
for (int i=0;i<repetir;i++)
    {
    int encontrado=-1;

    cout<<"Número buscado: "<<num_buscado<<endl;

    sort(elementos.begin(),elementos.end());

    long int size = elementos.size();

    int a=0;

    auto start = chrono::steady_clock::now();

    while (encontrado==-1 && a < size)
    {
        //cout<<elementos[a]<<", ";
        if (elementos[a] == num_buscado)
        {
            encontrado = a;
            break;
        } 
        ++a;   
    } 
    cout<<endl;
    
    auto end = chrono::steady_clock::now();
    cout << "Tiempo de ejecución : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microsegundos" << endl; 
   
    
    if (encontrado==-1)
    {
        cout<<"El valor no se encontró"<<endl;
        cout<<"-------------------------------------------------"<<endl; 
        
        
    }
    else
    {
        cout<<"El valor se encuentra en la posición: "<< encontrado+1<<endl;
        cout<<"-------------------------------------------------"<<endl; 
    }  
    }
}


template <typename T>
void busqueda_binaria(vector <T> elementos, T num_buscado, T repetir)
{
    for (int i=0;i<repetir;i++)
    {
        num
    sort(elementos.begin(),elementos.end());

    /*
    cout<<"Vector ordenado: "<<endl;
    for(vector<int>::iterator it = elementos.begin() ; it != elementos.end(); ++it)
    {
    cout << *it<< ", ";
    }
    */
    
    
    cout << endl;
    cout<<endl;

    int inferior= 0;
    int superior= elementos.size();

    int encontrado = -1;

    auto start = chrono::steady_clock::now();

    while (inferior <= superior)
    {
        int medio= (inferior+superior)/2;
    
        if(elementos[medio]==num_buscado)
        {
            encontrado= medio;
            break;
        }
        if(elementos[medio] > num_buscado)
        {
            superior=medio-1;
            medio= (inferior+superior)/2;
        }
        if(elementos[medio] < num_buscado)
        {
            inferior=medio+1;
            medio=(inferior+superior)/2;
        }
    }

    auto end = chrono::steady_clock::now();
    cout << "Tiempo de ejecución : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microsegundos" << endl;
   
    if (inferior>superior)
    {
        cout<<"El número no se encontró"<<endl;
    }
    else if (encontrado != 1)
        {
            cout<<"El número se ecuentra en la posición: "<<encontrado+1<<endl;
        }
    else
    {
        cout<<"El número no se encontró"<<endl;
    }
    }
    

}


int main()
{
    //Veces que se repite cada método
    int repetir=10;

    //Elemento buscado en el vector
    int valor_buscado=10;


    //Declaración del vector
    vector <int> elementos;

    srand((int) time(nullptr));

    //Número de Elementos que agregar a acada función
    int N=100000;

    //función que agrega N elementos al vector
    for (int i=0; i<N; ++i)
    {
        elementos.push_back(genera_int());
        //cout << elementos.back() << ", ";
    }  
    //cout<<endl;
    cout<<"-----------------------------------Busq Secuencial----------------------------------------"<<endl;

    auto start = chrono::steady_clock::now();
    
    busqueda_secuencial<int>(elementos, valor_buscado, repetir);

    
    cout<<"-----------------------------------Mov al frente----------------------------------------"<<endl;

    busqueda_secuencialMovFrente<int>(elementos,valor_buscado,repetir);

    cout<<"-----------------------------------Transposición----------------------------------------"<<endl;

    busqueda_secuencialTransposicion<int>(elementos,valor_buscado,repetir);

    cout<<"-----------------------------------Ordenamiento------------------------------------------"<<endl;

    busqueda_secuencialOrdenamiento<int>(elementos,valor_buscado,repetir);

    cout<<"-----------------------------------Busq Binaria------------------------------------------"<<endl;

    busqueda_binaria<int>(elementos, valor_buscado, repetir);

}