// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos no deterministas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 08/11/2022
// Archivo alphabet.cc
// Contiene la definición de los métodos de la clase alphabet
// Referencias:
// Enlaces de interés
#include "alphabet.h"
Alphabet::Alphabet (std::vector<std::string> input) {
  for (unsigned int i{0}; i < input.size() - 1; ++i) {  // -1 porque el símbolo final es chain
    alphabet_.insert(Symbol(input[i]));
  }
}
std::set<Symbol> Alphabet::GetSet(void) {
  return alphabet_;
}