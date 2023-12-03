//
// Created by Diego Rossi on 03/12/23.
//

#ifndef WHATSVIERNES_USUARIO_H
#define WHATSVIERNES_USUARIO_H

#endif //WHATSVIERNES_USUARIO_H



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

    std::string getNombre() const {
        return Nombre;
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
            std::cout << "Selecciona un destinatario de la lista de contactos:\n";
                for (int i = 0; i < remitente->ListaContactos.size(); i++) {
                    std::cout << i + 1 << ". " << remitente->ListaContactos[i]->Nombre << "\n";
                }
                int seleccion;
                std::cin >> seleccion;
                destinatarios.push_back(remitente->ListaContactos[seleccion - 1]);




        }



        void enviar() {
            std::cout << "Mensaje de " << remitente->Nombre << ": " << texto << std::endl;
            std::cout << "Para: ";
            for (int i = 0; i < destinatarios.size(); i++) {
                std::cout << destinatarios[i]->Nombre;
            }

            std::cout << std::endl;
        }


    };

};