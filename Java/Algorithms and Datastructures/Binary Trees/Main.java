/**
 * Main-Class for initializing a binary tree
 * @author Julian Gürtler
 */
public class Main{

   /**
    * main-function
    * @param args
    */
   public static void main(String args []){

      Tree tree = new Tree(5);
      System.out.println(tree.toString());
      System.out.println("Depth: " + tree.getDepth());
      if(tree.isIn(7)){
         System.out.println(7 + " is in");
      } else{
         System.out.println(7 + " is not in");
      }
      tree.add(2);
      tree.add(4);
      tree.add(5);
      tree.add(7);

      System.out.println("\nAdded...\n");

      System.out.println(tree.toString());
      System.out.println("Depth: " + tree.getDepth());
      if(tree.isIn(7)){
         System.out.println(7 + " is in");
      } else{
         System.out.println(7 + " is not in");
      }

   }

}