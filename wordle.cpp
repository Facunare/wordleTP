#include "lib.h"
#include "lib.cpp"
#include <iostream>

using namespace std;



int main(){
    string intento;
    cin >> intento;
    vector<EstadoLetra> resultado = evaluar_intento(intento, "jabon");
    string respuestaString = respuesta_en_string(resultado);
    cout << respuestaString << endl;

    
    // // Cargar listado
    // string filename;
    // cout << "Ruta al listado de palabras: ";
    // cin >> filename;
    // vector<string> listado = cargar_listado(filename);

    // // Generar palabra
    // srand(time(0));
    // string palabra_secreta = listado[rand() % listado.size()];
    // cout << "La palabra secreta tiene " << palabra_secreta.length() << " letras." << endl;
    // cout << palabra_secreta << endl;

    // int cantIntentos = 5;
    // cout << "Te quedan " << cantIntentos << " intentos." << endl;
    // string intento;
    // cin >> intento;
    // bool isValid = intento_valido(intento, palabra_secreta, listado);
    
    // while (isValid){
    //     vector<EstadoLetra> resultado = evaluar_intento(intento, palabra_secreta);
    //     string respuestaString = respuesta_en_string(resultado);
    //     cout << respuestaString << endl;
        
    //     if(respuestaString == "+++++"){
    //         cout << "Correcto!" << endl;
    //     }else{
    //         cantIntentos--;
    //         if(cantIntentos==0){
    //             cout << "Perdiste!" << endl;
    //         }
    //     }

    //     cout << "Te quedan " << cantIntentos << " intentos." << endl;
    //     string intento;
    //     cin >> intento;
    //     isValid = intento_valido(intento, palabra_secreta, listado);
    // }
}
