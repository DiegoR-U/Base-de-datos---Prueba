#include "Ingreso.hpp"
#include <iostream>
ingreso::ingreso(int _bruto, int _gasto, int _d, int _m, int _y){
    bruto = _bruto;
    gasto = _gasto;
    neto = bruto - gasto;
    d = _d;
    m = _m;
    y = _y;
}
