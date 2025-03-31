#include "Kompilator.h"

std::string Kompilator::kompiluj(std::string kod) {
  std::vector<Token> tokens = tokenizator(kod);
  Parser parser(tokens);
  std::unique_ptr<Node> root = parser.parse();

  // czyszczenie
  interpreter.czyscWyniki();

  // ast
  interpreter.interpretuj(root.get());

  // print
  const auto& wyniki = interpreter.pobierzWyniki();

  std::string rezultat;

  // dolaczanie print
  if (!wyniki.empty()) {
    rezultat += "\n";
    for (const auto& wynik : wyniki) {
      rezultat += wynik + "\n";
    }
  }

  rezultat += "program wykonany bez bledow";

  return rezultat;
}

std::string Kompilator::kompiluj(std::string kod, std::string flagi) {
  if (flagi == "-t") {
    // sam lexer
    std::vector<Token> tokens = tokenizator(kod);
    std::string result;
    for (const auto &token : tokens) {
      result += token.value + " ";
    }
    return result;
  } else if (flagi == "-p") {
    // wyswietl drzewo ast
    std::vector<Token> tokens = tokenizator(kod);
    Parser parser(tokens);
    std::unique_ptr<Node> root = parser.parse();

    return interpreter.drzewoAst(root.get());
  } else if (flagi == "-i") {
    // interpretacja
    std::vector<Token> tokens = tokenizator(kod);
    Parser parser(tokens);
    std::unique_ptr<Node> root = parser.parse();

    int wynik = interpreter.interpretuj(root.get());
    return "wynik: " + std::to_string(wynik);
  }
  return kompiluj(kod);
}