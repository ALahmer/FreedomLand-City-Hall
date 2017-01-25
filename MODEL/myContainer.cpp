/*#include "MODEL/myContainer.h"

template<class T>
myContainer<T>::nodo::nodo() : references(0) {}

template<class T>
myContainer<T>::nodo::nodo(T* u, const smartp& p) : info(u), next_info(p), references(0) {}

template<class T>
T* myContainer<T>::nodo::getInfo() const {
    return info;
}

template<class T>
myContainer<T>::myContainer(const myContainer<T>& b) : first_info(b.first_info) {}

template<class T>
bool myContainer<T>::empty() const {
    return first_info == 0;
}

template<class T>
void myContainer<T>::Push(T* u) {
    first_info = new nodo(u,first_info);
}

template<class T>
void myContainer<T>::Remove(T* u) {
    smartp p_info = first_info, prev_info , q_info;
    smartp original_first_info = first_info;
    first_info = 0;
    while(p_info != 0 && !(p_info->info == u)){
        q_info = new nodo(p_info->info, p_info->next_info);
        if(prev_info == 0) first_info = q_info;
        else prev_info->next_info = q_info;
        prev_info = q_info;
        p_info = q_info->next_info;
    }
    if(p_info == 0) first_info = original_first_info;
     else if(prev_info == 0) first_info = p_info->next_info;
           else prev_info->next_info = p_info->next_info;
}

template<class T>
T* myContainer<T>::Pop() {
    T* aux = first_info->info;
    first_info = first_info->next_info;
    return aux;
}

template<class T>
myContainer<T>& myContainer<T>::operator=(const myContainer<T>& mc){
    if(this != &mc){
        first_info = mc.first_info;
        if(first_info != 0) first_info->references++;
    }
    return *this;
}

template<class T>
myContainer<T>::myIterator myContainer<T>::begin() const {
    myIterator aux;
    aux.punt = first_info;
    return aux;
}

template<class T>
myContainer<T>::myIterator myContainer<T>::end() const {
    myIterator aux;
    aux.punt = 0;
    return aux;
}

template<class T>
T* myContainer<T>::operator[](const myContainer<T>::myIterator& it) const {
    return (it.punt)->info;
}

template<class T>
bool myContainer<T>::myIterator::operator==(myIterator mi) const {
    return punt == mi.punt;
}

template<class T>
bool myContainer<T>::myIterator::operator!=(myIterator mi) const {
    return punt != mi.punt;
}

template<class T>
myContainer<T>::myIterator& myContainer<T>::myIterator::operator++(){
    if(punt != 0) punt = punt->next_info;
    return *this;
}

template<class T>
myContainer<T>::myIterator myContainer<T>::myIterator::operator++(int){
    myIterator aux = *this;
    if(punt != 0) punt = punt->next_info;
    return aux;
}

template<class T>
T* myContainer<T>::myIterator::operator*() const {
    return punt->info;
}

template<class T>
myContainer<T>::smartp::smartp(nodo *p) : punt(p) {
    if(punt) punt->references++;
}

template<class T>
myContainer<T>::smartp::smartp(const smartp& s) : punt(s.punt) {
    if(punt) punt->references++;
}

template<class T>
myContainer<T>::smartp::~smartp(){
    if(punt != 0){
        punt->references--;
        if(punt->references == 0) delete punt;
    }
}

template<class T>
myContainer<T>::smartp& myContainer<T>::smartp::operator=(const smartp& sp){
    if(this != &sp){
        nodo* temp = punt;
        punt = sp.punt;
        if(punt) (punt->references)++;
        if(temp){
            (temp->references)--;
            if(!(temp->references)) delete temp;
        }
    }
    return *this;
}

template<class T>
myContainer<T>::nodo& myContainer<T>::smartp::operator*() const{
    return *punt;
}

template<class T>
myContainer<T>::nodo* myContainer<T>::smartp::operator->() const{
    return punt;
}

template<class T>
T* myContainer<T>::smartp::getSmartPunt() const {
    return punt->info;
}

template<class T>
bool myContainer<T>::smartp::operator==(const smartp& sp) const{
    return punt == sp.punt;
}

template<class T>
bool myContainer<T>::smartp::operator!=(const smartp& sp) const{
    return punt != sp.punt;
}
*/

