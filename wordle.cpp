#include "lib.h"
#include <iostream>

using namespace std;



int main(){
    
    string filename;
    cout << "Ruta al listado de palabras: ";
    cin >> filename;
    vector<string> listado = cargar_listado(filename);

    srand(time(0)); // uso esta linea para que rand() no retorne siempre el mismo valor
    string palabra_secreta = listado[rand() % listado.size()];
    cout << "La palabra secreta tiene " << palabra_secreta.length() << " letras." << endl;

    
    int cantIntentos = 6;

    while(cantIntentos > 0){
        cout << "Te quedan " << cantIntentos << " intentos" << endl;
        string intento;
        cin >> intento;
        bool isValid = intento_valido(intento, palabra_secreta, listado);
        if(!isValid){
            cout << "Palabra Invalida. Intente nuevamente." << endl;
            continue;
        }
        vector<EstadoLetra> resultado = evaluar_intento(intento, palabra_secreta);
        string respuestaString = respuesta_en_string(resultado);
        cout << respuestaString << endl;
        
        if(intento == palabra_secreta){
            cout << "¡Correcto!" << endl;
            break;
        }else{
            cantIntentos--;
            if(cantIntentos==0){
                cout << "Se acabaron los intentos. Perdiste!" << endl;
                break;
            }
        }
    }
}
