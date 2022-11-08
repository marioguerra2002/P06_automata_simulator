// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos no deterministas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 08/11/2022
// Archivo nfa.h
// Contiene la declaracion de la clase nfa
// Referencias:
// Enlaces de interés

#ifndef NFA_H_
#define NFA_H_

#include "state.h"
#include <iostream>
#include <utility>
#include <map>
#include <set>

class NFA {
  public:
    NFA (std::vector<std::string>);
    NFA ();
    const std::vector<State> GetStates(void) const;
    std::vector<State> GetNextStates(Symbol, std::vector<State>) const;
    void SetInitial(void);
    const bool IsAccepted(Chain) const;
    Alphabet GetAlphabet(void) const;
  private:
    Alphabet alphabet_;
    int number_states_;
    std::string initial_state_;
    std::vector <State> states_;
};
#endif // NFA_H_
