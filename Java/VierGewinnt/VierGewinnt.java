import java.util.*;

public class VierGewinnt{

   static Scanner sc = new Scanner(System.in);
   static int mode = 1;

   public static void main(String[] args){


      System.out.println("\n################################");
      System.out.println("\nWie viele Spieler spielen mit?\n");
      int spielerAnzahl = Integer.parseInt(sc.nextLine());

      boolean menuWahl = true;
      while(menuWahl){
         if(spielerAnzahl == 1){
            menuWahl = false;
            schleifeEinzelspieler();
         } else if(spielerAnzahl == 2){
            menuWahl = false;
            schleifeMehrspieler();
         } else{
            System.out.println("Es koennen nur 1 oder 2 Spieler spielen");
            System.out.println("\nWie viele Spieler spielen mit?\n");
            spielerAnzahl = Integer.parseInt(sc.nextLine());
         }
      }
   }

   public static void schleifeEinzelspieler(){
      System.out.println("\nHallo! Waehle deinen Spielzug (oder schreibe help bei Fragen):\n");
      boolean run = true;
      while(run){
         String befehl = sc.nextLine();
         switch(befehl.split(" ")[0]){
            case "show":
               Spielfeld.show();
               System.out.println();
               break;
            case "put":
               int spalte;
               try{
                  spalte = Integer.parseInt(befehl.split(" ")[1]);
               } catch(Exception e){
                  System.out.println("\nBitte schreibe hinter \"put\" die Spaltennummer\n");
                  break;
               }
               if(spalte < 1 || spalte > 8){
                  System.out.println("\nBitte waehle eine Spalte zwischen 1 und 8\n");
               } else if(spalte == 100){
                  System.out.println("\nBitte waehle eine andere Spalte\n");
               } else{
                  Spielfeld.zug(Integer.parseInt(befehl.split(" ")[1]), "#");
                  System.out.println();
                  mode *= -1;
               }
               break;
            case "help":
               help();
               break;
            case "exit":
               run = false;
               break;
            default:
               System.out.println("\nUngueltiger Befehl. Schreibe help, um dir die möglichen Befehle anzuzueigen\n");
               break;
         }
         if(Spielfeld.check()){
            run = false;
         }
         if(mode == -1 && run == true){
            computer();
            mode *= -1;
         }
      }
   }

   public static void schleifeMehrspieler(){

   }

   public static void help(){
      System.out.println("\nshow - Zeigt das aktuelle Spielfeld an");
      System.out.println("put  - Spielzug");
      System.out.println("exit - Verlasse das Spiel\n");
   }

   public static void computer(){
      int zufallszahl;
      do{
         zufallszahl = (int)(Math.random() * Spielfeld.SIZE);
      } while(Spielfeld.hoehe(zufallszahl) == 100);
      Spielfeld.zug(zufallszahl + 1, "@");
   }

}

// TODO: Mehrspielerschleife