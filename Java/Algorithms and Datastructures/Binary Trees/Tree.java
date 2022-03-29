/**
 * class for trees
 * @author Julian Gürtler
 */
public class Tree{

   Tree l;
   Tree r;
   int value;

   /**
    * Constructor without parameter
    */
   public Tree(){

      this(5);

   }

   /**
    * Constroctor with value-parameter
    * @param root
    */
   public Tree(int root){

      this.l = null;
      this.r = null;
      this.value = root;

   }

   /**
    * toString-Method
    * @Override
    */
   public String toString(){

      if(this.l == null && this.r == null){
         return "" + this.value;
      } else if(this.l == null){
         return this.value + "(" + this.r.toString() + ")";
      } else if(this.r == null){
         return "(" + this.l.toString() + ")" + this.value;
      } else{
         return "(" + this.l.toString() + ")" + this.value + "(" + this.r.toString() + ")";
      }

   }

   /**
    * Function for adding new nodes to tree
    * @param t
    */
   public void add(int t){

      if(t <= this.value && this.l == null){
         this.l = new Tree(t);
      } else if(t <= this.value){
         this.l.add(t);
      } else if(t > this.value && this.r == null){
         this.r = new Tree(t);
      } else if(t > this.value){
         this.r.add(t);
      }

   }

   /**
    * Function for getting depth of the tree
    * @return
    */
   public int getDepth(){

      if(this.l == null && this.r == null){
         return 1;
      } else if(this.l == null){
         return this.r.getDepth() + 1;
      } else if(this.r == null){
         return this.l.getDepth() + 1;
      } else{
         if(this.l.getDepth() >= this.r.getDepth()){
            return this.l.getDepth() + 1;
         } else{
            return this.r.getDepth() + 1;
         }
      }

   }

   /**
    * Method for finding out weather a value is in tree or not
    * @param value
    * @return
    */
   public boolean isIn(int value){

      if(this.value == value){
         return true;
      } else{
         if(this.l != null && value < this.value){
            return this.l.isIn(value);
         } else if(this.r != null && value > this.value){
            return this.r.isIn(value);
         }
         return false;
      }

   }

}