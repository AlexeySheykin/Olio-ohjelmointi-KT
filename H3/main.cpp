#include <iostream>
#include <string>
class Chef {
private:
    std::string chefName;
public:
Chef(const std::string& name) : chefName(name) {
std::cout << "Kokki " << chefName << " luotu." << std::endl;
    }

virtual ~Chef() {
std::cout << "Kokki " << chefName << " poistettu." << std::endl;
    }
int makeSalad(int ingredientCount) {
int portions = ingredientCount / 5;
std::cout << "Kokki " << chefName << " teki " << portions
<< " annosta salaattia käyttäen " << ingredientCount << " ainesta." << std::endl;
return portions;
    }
int makeSoup(int ingredientCount) {
int portions = ingredientCount / 3;
 std::cout << "Kokki " << chefName << " teki " << portions
<< " annosta keittoa käyttäen " << ingredientCount << " ainesta." << std::endl;
return portions;
    }
};
class ItalianChef : public Chef {
private:
std::string password;
int makePizza(int flour, int water) {
int possiblePizzas = std::min(flour / 5, water / 5);
std::cout << "ItalianChef teki " << possiblePizzas
 << " pizzaa käyttäen " << flour << " jauhoa ja " << water << " vettä." << std::endl;
 return possiblePizzas;
    }
public:
ItalianChef(const std::string& name) : Chef(name), password("pizza") {
        std::cout << "ItalianChef luotu!" << std::endl;
    }
bool askSecret(const std::string& attempt, int flour, int water) {
if (attempt == password) {
std::cout << "Salasana oikein!" << std::endl;
makePizza(flour, water);
return true;
} else {
std::cout << "Väärä salasana!" << std::endl;
return false;
        }
    }
};
int main() {
ItalianChef italianChef("Giovanni");
italianChef.makeSalad(20);
 italianChef.makeSoup(15);
std::cout << "Kokeillaan väärää salasanaa:" << std::endl;
    italianChef.askSecret("wrongpass", 25, 25);

    std::cout << "\nKokeillaan oikeaa salasanaa:" << std::endl;
    italianChef.askSecret("pizza", 25, 25);

    return 0;
}
