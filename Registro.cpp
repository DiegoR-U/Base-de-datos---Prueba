#include "registro.hpp"
registro::registro(char _nombre[100], int _d, int _m, int _y, int _inversion){
  if(nombre != nullptr){
    delete []nombre;
  }
  int count{0};
  for(int i = 0; i < 100; i++){
    count++;
    if(_nombre[i] == '\0'){
      break;
    }
  }
  count--;
  nombrelen = count;
  nombre = new char[count];
  for(int i = 0; i<count; i++){
    nombre[i] = _nombre[i];
  }
  d = _d;
  m = _m;
  y = _y;
  inversion = _inversion;
}
void registro::borrarregistro(){
  if(nombre != nullptr){
    delete []nombre;
  }
  return;
}
char registro::getnombre(){
  char x[nombrelen +1];
  for(int i = 0; i < nombrelen; i++){
    nombre[i] = x[i];
  }
  return x;
}
registro::setnombre(char _nombre[100]){
  if(nombre != nullptr){
    delete []nombre;
  }
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
int registro::getd(){
  return d;
}
void registro::setd(int x){
  d = x;
  return;
}
int registro::getm(){
  return m;
}
void registro::setm(int x){
  m = x;
  return;
}
int registro::gety(){
  return y;
}
void registro::sety(int x){
  y = x;
  return;
}
void registro::setfecha(int x, int y, int z){
  setd(x);
  setm(y);
  sety(z);
}
int getingreso(){
  return ingreso;
}
void setingreso(int x){
  ingreso = x;
  return;
}
