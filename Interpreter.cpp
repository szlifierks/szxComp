#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::czyscWyniki() {
    wynikiPrint.clear();
}

const std::vector<std::string>& Interpreter::pobierzWyniki() const {
    return wynikiPrint;
}

int Interpreter::interpretuj(const Node* node) {
    if (!node)
        return 0;

    switch (node->getType()) {
    case NodeType::NUM: {
        const NumNode* numNode = dynamic_cast<const NumNode*>(node);
        return numNode->getNum();
    }
    case NodeType::VAR: {
        const VarNode* varNode = dynamic_cast<const VarNode*>(node);
        const std::string& name = varNode->getName();

        if (zmienne.find(name) == zmienne.end()) {
            throw std::runtime_error("niezdefiniowana zmienna: " + name);
        }

        return zmienne[name];
    }
    case NodeType::OP: {
        const OpNode* opNode = dynamic_cast<const OpNode*>(node);
        const std::string& op = opNode->getOp();
        int lewy = interpretuj(opNode->getLeft());
        int prawy = interpretuj(opNode->getRight());

        if (op == "+")
            return lewy + prawy;
        if (op == "-")
            return lewy - prawy;
        if (op == "*")
            return lewy * prawy;
        if (op == "/") {
            if (prawy == 0)
                throw std::runtime_error("dzielenie przez zero");
            return lewy / prawy;
        }

        throw std::runtime_error("nieznany operator: " + op);
    }
    case NodeType::ASG: {
        const AsgNode* asgNode = dynamic_cast<const AsgNode*>(node);
        const std::string& name = asgNode->getName();
        int wartosc = interpretuj(asgNode->getValue());

        zmienne[name] = wartosc;
        return wartosc;
    }
    case NodeType::PRINT: {
        const PrintNode* printNode = dynamic_cast<const PrintNode*>(node);
        int wynik = interpretuj(printNode->getExpression());
        wynikiPrint.push_back(std::to_string(wynik)); // zapisz wynik
        return wynik;
    }
    default:
        throw std::runtime_error("nieznany typ wezla");
    }
}

std::string Interpreter::drzewoAst(const Node* node, int indent, bool ostatni) {
    if (!node)
        return "";

    std::string result;
    std::string wciecie;

    for (int i = 0; i < indent; i++)
        wciecie += (i == indent - 1) ? (ostatni ? "`---" : "|---") : "|   ";

    switch (node->getType()) {
    case NodeType::NUM: {
        const NumNode* numNode = dynamic_cast<const NumNode*>(node);
        result += wciecie + "+----------+\n";
        std::string napis = "|  NUM: " + std::to_string(numNode->getNum());
        std::string wypelnienie(16 - napis.length(), ' ');
        result += wciecie + napis + wypelnienie + "|\n";
        result += wciecie + "+----------+\n";
        break;
    }
    case NodeType::VAR: {
        const VarNode* varNode = dynamic_cast<const VarNode*>(node);
        result += wciecie + "+----------+\n";
        std::string napis = "|  VAR: " + varNode->getName();
        std::string wypelnienie(16 - napis.length(), ' ');
        result += wciecie + napis + wypelnienie + "|\n";
        result += wciecie + "+----------+\n";
        break;
    }
    case NodeType::OP: {
        const OpNode* opNode = dynamic_cast<const OpNode*>(node);
        result += wciecie + "+----------+\n";
        std::string napis = "|   OP: " + opNode->getOp();
        std::string wypelnienie(16 - napis.length(), ' ');
        result += wciecie + napis + wypelnienie + "|\n";
        result += wciecie + "+----------+\n";

        std::string linia = (ostatni) ? " " : "|";
        result += wciecie.substr(0, wciecie.length() - 4) + linia + "\n";

        result += drzewoAst(opNode->getLeft(), indent + 1, false);
        result += wciecie.substr(0, wciecie.length() - 4) + linia + "\n";
        result += drzewoAst(opNode->getRight(), indent + 1, true);
        break;
    }
    case NodeType::ASG: {
        const AsgNode* asgNode = dynamic_cast<const AsgNode*>(node);
        result += wciecie + "+--------------------+\n";
        std::string napis = "|  PRZYPISANIE: " + asgNode->getName();
        std::string wypelnienie(22 - napis.length(), ' ');
        result += wciecie + napis + wypelnienie + "|\n";
        result += wciecie + "+--------------------+\n";

        std::string linia = (ostatni) ? " " : "|";
        result += wciecie.substr(0, wciecie.length() - 4) + linia + "\n";
        result += drzewoAst(asgNode->getValue(), indent + 1, true);
        break;
    }
    case NodeType::PRINT: {
        const PrintNode* printNode = dynamic_cast<const PrintNode*>(node);
        result += wciecie + "+----------+\n";
        result += wciecie + "|  PRINT    |\n";
        result += wciecie + "+----------+\n";

        std::string linia = (ostatni) ? " " : "|";
        result += wciecie.substr(0, wciecie.length() - 4) + linia + "\n";
        result += drzewoAst(printNode->getExpression(), indent + 1, true);
        break;
    }
    }

    return result;
}