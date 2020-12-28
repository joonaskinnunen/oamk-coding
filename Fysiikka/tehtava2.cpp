#include "L3G4200D.h"
#include "mbed.h"

// Tällä ohjelmalla mitataan gyroanturin GY-50 antamaa raakadataa
// joka on kalibroimatonta, mutta se siis antaa tietoa pyörimisnopeudesta.
// Ohjelma on tehty ja testattu MBED Studio 1.3.1 -versiolla 7.12.2020 /
// J.Kaski. Vanhaan ohjelmaversioon verrattuna oli tullut aika paljon muutoksia.
// Tässä uudessa versiossa sarjayhteys aukeaa ihan oletuksena.
// Jos haluat seurata sarjaliikennettä jollain muulla ohjelmalla, esim.
// Arduinon Serial Plotterilla, niin laita ensin MBED Studion sarjayhteys-ikkuna
// kiinni ja vapauta portti toista ohjelmaa varten.
//
// Anturin datasheet luettu 7.12.2020:
// http://pdf1.alldatasheet.com/datasheet-pdf/view/435303/STMICROELECTRONICS/L3G4200D.html
// Huomaa, että datasheetissä dps = degree /second, joka on siis kulmanopeuden
// yksikkö.
//
// NOTE! MBED Studiossa on kirjaston lisääminen: File / Add Library...
// Tämän koodin gyroanturin kirjasto olisi osoitteessa:
// http://os.mbed.com/users/shimniok/code/L3G4200D/
// mutta jostain syystä se ei ainakaan minulla testivaiheessa toimi.
// Ratkaisin ongelman siten, että otin vanhemmalla versiolla asennetun
// kirjastokansion tämän projektin ohjelmakansioon: "L3G4200D". Kansio oli luotu
// Nucleo F3030RE -alustalle. joten se toimii vain sillä. Latasin kansion
// pakattuna Dropboxiin: L3G4200D.7z, josta voi sitä tarvittaessa kokeilla
// kopioimalla sen purettuna samaan paikkaan, kuin missä main.cpp sijaitsee.

Timer timer;

/*
// Jos on tarvetta puskuroida tulostusta, niin tätä voi kokeilla ottaa käyttöön.
// Oli annettu mallina... tarvittaessa tällä varmaan voi säätää
// myös sarjayhteyden nopeutta.
// Toisaalta puskurointi aiheuttaa viivettä liikkeiden tulostukseen, joten
// laitoin tämän osion kommentiksi.
static BufferedSerial serial_port(USBTX, USBRX, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}
*/

L3G4200D gyro(D14, D15);          // Gyron kytkentänavat suluissa
int g[3] = {0, 0, 0};             // Gyro-raakadata x, y, z
float kulma[3] = {0.0, 0.0, 0.0}; // Näitä pitäisi osata laskea harjoituksissa
int tulostusvali = 10;            // Monenko kierroksen välein tulostetaan
int sykli = 0;                    // Apumuuttuja kierrosten laskemiseksi

int main() {

  timer.start();
  timer.reset();
  while (true) {
    sykli = sykli + 1; // Seurataan kierrosten määrää tulostusta varten
    unsigned long aika = timer.read_ms(); // Kierrokseen kulunut aika
    // Jos read_ms vanhentuneena ei enää toimi, testaa
    // toimintoa duration_cast<milliseconds>(elapsed_time()).count();
    // timer.reset(); // Nollataan kello seuraavaa kierrosta varten
    gyro.read(g); // Luetaan gyro-raakadata

    // Vakiotason korjaukset, testaa ja muuta nollat tarpeen mukaan...
    // Kun tulostat raakadataa ja laite on paikallaan, kulmanopeuden ja
    // myös raakadatan pitäisi näyttää nollaa. Jos näin ei ole, vähennä
    // nollapoikkeama pois.
    // Mallissa paikallaan ollessa keskiarvot olivat 15; 3 ja 12 digittiä.
    g[0] = g[0] - 10; // Raakadatan nollakorjaus x, y, z
    g[1] = g[1] - 17;
    g[2] = g[2] + 14;

    // Kalibrointi: Voit toteuttaa sen 2 vaihtoehtoisella tavalla:
    // 1. Etsimällä datasheetistä tiedon, miten digit muutetaan
    // kulmanopeuden yksiköksi dps.
    // 2. Testaamalla omaa skaalauskerrointa Excelissä,
    // eli tehdään tunnettuja edestakaisin-kääntöjä (esim. 90 astetta)
    // ja sovitetaan kerroin Excelissä niin, että laskettu kulmakäyttäytyminen
    // vastaa todellista kääntelykulmaa.

    // Asentokulman laskeminen kalibroinnin jälkeen:
    // Kulmanopeuden numerinen integraali ajan suhteen = asentokulma.
    // Tässä kohtaa olisi sen paikka, eli harjoitellaan Excelissä ja
    // toteutetaan tänne siellä opituilla laskentamenetelmillä.

    // Gyrodatan tulostus (raakadataa; datasheetistä kalibrointi)
    // Myöhemmässä vaiheessa tulostusta muokataan niin, että
    // digittien sijaan tulostetaan kulma-arvot (x, y, z).
    // Muistutan tässä vielä siitä, että sovelluksen kehitysvaiheessa
    // yleensä tarvitaan testivaiheen ohjelmaversio, jolla päästään heti dataan
    // kiinni. Vasta laskentaohjelmilla testatut laskentamenetelmät koodataan
    // itse laitteeseen!
    // Huom! Varsinkin kulman tulostusvaiheessa on hyvä seurailla asentoa
    // nopeasti ja tulostaa asennon päivitys tietyllä "tulostusvälillä".
    if (sykli == tulostusvali) {
      // Aikaleiman tulostus (ms) jos tarvit datan aikaleimalla esim.
      // Excel-laskuja varten.
      //
      // printf("%lu ", aika);
      for (int i = 0; i < 3; i++) {
        kulma[i] = kulma[i] + (g[i] * 70 * 0.001) * (aika * 0.001);
        printf("%i, ", (int)kulma[i]);
        // NOTE! MBED Studio ei tulosta float-lukuja
        // Mikäli tarkkuus int-tyyppisenä ei ole sinulle riittävä,
        // voit kertoa luvun tuhannella ja esim. kulman voit silloin
        // tulostaa milliasteina.
        // Muista myös tsekata, että int-tyypissä riittää lukuavaruus.
        // Tarvittaessa vaihda lukutyyppiä.
      }
      sykli = 0; // Kun tulostusvälin syklit tuli täyteen, tulostetaan ja
                 // nollataan laskuri.
      timer.reset();
      printf("\r\n");
    }
  }
}