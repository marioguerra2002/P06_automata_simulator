// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos no deterministas
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 08/11/2022
// Archivo nfa.cc
// Contiene las definiciones de los métodos de la clase NFA
// Referencias:
// Enlaces de interés

#include "nfa.h"

NFA::NFA (std::vector<std::string> input) {
  // en cada componente del vector hay una linea del fichero
  // la primera linea es el alfabeto
  // la siguiente es el numero de estados
  // la sifuiente es el estado inicial
  // las siguientes son los estados
  std::string auxiliar;
  std::vector<std::string> auxiliar_vect;
  for (unsigned int j{0}; j < input[0].size(); ++j) {
    if (input[0][j] != kSpace) {
      auxiliar += input[0][j];
    } else {
      auxiliar_vect.push_back(auxiliar);
      auxiliar = "";
    }
  }
  auxiliar_vect.push_back(auxiliar); // para el ultimo elemento de la linea
  auxiliar = "";
  alphabet_ = Alphabet(auxiliar_vect); // creamos el alfabeto
  number_states_ = std::stoi(input[1]); // numero de estados
  initial_state_ = input[2]; // estado inicial
  for (int i{0} ; i < number_states_; ++i) {
    states_.push_back(State(input[i+3]));
  }
  SetInitial();
}

const std::vector<State> NFA::GetStates(void) const {
  return states_;
}
void NFA::SetInitial(void) {  // define el estado como inicial (se realiza a la hora de crear el nfa)
  for (int i{0}; i < number_states_; ++i) {
    if (states_[i].GetState() == initial_state_) {
      states_[i].SetInitial();
    }
  }
}
Alphabet NFA::GetAlphabet(void) const {
  return alphabet_;
}
const bool NFA::IsAccepted(Chain chain) const {
  std::set<State> current_states;
  std::set<State> next_states;
  // iteracion 0 (estado inicial)
  for (int i{0}; i < number_states_; ++i) {
    if (states_[i].IsInitial()) {
      current_states.insert(states_[i]);
    }
  }
  for (int i{0}; i < chain.Size(); ++i) {
    for (auto& state : current_states) { // para cada estado en el conjunto de estados actuales
      std::vector<State> auxiliar = state.GetNextStates(chain.GetChain()[i], states_);
      // devuelve un vector con los estados a los que se puede llegar con el simbolo
      for (auto& state : auxiliar) {
        next_states.insert(state); // inserta los estados en el conjunto de estados
      }
    }
    // una vez tenemos los estados a los que se puede llegar con el simbolo, los pasamos a los estados actuales
    current_states = next_states;
    next_states.clear();
  }
  for (auto& state : current_states) {
    if (state.IsFinal()) {
      return true;
    }
  }
  return false;
}