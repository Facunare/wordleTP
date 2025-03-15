#include "lib.h"
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    vector<string> palabras_validas = {};
    ifstream infile(nombre_archivo);
    if (infile.good() == false) {
        cout << "No se pudo abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
    string line;

    while(!infile.eof()) {
        if(getline(infile, line)){
            // Las palabras tienen "escondido" el caracter de salto de linea (excepto en la ultima palabra) -> lo borramos. 
            if (line.back() == '\r' || line.back() == '\n') {
                line.pop_back();
            }
            palabras_validas.push_back(line);
        }      
    }
    infile.close();

    return palabras_validas;
}


bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){

    if(intento.length() == palabra_secreta.length()){ // Chequeo que tengan igual longitud
        // Chequeo que la palabra secreta este en la lista de palabras validas
        for(int i = 0; i < listado.size(); i++){ 
            if(intento == listado[i]){
                return true;
            }
        }
    }

    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
   
    vector<EstadoLetra> estados = {};
    int indexIntento = 0;
    int indexSecreta = 0;

    // por cada letra del intento, recorro toda la palabra secreta
    while(indexIntento < intento.length()){
        indexSecreta = 0;
        while(indexSecreta < palabra_secreta.length()){
            if(intento[indexIntento] == palabra_secreta[indexSecreta] && indexIntento==indexSecreta){
                estados.push_back(EstadoLetra::LugarCorrecto);
                break;
            }else if(intento[indexIntento] == palabra_secreta[indexSecreta] && indexIntento!=indexSecreta){
                estados.push_back(EstadoLetra::LugarIncorrecto);
                break;
            }
           
            indexSecreta++;

            if(indexSecreta==palabra_secreta.length()){
                estados.push_back(EstadoLetra::NoPresente);
            }
        }

        indexIntento++;
       
    }

    return estados;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string cadenaFinal = "";
    int i = 0;
    while(i < respuesta.size()){
        EstadoLetra estado = respuesta[i];
        if(estado == EstadoLetra::LugarCorrecto){
            cadenaFinal = cadenaFinal + '+';
        }else if(estado == EstadoLetra::LugarIncorrecto){
            cadenaFinal = cadenaFinal + '-';
        }else if(estado == EstadoLetra::NoPresente){
            cadenaFinal = cadenaFinal + 'X';
        }
        i++;
    }

    return cadenaFinal;
}
