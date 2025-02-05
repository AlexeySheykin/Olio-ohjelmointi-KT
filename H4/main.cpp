#include <iostream>
#include <string>
class Pankkitili {
protected:
double saldo;
public:
Pankkitili() : saldo(0.0) {}
virtual bool deposit(double amount) {
if (amount > 0) {
saldo += amount;
return true;
}
return false;
}
virtual bool withdraw(double amount) {
if (amount > 0 && amount <= saldo) {
saldo -= amount;
return true;
}
return false;
}
double getBalance() const {
return saldo;
}
virtual ~Pankkitili() = default;
};
class Luottotili : public Pankkitili {
private:
double luottoraja;

public:
Luottotili(double raja) : luottoraja(raja) {}
bool withdraw(double amount) override {
if (amount > 0 && (saldo - amount) >= -luottoraja) {
saldo -= amount;
return true;
}
return false;
}
bool payCredit(double amount) {
if (amount > 0 && saldo + amount <= 0) {
saldo += amount;
return true;
}
return false;
}
};
class Asiakas {
private:
    std::string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;
public:
Asiakas(const std::string& nimi, double luottoraja)
        : nimi(nimi), luottotili(luottoraja) {}
void showSaldo() const {
        std::cout << "Asiakas: " << nimi << "\n";
        std::cout << "Pankkitilin saldo: " << pankkitili.getBalance() << " EUR\n";
        std::cout << "Luottotilin saldo: " << luottotili.getBalance() << " EUR\n";
}
bool talletus(double amount) {
return pankkitili.deposit(amount);
}
bool nosto(double amount) {
return pankkitili.withdraw(amount);
}
bool luotonNosto(double amount) {
return luottotili.withdraw(amount);
}
bool luotonMaksu(double amount) {
return luottotili.payCredit(amount);
}
bool tiliSiirto(double amount, Asiakas& vastaanottaja) {
if (amount > 0 && pankkitili.withdraw(amount)) {
return vastaanottaja.talletus(amount);
}
return false;
}
};
int main() {
    Asiakas asiakas1("Matti Meikäläinen", 500);
    Asiakas asiakas2("Maija Meikäläinen", 300);

    asiakas1.talletus(1000);
    asiakas1.nosto(200);
    asiakas1.luotonNosto(100);

    asiakas2.talletus(500);
    asiakas2.luotonNosto(150);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    std::cout << "\nTilisiirto 300 EUR asiakas1 -> asiakas2...\n";
    if (asiakas1.tiliSiirto(300, asiakas2)) {
        std::cout << "Tilisiirto onnistui.\n";
    } else {
        std::cout << "Tilisiirto epäonnistui.\n";
    }
asiakas1.showSaldo();
asiakas2.showSaldo();
return 0;
}
