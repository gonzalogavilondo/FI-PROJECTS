#ifndef BACKUP_H
#define BACKUP_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
enum access{INN, OUTT = 1};

/**
 *  Backup es una clase que se encarga del manejo de archivos.
 */

class Backup
{
    public:
        //Constructores y Destructores
        Backup();
        Backup(const char*);
        ~Backup();

        //Setters y Getters
        void setFileName(const char *);
        const char *getFileName();

        //Métodos de la clase
        stringstream readFile();
        void saveFile(string data);
    private:
        fstream openFile(const char*, access);

        string fileName;
};

#endif // BACKUP_H
