import java.util.*;
public class ToDo{

   public static void main(String args[]){

      Scanner sc = new Scanner(System.in);

      boolean run = true;

      Liste aufgaben = new Liste();
      aufgaben.add("Gregs Tagebuch", "04.02.2022");
      aufgaben.show();
      Liste.help();

      while(run){
         String befehl = sc.nextLine();

         switch(befehl.split(" ")[0]){
            case "add":
               aufgaben.add(befehl.split("add ")[1].split("-")[0], befehl.split("add ")[1].split("-")[1]);
               break;
            case "show":
               aufgaben.show();
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

   ArrayList<String> aufgabenListe = new ArrayList<String>();
   ArrayList<String> datumsListe = new ArrayList<String>();

   public Liste(){

   }

   public void add(String aufgabe, String datum){
      this.aufgabenListe.add(aufgabe);
      this.datumsListe.add(datum);
   }

   public void remove(String aufgabe){

   }

   public void show(){
      System.out.println("\n#################### ToDo ####################\n");
      for(int i = 0; i < this.aufgabenListe.size(); i++) System.out.println(this.aufgabenListe.get(i) + " - " + this.datumsListe.get(i));
      System.out.println("\n");
   }

   public static void help(){
      System.out.println("\nadd + [Aufgabe] + \"-\" + [Datum] - Neue Aufgabe anlegen");
      System.out.println("rem + [Aufgabe]                 - Aufgabe abschliessen");
      System.out.println("show                            - Aufgaben anzeigen lassen");
      System.out.println("help                            - Hilfe");
      System.out.println("exit                            - Verlassen\n");
   }

}