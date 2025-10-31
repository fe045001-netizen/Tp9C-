#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
protected:
    int id;
    string login;

public:
   Utilisateur(int i, string l) {
        id = i;
        login = l;
    }
    void afficherInfos() const {
        cout << "Identifiant : " << id << ", Login : " << login << endl;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int i, string l, string droits)
        : Utilisateur(i, l)  
		 {
        droitsAcces = droits;
    }
    void gererSysteme() const {
        cout << "Administrateur: " << login << " des  droits : "<< droitsAcces << endl;
    }

    
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int i , string l , int niveau) 
       : Utilisateur(i, l)    {        
        niveauModeration = niveau;
    }
    void modererContenu() const {       
	    cout << "Moderateur " << login << " niveau " << niveauModeration << endl;
    }
};

class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int i, string l, string droits, int niveau) 
	    : Utilisateur(i, l),        
          Administrateur(i, l, droits),
          Moderateur(i, l, niveau)
{}

    void afficherProfil() const {
        cout << " Profil Super Utilisateur " << endl;
         afficherInfos();
	     gererSysteme();       
         modererContenu();      
       
    }
     void executerActions() const {
        cout << " SuperUtilisateur exécute " << endl;
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int choix;
    SuperUtilisateur* su = NULL;

    do {
        cout << " Menu en ligne de commande" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Profil Super Utilisateur " << endl;
        cout << "3. Les actions du SuperUtilisateur " << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int id, niveau;
                string login, droits;
                cout << "Entrez l'identifiant : ";
                cin >> id;
                cout << "Entrez le login : ";
                cin >> login;
                cout << "Entrez les droits d'acces : ";
                cin >> droits;
                cout << "Entrez le niveau de moderation : ";
                cin >> niveau;

                delete su;
                su = new SuperUtilisateur(id, login, droits, niveau);
                cout << " SuperUtilisateur est cree !" << endl;
                break;
            }

            case 2:
                if (su != NULL){ 
				      (*su).afficherProfil(); 
				}    
                else {
				cout << " Aucun SuperUtilisateur  !" << endl;
				}
                break;

            case 3:
            	 if (su != NULL){ 
				      (*su).executerActions(); 
				}    
                else {
				cout << "Creez  un SuperUtilisateur   !" << endl;
				}
                break;
               
            case 0:
                cout << " Fin du programme." << endl;
                break;

            default:
                cout << " Choix invalide !" << endl;
        }

    } while (choix != 0);

    delete su;
    return 0;
}

