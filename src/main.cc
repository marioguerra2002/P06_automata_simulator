// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos no deterministas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 08/11/2022
// Archivo main.cc
// Contiene el main del programa 
// Referencias:
// Enlaces de interés
#include "nfa.h"
#include <string.h>
#include <fstream>
#include <iostream>
int main(int argc, char* argv[]) {
  if (strcmp(argv[1], "--help") == 0) {
    std::cout << "Este programa lee un fichero de texto con un automata no determinista" << std::endl;
    std::cout << "y otro fichero de texto con una cadena de caracteres y comprueba si" << std::endl;
    std::cout << "la cadena pertenece al lenguaje del automata." << std::endl;
    std::cout << "Además, comprueba si el dfa y el nfa son equivalentes." << std::endl << std::endl;
    std::cout << "El archivo nfamodificado contiene el nfa modificado para " << std::endl;
    std::cout << "comprobar si deja de ser equivalente con el dfa" << std::endl << std::endl;
    std::cout << "Modo de empleo: ./P06_nfa nfa.fa dfa.fa input.txt" << std::endl;
    return 0;
  } else if (argc != 4) {
    std::cout << "Modo de empleo: ./P06_nfa nfa.fa dfa.fa input.txt" << std::endl;
    std::cout << "Pruebe ./P06_nfa --help para más información." << std::endl;
    return 1;
  }
  std::ifstream nfafile(argv[1]);
  std::ifstream dfafile(argv[2]);
  std::ifstream chainfile(argv[3]);
  std::string line;
  std::vector<std::string> vect_auxiliar;
  while (std::getline(nfafile, line)) {
    vect_auxiliar.push_back(line);  // meto cada línea del fichero en un vector
  }
  NFA nfa(vect_auxiliar);
  vect_auxiliar.clear();
  while (std::getline(dfafile, line)) {
    vect_auxiliar.push_back(line);  // meto cada línea del fichero en un vector
  }
  NFA dfa(vect_auxiliar);

  bool equivalent{false};
  while (std::getline(chainfile, line)) {
    if (Chain(line).IsChainAccepted(nfa.GetAlphabet())) {  // si la cadena pertenece al alfabeto
      if (nfa.IsAccepted(Chain(line))) {
        std::cout << line << "--------aceptada" << std::endl;
      } else {
        std::cout << line << "--------no aceptada" << std::endl;
      }
      if (nfa.IsAccepted(Chain(line)) == dfa.IsAccepted(Chain(line))) {
        equivalent = true;
      } else {
        equivalent = false;
      }
    }
  }
  if (equivalent) {
    std::cout << "Los automatas son equivalentes" << std::endl;
  } else {
    std::cout << "Los automatas no son equivalentes" << std::endl;
  }
}