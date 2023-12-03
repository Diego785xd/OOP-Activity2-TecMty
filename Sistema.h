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
#include <limits>
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

class Grupo {
private:
    std::string nombre;
    std::vector<Usuario*> miembros;
    std::vector<std::string> historialMensajes;

public:
    Grupo(const std::string &nombre) : nombre(nombre) {}

    void agregarMiembro(Usuario &miembro) {
        miembros.push_back(&miembro);
    }

    void enviarMensaje(Usuario &remitente, const std::string &mensaje) {
        std::string mensajeCompleto = remitente.getNombre() + ": " + mensaje;
        historialMensajes.push_back(mensajeCompleto);
    }

    void mostrarHistorialMensajes() {
        for (const auto &mensaje : historialMensajes) {
            std::cout << mensaje << std::endl;
        }
    }
    void mostrarGrupo() {
        std::cout << "Nombre del grupo: " << nombre << std::endl;
        std::cout << "Miembros del grupo: ";
        for (const auto &miembro : miembros) {
            std::cout << miembro->getNombre() << ", ";
        }
        std::cout << std::endl;
    }
};

std::string currentDateTime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return buffer;
}