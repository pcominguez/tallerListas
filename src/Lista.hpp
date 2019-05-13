#include "Lista.h"

template <typename T>
Lista<T>::Lista()
    :_length(0), _head(NULL), _tail(NULL){}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    while (_head!=NULL){
        sacarFirst();
    }
}
template  <typename T>
void Lista<T>::sacarFirst(){
    Nodo* n = _head;
    _head = _head->_next;
    _length--;
    delete n;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    this->~Lista(); //fijarme si funciona.
    (this->head)=(aCopiar.head);
    (this->tail)=(aCopiar.tail);
    (this->length)=(aCopiar.length);
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *primero = _head;
    n->next = primero;
    _length++;
    _head = n;
    if (primero != NULL) {
        primero->prev = n;
    } else {
        _tail = _head;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *ultimo = _tail;
    n->prev = ultimo;
    _tail = n;
    _length++;
    if (ultimo != NULL) {
        ultimo->next = n;
    } else {
        _head = _tail;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    // Completar
}

template <typename T>
int Lista<T>::longitud() const {
    int i = 0;
    Nodo* n = _head;
    while(n != NULL){
        i++;
        n = _head-> _next;
    }
    return i;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* n = _head;
    int j = 0;
    while (j <= i && (n != NULL){
        if (j != i){
            n = n -> _next;
        }
        j++;
    }
    return n -> data;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* n = _head;
    int j = 0;
    while (j <= i && (n != NULL){
        if (j != i){
            n = n -> _next;
        }
        j++;
    }
    return n -> data;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}