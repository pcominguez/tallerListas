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

template<class T>
Lista<T>::Nodo::Nodo(const T& elem) : _data(elem), _prev(NULL), _next(NULL){};

template<class T>
Lista<T>::Nodo::Nodo(Nodo& n) : _data(n._data), _prev(n._prev), _next(n._next){};


template  <typename T>
void Lista<T>::sacarFirst(){
    Nodo* n = _head;
    _head = _head->_next;
    _length--;
    delete n;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    this->~Lista();
    (this->_head) = aCopiar._head;
    Nodo* iterar = (aCopiar._head);
    int i=0;
    while (i < (aCopiar._length)) {
        (*this).agregarAtras(iterar->_data);
        iterar = (iterar)->_next;
        i++;
    }
    int nuevalength = (aCopiar._length);
    (this->_length) = nuevalength;
    return *this;
}


template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *primero = _head;
    n->_next = primero;
    _length++;
    _head = n;
    if (primero != NULL) {
        primero-> _prev = n;
    } else {
        _tail = _head;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *primero = _head;
    n->_next = primero;
    _length++;
    _head = n;
    if (primero != NULL) {
        primero-> _prev = n;
    } else {
        _tail = _head;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo *n = _head;
    if (i == 0){
        sacarFirst();
    } else {
        for (int p = 0; p <= i && (n != NULL); p++) {
            if (p != i) {
                n = n-> _next;
            } else {
                if (n->_prev != NULL) {
                    (n->_prev)->_next = n-> _next;
                }
                if (n->_next != NULL) {
                    (n->_next)-> _prev = n-> _prev;
                }
                delete (n);
            }
        }
        _length--;
    }
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
    while (j <= i && (n != NULL)){
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
    while (j <= i && (n != NULL)){
        if (j != i){
            n = n -> _next;
        }
        j++;
    }
    return n -> _data;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}