#include <iostream>
#include "Sistema.h"

int main() {

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

    Rossi.QuitarContacto("ivan@gmail.com");
    Rossi.VerListaContactos();
    return 0;


}