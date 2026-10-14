# Implementacion de estructuras de datos dinamicas en C++

Trabajo colaborativo - Unidad 3 de la asignatura **Estructura de Datos Dinamicas**, CFT CENCO.

## Integrantes

- Ivan Munoz
- Alejandro Urgelles
- Luis Retamales
- Osvaldo Fuentes
- Luis Riveros

## Descripcion

El proyecto implementa una pequena biblioteca en C++ basada en nodos y punteros. Incluye:

- Lista enlazada simple: insercion, busqueda y eliminacion.
- Pila: operaciones `push` y `pop`, con comportamiento LIFO.
- Cola: operaciones `InsertarQ` y `EliminarQ`, con comportamiento FIFO.

El codigo contiene comentarios explicativos y libera la memoria dinamica utilizada por las estructuras.

## Estructura del proyecto

```text
estructuras-datos-dinamicas-cpp/
├── README.md
├── .gitignore
└── src/
    └── main.cpp
```

## Compilacion

Se requiere un compilador compatible con C++17, por ejemplo `g++`.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o biblioteca
```

## Ejecucion

En macOS o Linux:

```bash
./biblioteca
```

Salida esperada:

```text
BIBLIOTECA DE ESTRUCTURAS DINAMICAS

Lista despues de insertar: 10 -> 20 -> 30
Busqueda de 20: encontrado
Lista despues de eliminar 20: 10 -> 30
Pila - pop: 15
Cola - EliminarQ: 100
```

## Objetivo academico

Demostrar el uso de memoria dinamica y punteros mediante estructuras lineales, distinguiendo sus reglas de acceso y comprobando su funcionamiento con una ejecucion de prueba.
