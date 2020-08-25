import java.util.* ;

class Lampo
{
   public static void tulosta_lampotilataulukko() {
      for(int i = 0; i <= 100; i += 10) {
         System.out.println(i + "°F = " + (i - 32) / 1.8 + "°C");
      }
   }
   public static void main( String args[] )
   {
      Scanner nappaimisto = new Scanner( System.in );
      double asteet;

      System.out.print( "\n Syota astemaara: " );
      asteet  =  Double.parseDouble(nappaimisto.nextLine());
      if(asteet == 0) {
         tulosta_lampotilataulukko();
      } else {
         System.out.println( "\n" + asteet + " Celsius-astetta on " +  (asteet * 1.8 + 32) + " Fahrenheit-astetta");
         System.out.println( "\n" + asteet + " Fahrenheit-astetta on " +  ((asteet - 32) / 1.8) + " Celcius-astetta");
         nappaimisto.close();
      }
   }
}