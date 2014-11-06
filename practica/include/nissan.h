#ifndef NISSAN_H
#define NISSAN_H
#include "carro.h"

class nissan:carro
{
    public:
        nissan(string marca , string combustible , int motor);
        virtual ~nissan();
        void kilometraje();
        void imprimir();
    protected:
    private:
};

#endif // NISSAN_H
