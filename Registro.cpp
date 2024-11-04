#include "registro.hpp"
registro::registro(char _nombre[100], int _d, int _m, int _y, int _inversion){
  delete []nombre;
  int count{0};
  for(int i = 0; i < 100; i++){
    count++;
    if(_nombre[i] == '\0'){
      break;
    }
  }
  count--;
  nombre = new char[count];
  for(int i = 0; i<count; i++){
    nombre[i] = _nombre[i];
  }
  d = _d;
  m = _m;
  y = _y;
  inversion = _inversion;
}
registro::editnombre(char _nombre[100]){
  delete []nombre;
  int count{0};
  for(int i = 0; i < 100; i++){
    count++;
    if(_nombre[i] == '\0'){
      break;
    }
  }
  count--;
  nombre = new char[count];
  for(int i = 0; i<count; i++){
    nombre[i] = _nombre[i];
  }
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
