//
// Created by Diego Rossi on 03/12/23.
//

#ifndef WHATSVIERNES_SISTEMA_H
#define WHATSVIERNES_SISTEMA_H

#endif //WHATSVIERNES_SISTEMA_H

#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <ctime>
#include "Usuario.h"

class Sistema {
private:
    std::vector<std::string> ListaCorreos;
    std::vector<Usuario> Usuarios;


public:

    // Generador
    void AgregarUsuario(const std::string nombre, const std::string correo, const std::string user){
        Usuarios.emplace_back(nombre, correo, user);
    }




};

std::string currentDateTime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return buffer;
}