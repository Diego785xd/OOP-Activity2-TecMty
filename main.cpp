#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <ctime>


class Mensaje;

/*
 *
 *
 * Clase Usuarios
 *
 *
 * */


class Usuario {

private:
    //Atributos privados, solo accesibles por getters
    std::string Nombre;
    std::string Correo;
    std::string User;
    std::vector<Usuario*> ListaContactos;


public:

    //Constructor que guarda el valor en la lista de posibles correos
    Usuario(const std::string &nombre, const std::string &correo, const std::string &user){
        Nombre = nombre;
        Correo = correo;
        User = user;
    }


    void DatosUsuario(){
        std::cout << Nombre << " " << Correo << " " << User << std::endl;

    }

    void AgregarContacto(Usuario &amigo){


        amigo.DatosUsuario();
        ListaContactos.push_back(&amigo);
        std::cout << "Tu amigo " << amigo.Nombre << " fue agregado" <<std::endl;

    }


    void VerListaContactos(){

        std::cout << "En total tienes " << ListaContactos.size() << " amigos"<<std::endl;

        for (const auto& obj : ListaContactos) {
            std::cout << obj->Nombre <<std::endl;
        }
    }

    void QuitarContacto(const std::string& correo_eliminar){

        for (auto it = ListaContactos.begin(); it != ListaContactos.end(); ++it) {
            if ((*it)->Correo == correo_eliminar) {
                std::cout << "Correo encontrado y eliminado: " << (*it)->Correo << std::endl;

                ListaContactos.erase(it);
                return;
            }
        }
    }

    void enviarMensaje() {
        Mensaje mensaje(this);
        mensaje.setTexto();
        mensaje.nomDestinatario();
        mensaje.enviar();
    }


    class Mensaje {
    private:
        std::string texto;
        Usuario *remitente;
        std::vector<Usuario *> destinatarios;

    public:
        Mensaje(Usuario *remitente) : remitente(remitente) {}

        void setTexto() {
            std::cout << "Ingresa tu mensaje:  ";
            std::getline(std::cin, texto);
        }


        void nomDestinatario() {
            char continuar;
            do {
                std::cout << "Selecciona un destinatario de la lista de contactos:\n";
                for (int i = 0; i < remitente->ListaContactos.size(); i++) {
                    std::cout << i + 1 << ". " << remitente->ListaContactos[i]->Nombre << "\n";
                }
                int seleccion;
                std::cin >> seleccion;
                destinatarios.push_back(remitente->ListaContactos[seleccion - 1]);

                std::cout << "¿Deseas agregar otro destinatario? (s/n): ";
                std::cin >> continuar;

                switch (continuar) {
                    case 's':
                    case 'S':
                        break;
                    case 'n':
                    case 'N':
                        continuar = 'n';
                        break;
                    default:
                        std::cout << "Opción no válida. Por favor, introduce 's' para continuar o 'n' para terminar.\n";
                        continuar = 's';
                        break;
                }
            } while (continuar == 's' || continuar == 'S');
        }



        void enviar() {
            std::cout << "Mensaje de " << remitente->Nombre << ": " << texto << std::endl;
            std::cout << "Para: ";
            for (int i = 0; i < destinatarios.size(); i++) {
                std::cout << destinatarios[i]->Nombre;
                if (i < destinatarios.size() - 2) {
                    std::cout << ", ";
                } else if (i == destinatarios.size() - 2) {
                    std::cout << " y ";
                }
            }

            std::cout << std::endl;
        }


    };

};







/*
 *
 *
 * Clase Sistema
 *
 *
 * */

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

/*
 *
 *
 * Clase Main
 *
 *
 * */


int main() {

    int n;

    Usuario Rossi = Usuario("Diego", "dperezrossi@gmail.com", "drossi");
    Usuario Ivan = Usuario("Ivan", "ivan@gmail.com", "ivani");
    Usuario Jesus = Usuario("Jesus", "jesus@gmail.com", "jsus");
    Usuario Jime = Usuario("Jime", "jime@gmail.com", "jims");

    Rossi.DatosUsuario();
    Rossi.AgregarContacto(Ivan);
    Rossi.AgregarContacto(Jesus);
    Rossi.AgregarContacto(Jime);
    Rossi.VerListaContactos();
    Rossi.enviarMensaje();
    std::cout << "Fecha y hora de envio: " << currentDateTime() << std::endl;

    return 0;
    /*
     *

    Rossi.AgregarContacto(Ivan);
    Rossi.AgregarContacto(Jesus);
    Rossi.AgregarContacto(Jime);
    Rossi.VerListaContactos();



    Ivan.AgregarContacto(Jime);
    Ivan.VerListaContactos();
    */




}