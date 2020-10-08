#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class Nisakas
{
private:
public:
        virtual void tulostaTiedot() = 0;
};

class Ihminen : public Nisakas
{
protected:
        int ika_;
        string sukupuoli_;

public:
        string nimi_;
        Ihminen(int ika, string nimi, string sukupuoli) : ika_(ika), nimi_(nimi), sukupuoli_(sukupuoli)
        {
        }

        void tulostaTiedot()
        {
                cout << "Nimi: " << nimi_ << ", Ikä: " << ika_ << ", Sukupuoli: " << sukupuoli_ << "\n";
        }

        void vanheneVuodella()
        {
                ika_++;
        }
};

class Elain : public Nisakas
{
protected:
        string omistaja_;
        string laji_;

public:
        Elain(string omistaja, string laji) : omistaja_(omistaja), laji_(laji)
        {
        }
        void vaihdaOmistaja(string omistaja)
        {
                omistaja_ = omistaja;
        }
};

class Ihmissusi : public Elain, public Ihminen
{
private:
        string silmienVari_;
        int raajojenMaara_;

public:
        Ihmissusi(string silmienVari, int raajojenMaara, string omistaja, string laji, int ika, string nimi, string sukupuoli) : Elain(omistaja, laji), Ihminen(ika, nimi, sukupuoli), silmienVari_(silmienVari), raajojenMaara_(raajojenMaara)
        {
        }
        void tulostaTiedot()
        {
                cout << "Nimi: " << nimi_ << ", Laji: " << laji_ << ", Raajojen määrä: " << raajojenMaara_ << ", Ikä: " << ika_ << ", Sukupuoli: " << sukupuoli_ << ", Silmien väri: " << silmienVari_ << ", Omistaja: " << omistaja_ << "\n";
        }
        void menetaRaaja(int maara)
        {
                if (raajojenMaara_ - maara < 0)
                {
                        cout << "Virheellinen syöte. Ihmissusi ei voi menettää enempää raajoja kuin niitä on.\n";
                }
                else
                {
                        raajojenMaara_ -= maara;
                }
        }
};

int main()

{
        Ihmissusi ihmissusi("verenpunainen", 4, "Jonna", "zombi", 300, "Monster", "Mies");
        ihmissusi.tulostaTiedot();
        Ihminen seppo(35, "Seppo", "Mies");
        Ihminen tiina(22, "Tiina", "Nainen");
        Ihminen taneli(27, "Taneli", "Mies");
        seppo.tulostaTiedot();
        seppo.vanheneVuodella();
        seppo.tulostaTiedot();
        ihmissusi.vaihdaOmistaja("Aku Ankka");
        ihmissusi.tulostaTiedot();
        ihmissusi.menetaRaaja(5);
        ihmissusi.tulostaTiedot();
        ihmissusi.menetaRaaja(2);
        ihmissusi.tulostaTiedot();

        list<Ihminen> ihmiset;

        ihmiset.push_back(seppo);
        ihmiset.push_back(tiina);
        ihmiset.push_back(taneli);

        cout << "Ihmiset lista sisältää ihmiset:\n";
        for (auto it = ihmiset.begin(); it != ihmiset.end(); ++it)
        {
                cout << it->nimi_ << '\n';
        }

        return 0;
}
