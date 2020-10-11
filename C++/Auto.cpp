#include<iostream>
using namespace std;

class Ajoneuvo
{
public:
  Ajoneuvo(int ajetut, int paino, string merkki, string malli);

protected:
  void Liikuta(int km);
  int PalautaAjetut();
  int PalautaPaino();
  string PalautaMerkki();
  string PalautaMalli();
  
private:
  int ajetut_;
  int paino_;
  string merkki_;
  string malli_;
};

Ajoneuvo::Ajoneuvo(int ajetut, int paino, string merkki, string malli) : ajetut_(ajetut), paino_(paino), 
merkki_(merkki), malli_(malli)
{
}

void Ajoneuvo::Liikuta(int km)
{ ajetut_ = ajetut_ + km; }

int Ajoneuvo::PalautaAjetut()
{ return ajetut_; }

int Ajoneuvo::PalautaPaino()
{ return paino_; }

string Ajoneuvo::PalautaMerkki()
{ return merkki_; }

string Ajoneuvo::PalautaMalli()
{ return malli_; }




class Auto : public Ajoneuvo {
	private:
		string rekisteri_nro_;
		int matkustajat_max_;
	public:
		Auto(int ajetut, int paino, string merkki, string malli, string rekisteri_nro_,
		int matkustajat_max_);
		void TulostaAutonTiedot();
		void AjaAutoa(int km);
		
};

Auto::Auto(int ajetut, int paino, string merkki, string malli, string rekisteri_nro, int matkustajat_max):
Ajoneuvo(ajetut, paino, merkki, malli), rekisteri_nro_(rekisteri_nro), matkustajat_max_(matkustajat_max) {}

void Auto::TulostaAutonTiedot() {
	cout << "Merkki: " << PalautaMerkki() << "\n";
	cout << "Malli: " << PalautaMalli() << "\n";
	cout << "Paino: " << PalautaPaino() << "\n";
	cout << "Ajetut kilometrit: " << PalautaAjetut() << "\n";
	cout << "Rekisterinumero: " << rekisteri_nro_ << "\n";
	cout << "Maksimi matkustajien määrä: " << matkustajat_max_ << "\n\n";
}

void Auto::AjaAutoa(int km) {
	Liikuta(km);
	cout << "Autolla ajettu " << km << " kilometriä.\n\n";
}

int main() {
    Auto pirssi(250000, 1700, "Toyota", "Carina II", "TFM-257", 5);
    pirssi.TulostaAutonTiedot();
    pirssi.AjaAutoa(25000);
    pirssi.TulostaAutonTiedot();
    return 0;
}