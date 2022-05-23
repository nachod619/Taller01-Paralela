#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include<stdlib.h>
#include<omp.h>
#define ARCHIVO "pruebas.csv"
using namespace std;


int main ()
{
    ifstream archivo(ARCHIVO);
    string linea;
    char separador = ';';
    int correctas;
    int incorrectas;
    int omitidas;
    float puntaje;
    float nota;
    clock_t time_req;
    cout<<"IMPLEMENTACION OpenMP"<<"\r\n";
    cout<<"Integrantes: BYRON ANTONIO BEAS MENAIQUE"<<"\r\n";
    cout<<"IGNACIO SEBASTIAN DELGADO VARGAS"<<"\r\n";
    cout<<"MATIAS IGNACIO INOSTROZA QUINTEROS"<<"\r\n";
    cout<<"espere mientras se crea el archivo..."<<"\r\n";
    string acorrectas[12] = {"\"A\"","\"E\"","\"C\"","\"B\"","\"B\"","\"D\"","\"A\"","\"B\"","\"E\"","\"C\"","\"B\"","\"D\""};
    ofstream archivo2;
    archivo2.open("pruebas_resultado.csv");
    archivo2 << "Token de Estudiante" << ";"<< "Preguntas correctas"<<";"<<"Preguntas incorrectas"<<";"<<"Preguntas omitidas"<<";"<<"Puntaje"<<";"<<"Nota"<<"\n";
    //inicio comandos omp
    #pragma omp parallel
    {
    getline(archivo,linea); //lee la primera linea para no contabilizarla
    //ejecuta mientras exista algun estudiante
    time_req = clock();
    #pragma omp barrier
    {
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string estudiante[13];
        correctas=0;
        incorrectas=0;
        omitidas=0;
        #pragma omp for
        {
        //revision de las respuestas por cada estudiante
        for(int i=0;i<13;i++)
        {
            getline(stream, estudiante[i], separador);
            if(i >= 1)
            {
                if(estudiante[i] == acorrectas[i-1])
                {
                    correctas++;
                }
                else
                {
                    if (estudiante[i]=="\"-\"")
                    {
                        omitidas++;
                    }
                    else
                    {
                        incorrectas++;
                    }
                }
            }
        puntaje = (correctas*0.5)-(incorrectas*0.12);
        nota = 1 + roundf(puntaje*10)/10;
        }
        }
        archivo2<<estudiante[0]<< ";"<< correctas <<";"<< incorrectas <<";"<< omitidas <<";"<< puntaje <<";"<< nota<<"\n";
    }
    }
    //se cierran ambos archivos
    archivo.close(); 
    archivo2.close();
    }
    cout << "COLO-COLO ES CHILE <3"<<"\r\n";
    time_req = clock() - time_req;
    cout<<"Tiempo de procesamiento = " << (float)time_req/CLOCKS_PER_SEC <<" segundos"<<"\r\n"<<endl;
    return 0;
}
