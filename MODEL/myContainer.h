#ifndef MYCONTAINER_H
#define MYCONTAINER_H

template <class T>
class myContainer {
    friend class myIterator;
private:
    class nodo;

    class smartp{
    public:
        nodo* punt;

        smartp(nodo* p = 0) : punt(p) { if(punt) punt->references++; }

        smartp(const smartp& s) : punt(s.punt) { if(punt) punt->references++; }

        ~smartp() {
            if(punt != 0){
                punt->references--;
                if(punt->references == 0) delete punt;
            }
        }

        smartp& operator=(const smartp& sp) {
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

        nodo& operator*() const {
            return *punt;
        }

        nodo* operator->() const {
            return punt;
        }

        T* getSmartPunt() const { return punt->info; }

        bool operator==(const smartp& sp) const { return punt == sp.punt; }

        bool operator!=(const smartp& sp) const { return punt != sp.punt; }
    };

    class nodo{
    public:
        nodo() : references(0) {}

        nodo(T* u, const smartp& p) : info(u), next_info(p), references(0) {}

        T* getInfo() const { return info; }

        T* info;
        smartp next_info;
        int references;
    };

    smartp first_info;

public:
    myContainer() : first_info(0) {}

    myContainer(const myContainer<T>& b) : first_info(b.first_info) {}

    myContainer<T>& operator=(const myContainer<T>& mc) {
        if(this != &mc){
            first_info = mc.first_info;
            if(first_info != 0) first_info->references++;
        }
        return *this;
    }

    bool empty() const { return first_info == 0; }

    void Push(T* u) { first_info = new nodo(u,first_info); }

    void Remove(T* u) {
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

    T* Pop() {
        T* aux = first_info->info;
        first_info = first_info->next_info;
        return aux;
    }

    class myIterator{
        friend class myContainer<T>;
    private:
        myContainer::smartp punt;
    public:
        bool operator==(myIterator mi) const { return punt == mi.punt; }

        bool operator!=(myIterator mi) const { return punt != mi.punt; }

        myIterator& operator++() {
            if(punt != 0) punt = punt->next_info;
            return *this;
        }

        myIterator operator++(int) {
            myIterator aux = *this;
            if(punt != 0) punt = punt->next_info;
            return aux;
        }

        T* operator*() const { return punt->info; }
    };

    myIterator begin() const {
        myIterator aux;
        aux.punt = first_info;
        return aux;
    }

    myIterator end() const  {
        myIterator aux;
        aux.punt = 0;
        return aux;
    }

    T* operator[](const myIterator& it) const { return (it.punt)->info; }
};

#endif // MYCONTAINER_H
