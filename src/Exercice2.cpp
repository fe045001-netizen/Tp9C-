#include <iostream>
using namespace std;

class Technicien {
protected:
    double salaireTech;

public:
    Technicien(double s1) {
    	
    	 salaireTech=s1;
    	
	}

    void afficherSalaire() const {
        cout << "Salaire du technicien : " << salaireTech << " DH" << endl;
    }
};

class Comptable {
protected:
    double salaireComp;

public:
    Comptable(double s2)  {
	salaireComp=s2;
	}

    void afficherSalaire() const {
        cout << "Salaire du comptable : " << salaireComp << " DH" << endl;
    }
};


class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(double s1, double s2)
        : Technicien(s1), Comptable(s2) {}

    void afficherTousSalaires() const {
        Technicien::afficherSalaire();  
        Comptable::afficherSalaire();   
    }
    void afficherSalaire() const {
        cout << "Employe Polyvalent possede  :" << endl;
        afficherTousSalaires();
    }
};
int main() {
    EmployePolyvalent e1(5000, 10000);

    e1.afficherTousSalaires();

    e1.afficherSalaire();

    return 0;
}

