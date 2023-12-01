#include <iostream>
#include <vector>
#include <string>
#include <ranges>



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
    Usuario Prueba = Usuario("Pruebini", "ppp", "aaa");

    Rossi.DatosUsuario();
    Rossi.AgregarContacto(Ivan);
    Rossi.VerListaContactos();
    Rossi.QuitarContacto("ivan@gmail.com");
    Rossi.VerListaContactos();

    /*

    Rossi.AgregarContacto(Ivan);
    Rossi.AgregarContacto(Jesus);
    Rossi.AgregarContacto(Jime);
    Rossi.VerListaContactos();



    Ivan.AgregarContacto(Jime);
    Ivan.VerListaContactos();
    */




}