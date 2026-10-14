#include <iostream>
#include <stdexcept>

// Nodo base utilizado por la lista enlazada, la pila y la cola.
struct Nodo {
    int dato;
    Nodo* siguiente;

    explicit Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Lista enlazada simple con insercion al inicio, busqueda y eliminacion.
class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* eliminado = cabeza;
            cabeza = cabeza->siguiente;
            delete eliminado;
        }
    }

    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    bool buscar(int valor) const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            if (actual->dato == valor) {
                return true;
            }
        }
        return false;
    }

    bool eliminar(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual != nullptr && actual->dato != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            return false;
        }

        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;
        return true;
    }

    void mostrar() const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
    }
};

// Pila implementada mediante nodos enlazados. Aplica politica LIFO.
class Pila {
private:
    Nodo* cima;

public:
    Pila() : cima(nullptr) {}

    ~Pila() {
        while (cima != nullptr) {
            Nodo* eliminado = cima;
            cima = cima->siguiente;
            delete eliminado;
        }
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    int pop() {
        if (cima == nullptr) {
            throw std::underflow_error("La pila esta vacia");
        }

        Nodo* eliminado = cima;
        int valor = eliminado->dato;
        cima = cima->siguiente;
        delete eliminado;
        return valor;
    }
};

// Cola implementada mediante nodos enlazados. Aplica politica FIFO.
class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (frente != nullptr) {
            Nodo* eliminado = frente;
            frente = frente->siguiente;
            delete eliminado;
        }
        final = nullptr;
    }

    void InsertarQ(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (final == nullptr) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    int EliminarQ() {
        if (frente == nullptr) {
            throw std::underflow_error("La cola esta vacia");
        }

        Nodo* eliminado = frente;
        int valor = eliminado->dato;
        frente = frente->siguiente;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete eliminado;
        return valor;
    }
};

int main() {
    std::cout << "BIBLIOTECA DE ESTRUCTURAS DINAMICAS\n\n";

    ListaEnlazada lista;
    lista.insertarAlInicio(30);
    lista.insertarAlInicio(20);
    lista.insertarAlInicio(10);

    std::cout << "Lista despues de insertar: ";
    lista.mostrar();
    std::cout << '\n';

    std::cout << "Busqueda de 20: "
              << (lista.buscar(20) ? "encontrado" : "no encontrado") << '\n';

    lista.eliminar(20);
    std::cout << "Lista despues de eliminar 20: ";
    lista.mostrar();
    std::cout << '\n';

    Pila pila;
    pila.push(5);
    pila.push(10);
    pila.push(15);
    std::cout << "Pila - pop: " << pila.pop() << '\n';

    Cola cola;
    cola.InsertarQ(100);
    cola.InsertarQ(200);
    cola.InsertarQ(300);
    std::cout << "Cola - EliminarQ: " << cola.EliminarQ() << '\n';

    return 0;
}
