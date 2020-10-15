#include<iostream>
#include <string>
using namespace std;

class Kortti
{
public:
  int KerroMaa();
  int KerroArvo();
  void AlustaKortti(int maa, int arvo);
  Kortti();
private:
  int maa_;   // 1=hertta, 2=ruutu, 3=pata, 4=risti
  int arvo_;
};

Kortti::Kortti() : maa_(0), arvo_(0)
{
}

int Kortti::KerroMaa()
{
  return maa_;
}

int Kortti::KerroArvo()
{
  return arvo_;
}

void Kortti::AlustaKortti(int maa, int arvo)
{
  maa_ = maa;
  arvo_ = arvo;
}




class KorttiPakka {
	public:
		KorttiPakka();
		void TulostaKortti(int jnro);
		
	
	private:
		Kortti kortit_[52];
};

KorttiPakka::KorttiPakka() {
	int index = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j < 14; j++) {
			kortit_[index].AlustaKortti(i, j);
			index++;
		}
	}
}

void KorttiPakka::TulostaKortti(int jnro) {
	string maat[4] = {"Hertta", "Ruutu", "Pata", "Risti"};
	string maa = maat[kortit_[jnro].KerroMaa()];
	cout << maa << " " << kortit_[jnro].KerroArvo() << "\n";
}

int main() {
    int jnro;
    KorttiPakka pakka;
    pakka.TulostaKortti(0);
    pakka.TulostaKortti(20);
}

