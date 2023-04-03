template<typename T>

class Propriete {
    public :
        void changer(Sommet n, const T &val);
        void changer(Arete e, const T &val);
        const T & valeur(Sommet n) const;
        const T & valeur(Arete e) const;
        void supprimer(Sommet n);
        void supprimer(Arete e);

    private :  //ce n'est pas nécessairement privé
        T monAttributGenerique;
};