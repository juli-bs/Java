import java.util.*;
public class ToDo{

   public static void main(String args[]){

      Scanner sc = new Scanner(System.in);

      boolean run = true;

      Liste aufgaben = new Liste();
      aufgaben.add("Gregs Tagebuch", "04.02.2021");
      aufgaben.show();
      Liste.help();

      while(run){
         String befehl = sc.nextLine();

         switch(befehl.split(" ")[0]){
            case "new":
               //aufgaben.add();
               break;
            case "help":
               Liste.help();
               break;
            case "exit":
               run = false;
               break;
            default:
               System.out.println("Schreibe help um die gueltigen Befehle zu sehen");
               break;
         }
      }

   }

}

class Liste{

   int listenLaenge = 0;
   @SuppressWarnings("unchecked")
   ArrayList<String>[][] aufgabenListe = new ArrayList[listenLaenge + 1][2];

   public Liste(){

   }

   public void add(String aufgabe, String datum){
      this.aufgabenListe[listenLaenge][0].add(aufgabe);
      this.aufgabenListe[listenLaenge++][1].add(datum);
   }

   public void remove(String aufgabe){

   }

   public void show(){
      System.out.println("\n#################### ToDo ####################\n");
      for(int i = 0; i < this.listenLaenge; i++) System.out.println(this.aufgabenListe[i][0] + " - " + this.aufgabenListe[i][1]);
      System.out.println("\n");
   }

   public static void help(){
      System.out.println("\nnew + [Aufgabe] + \"-\" + [Datum] - Neue Aufgabe anlegen");
      System.out.println("rem + [Aufgabe]                 - Aufgabe abschliessen");
      System.out.println("help                            - Hilfe");
      System.out.println("exit                            - Verlassen\n");
   }

}