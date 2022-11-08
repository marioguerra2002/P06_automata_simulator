// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos no deterministas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 08/11/2022
// Archivo symbol.cc
// Contiene las declaraciones de los métodos de la clase Symbol
// Referencias:
// Enlaces de interés
#include "symbol.h"
Symbol::Symbol(std::string recieved) {
  recieved_ = recieved;
}
std::string Symbol::GetSymbol() const {
  return recieved_;
}
const bool Symbol::operator==(const Symbol& symbol2) const {
  return recieved_ == symbol2.recieved_;
}
const bool Symbol::operator<(const Symbol symbol_2) const { return recieved_ < symbol_2.recieved_; }
void Symbol::operator=(const Symbol& symbol_2) { recieved_ = symbol_2.recieved_; }
Symbol::Symbol() {};