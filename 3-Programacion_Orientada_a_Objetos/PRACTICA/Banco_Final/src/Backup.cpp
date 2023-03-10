#include "Backup.h"

//Constructores y Destructores
Backup::Backup(){

}

Backup::Backup(const char* inName){
    fileName = inName;
}

Backup::~Backup(){

}

//Setters y Getters
void Backup::setFileName(const char *inName){
    fileName = inName;
}

const char *Backup::getFileName(){
    return fileName.c_str();
}

///contemplar caso de agregar al final
//Métodos de la clase
fstream Backup::openFile(const char* inName, access modo){
    fstream file;
    string thisFileName = inName;

    if (modo){   // escritura
        file.open(inName, ios::out);
    } else {     // lectura
        file.open(inName, ios::in);
    }

    if (!file.good()){
        string mensaje = "No se pudo abrir el archivo \"" +
                         thisFileName + "\".\n";
        file.close();
        throw(runtime_error(mensaje.c_str()));
    }

    return file;
}

stringstream Backup::readFile(){
    stringstream buffer;

    try{
        //Abro archivo
        fstream fin = openFile(fileName.c_str(), INN);

        //Guardo su contenido en un buffer
        buffer << fin.rdbuf();

        //Lo cierro
        fin.close();
    }
    catch(...){
        throw;
    }

    return buffer;
}

//Cambiar el string de data
void Backup::saveFile(string data){
    try{
        //Abro archivo
        string tempFileName = fileName;
        for (int i = 0; i < 3; i++) tempFileName.pop_back();

        tempFileName += "temp";

        fstream fout = openFile(tempFileName.c_str(), OUTT);

        //Lo escribo
        fout << data;

        //Si llego hasta acá y no hubo ningún problema cierro
        //y borro el original y renombro el temporal.
        fout.close();
        remove(fileName.c_str());
        rename(tempFileName.c_str(), fileName.c_str());
    }
    catch(...){
        throw;
    }
}
