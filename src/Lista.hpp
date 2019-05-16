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
    _head = n;
    _length++;
    if (primero != NULL) {
        primero-> _prev = n;
    } else {
        _tail = _head;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *ultimo = _tail;
    n->_prev = ultimo;
    _tail = n;
    _length++;
    if (ultimo != NULL) {
        ultimo -> _next = n;
    } else {
        _head = _tail;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo *n = _head;
    if (i == 0){
        sacarFirst();
    } else {
        int p = 0;
        while ( p <= i && (n != NULL)) {
            if (p != i) {
                n = n-> _next;
            } else {
                if (n->_prev != NULL) {
                    (n->_prev)->_next = n-> _next;
                }
                if (n->_next != NULL) {
                    (n->_next)-> _prev = n-> _prev;
                }
                delete n;
                _length--;
            }
            p++;
        }
    }
}

template <typename T>
int Lista<T>::longitud() const {
    int i = this -> _length;
    return i;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* n = _head;
    int j = 0;
    while (j < i){
        n = n -> _next;
        j++;
    }
    const T& res = n -> _data;
    return res;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* n = _head;
    int j = 0;
    while (j < i){
        n = n -> _next;
        j++;
    }
    T& res = n -> _data;
    return res;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}