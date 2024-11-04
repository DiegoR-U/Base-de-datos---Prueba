#include "Ingreso.hpp"
#include <iostream>
ingreso::ingreso(float _ingreso, float _gasto, int _d, int _m, int _y){
    ingreso = _ingreso;
    gasto = _gasto;
    neto = bruto - gasto;
    d = _d;
    m = _m;
    y = _y;
}
ingreso::editingreso(float x){
    ingreso = x;
}
registro::editd(int x){
  d = x;
}
registro::editm(int x){
  m = x;
}
registro::edity(int x){
  y = x;
}
registro::editfecha(int x, int y, int z){
  editd(x);
  editm(y);
  edity(z);
}
