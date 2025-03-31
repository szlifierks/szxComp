#include "Parser.h"

#include "SeqNode.h"

std::unique_ptr<Node> Parser::parse() {
  auto seq = std::make_unique<SeqNode>();

  while (idx < tokens.size()) {
    auto instrukcja = parseLine();

    if (instrukcja) {
      seq -> dodajInstr(std::move(instrukcja));
    }

    //jak skoncza sie tokeny
    if (idx >= tokens.size()) {
      break;
    }
  }

  return seq;
}

std::unique_ptr<Node> Parser::parseLine() {
  // obsluga let
  if (idx < tokens.size() && tokens[idx].type == TokenType::SLOWOK &&
      tokens[idx].value == "let") {
    idx++; // przejdz po let

    if (idx < tokens.size() && tokens[idx].type == TokenType::NAZWA) {
      std::string varName = tokens[idx].value;
      idx++; // przejdz po nazwie

      if (idx < tokens.size() && tokens[idx].type == TokenType::OPERATOR &&
          tokens[idx].value == "=") {
        idx++; // przejdz =

        auto expr = parseOp();

        if (idx < tokens.size() && tokens[idx].type == TokenType::END) {
          idx++; // przejdz ;
          return std::make_unique<AsgNode>(varName, std::move(expr));
        }
          }
    }
    throw std::runtime_error("Błąd składni przy przypisaniu");
      }

  // print
  if (idx < tokens.size() && tokens[idx].type == TokenType::SLOWOK &&
    tokens[idx].value == "print") {
    idx++; // po print

    if (idx < tokens.size() && tokens[idx].type == TokenType::NAWIAS &&
        tokens[idx].value == "(") {
      idx++; // (

      auto expr = parseOp();

      if (idx < tokens.size() && tokens[idx].type == TokenType::NAWIAS &&
          tokens[idx].value == ")") {
        idx++; // )

        if (idx < tokens.size() && tokens[idx].type == TokenType::END) {
          idx++; // ;
          return std::make_unique<PrintNode>(std::move(expr));
        }
          }
        }
    throw std::runtime_error("blad skladni przy print");
    }

  return parseOp();
}

std::unique_ptr<Node> Parser::parseOp() {
  auto left = parseNum();

  while (idx < tokens.size() && tokens[idx].type == TokenType::OPERATOR &&
         (tokens[idx].value == "+" || tokens[idx].value == "-" ||
          tokens[idx].value == "*" || tokens[idx].value == "/")) {
    std::string op = tokens[idx].value;
    idx++; // operator

    auto right = parseNum();
    left = std::make_unique<OpNode>(op, std::move(left), std::move(right));
  }

  return left;
}

std::unique_ptr<Node> Parser::parseNum() {
  if (idx < tokens.size()) {
    if (tokens[idx].type == TokenType::NUMER) {
      int value = std::stoi(tokens[idx].value);
      idx++; // liczba
      return std::make_unique<NumNode>(value);
    } else if (tokens[idx].type == TokenType::NAZWA) {
      std::string name = tokens[idx].value;
      idx++; // nazwa
      return std::make_unique<VarNode>(name);
    } else if (tokens[idx].type == TokenType::NAWIAS &&
               tokens[idx].value == "(") {
      idx++; // (
      auto expr = parseOp();

      if (idx < tokens.size() && tokens[idx].type == TokenType::NAWIAS &&
          tokens[idx].value == ")") {
        idx++; // )
        return expr;
      }
      throw std::runtime_error("brak ')'");
    }
  }

  throw std::runtime_error("nieprawidlowe wyrazenie");
}
