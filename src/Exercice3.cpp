#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string ma, string mo ) {
        marque = ma;
        modele = mo;
    }

    void afficherVehicule() const {
        cout << "Marque : " << marque << ", Modele : " << modele << endl;
    }
};


class Thermique : virtual public Vehicule {
protected:
    double consommationCarburant; 

public:
    Thermique(string ma, string mo, double cc = 0.0)
        : Vehicule(ma, mo) {
        consommationCarburant = cc;
    }

    void afficherThermique() const {
        cout << "Consommation carburant : " << consommationCarburant << " L/100km" << endl;
    }
};


class Electrique : virtual public Vehicule {
protected:
    double autonomieBatterie; 

public:
    Electrique(string ma, string mo, double autonomie = 0.0)
        : Vehicule(ma, mo) {
        autonomieBatterie = autonomie;
    }

    void afficherElectrique() const {
        cout << "Autonomie batterie : " << autonomieBatterie << " km" << endl;
    }
};

class Hybride : public Thermique, public Electrique {
public:
    Hybride(string ma, string mo, double cc = 0.0, double autonomie = 0.0)
      
        : Vehicule(ma, mo), Thermique(ma, mo, cc), Electrique(ma, mo, autonomie) {
    }

    void afficherCaracteristiques() const {
        cout << " Vehicule Hybride " << endl;
        afficherVehicule();
        afficherThermique();
        afficherElectrique();
    }
};

int main() {
    Hybride v1("Fiat", "Uno", 5, 60);
    v1.afficherCaracteristiques();

    cout << endl;

    Hybride v2("Nissan", "Kachkay", 4.5, 75);
    v2.afficherCaracteristiques();

    return 0;
}


