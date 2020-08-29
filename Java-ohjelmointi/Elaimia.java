package elaimia;

class  Elain
{
   String elaimen_nimi;
   String  lajin_nimi ;
   String[] vatsan_sisalto = new String[ 30 ] ;   
   int ruokintojen_maara = 0 ; 
   
   public Elain() {
       lajin_nimi = "oletuselain";
       elaimen_nimi = "nimeton elain";
       
   }

   public Elain( String  annettu_lajin_nimi, String annettu_elaimen_nimi ) 
   {
      lajin_nimi      =  annettu_lajin_nimi ;
      elaimen_nimi    = annettu_elaimen_nimi;
   }

   public Elain( Elain  toinen_elain )
   {
      lajin_nimi      =  toinen_elain.lajin_nimi ;
      vatsan_sisalto  =  toinen_elain.vatsan_sisalto ;
      elaimen_nimi    =  toinen_elain.elaimen_nimi;
   }

   public void ruoki( String ruokaa_talle_elaimelle )
   {
      vatsan_sisalto[ruokintojen_maara] = ruokaa_talle_elaimelle;
      ruokintojen_maara++;
   }
   
   public void tyhjenna_vatsa() {
       vatsan_sisalto = new String[ 30 ];
       ruokintojen_maara = 0;
   }

   public void anna_puhua()
   {
      System.out.print( "\nHei. Mina olen " + lajin_nimi     + " nimeltä " + elaimen_nimi + ".\n");
      if(ruokintojen_maara == 0) {
         System.out.print("Vatsani on tyhjä.\n");
      } else {
          System.out.print("Olen syönyt: ");
          for(int i = 0; i < ruokintojen_maara; i++) {
             if(i > 0) System.out.print(", ");
             System.out.print(vatsan_sisalto[i]);
          }
          System.out.print(".\n");
      }
   }
}

class Elaintarha {
   Elain[] tarhan_elaimet = new Elain[ 20 ] ;
   int elaimia_tarhassa = 0 ;
    
   public void lisaa_elain( Elain uusi_elain_tarhaan ) {
      tarhan_elaimet[elaimia_tarhassa] = uusi_elain_tarhaan;
      elaimia_tarhassa++;
     }
   public void anna_elainten_puhua() {
      for(int i = 0; i < elaimia_tarhassa; i++) {
         tarhan_elaimet[i].anna_puhua();
      }
   }
}

class Petoelain extends Elain {
   public  Petoelain(
      String elaimen_nimi, String lajin_nimi
   )
   {
      super(elaimen_nimi, lajin_nimi);
   }

   public void ruoki( Elain syotava_elain ) {
      vatsan_sisalto[ruokintojen_maara] = syotava_elain.lajin_nimi;
      ruokintojen_maara++;
   }
}

class  Elaimia
{
   public static void main( String[] ei_kaytossa )
   {
      Elain  kissaolio  =  new Elain( "kissa", "Miuku" ) ;
      Elain  koiraolio  =  new Elain( "vegaani koira", "Hauva" ) ;

      kissaolio.ruoki( "kalaa" ) ;
      kissaolio.ruoki( "kalkkunaa" ) ;

      koiraolio.ruoki( "salaattia" ) ;
      koiraolio.ruoki( "perunoita" ) ;
      koiraolio.tyhjenna_vatsa();

      Elain  toinen_kissa  =  new Elain( kissaolio ) ;

      toinen_kissa.ruoki( "maitoa" ) ;
      Petoelain tiikeri = new Petoelain( "tiikeri", "tikru" ) ;
      Elain nauta = new Elain( "Lehmä", "Ammuu" ) ;
      tiikeri.ruoki( nauta ) ;
      tiikeri.anna_puhua();

      Elaintarha testitarha = new Elaintarha() ;
      testitarha.lisaa_elain( kissaolio ) ;
      testitarha.lisaa_elain( kissaolio ) ;
      testitarha.lisaa_elain( koiraolio ) ;
      testitarha.lisaa_elain( toinen_kissa ) ;
      testitarha.anna_elainten_puhua() ;
   }
}


