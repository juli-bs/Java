import java.util.*;

public class Spielfeld {
   
   final static int SIZE = 8;
   static String spielfeld [][] = {
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "}
   };

   public static void zug(int spalte, String zeichen){
      if(spalte < 1 || spalte > SIZE){
         System.out.println("\nBitte gib einen Wert zwischen 1 und 8 ein\n");
      } else{
         spalte--;
         if(hoehe(spalte) != 100){
            spielfeld[hoehe(spalte)][spalte] = zeichen;
            show();
         } else{
            System.out.println("\nBitte waehle eine andere Spalte\n");
         }
      }
   }

   public static void show(){
      System.out.println();
      for(int i = 0; i < spielfeld.length; i++){
         System.out.println(Arrays.toString(spielfeld[i]));
      }
      System.out.print(" ");
      for(int i = 0; i < SIZE; i++){
         System.out.print(i + 1 + "  ");
      }
      System.out.println();
   }

   public static int hoehe(int spalte){
      int height = SIZE - 1;

      while(!spielfeld[height][spalte].equals(" ")){
         if(height > 0){
            height--;
         } else{
            return 100;
         }
      }

      return height;
   }

   public static boolean check(){
      String sieger = "";
      sieger = checkHorizontal();
      if(!sieger.equals("")){
         System.out.println(sieger + " hat gewonnen!\n");
         return true;
      }
      sieger = checkVertical();
      if(!sieger.equals("")){
         System.out.println(sieger + " hat gewonnen!\n");
         return true;
      }
      return false;
   }

   public static String checkHorizontal(){
      int anzahl = 1;
      for(int i = 0; i < spielfeld.length; i++){
         for(int j = 0; j < spielfeld[i].length - 1; j++){
            if(!spielfeld[i][j].equals(" ") && spielfeld[i][j].equals(spielfeld[i][j + 1])){
               anzahl++;
               if(anzahl == 4){
                  return spielfeld[i][j];
               }
            } else{
               anzahl = 1;
            }
         }
      }
      return "";
   }

   public static String checkVertical(){
      int anzahl = 1;
      for(int i = 0; i < spielfeld[0].length; i++){
         for(int j = 0; j < spielfeld.length - 1; j++){
            if(!spielfeld[j][i].equals(" ") && spielfeld[j][i].equals(spielfeld[j + 1][i])){
               anzahl++;
               if(anzahl == 4){
                  return spielfeld[j][i];
               }
            } else{
               anzahl = 1;
            }
         }
      }
      return "";
   }

   public static String checkDiagonal(){
      int anzahl = 1;
      
      return "";
   }

}
