/**
 * class for non-sorted array-Objects
 * @author juli-bs
 */
public class Array{

   private int length;
   private int array [];
   private int compareArray [];

   /**
    * Constructor for array-elements of a specific size
    * @param length
    */
   public Array(int length){

      this.length = length;
      this.compareArray = new int [length];
      initCompareArray();
      this.array = new int [length];
      initRandomArray();

   }

   /**
    * Method for initializing a compare array to make it easier to initialize a non-sorted array
    */
   private void initCompareArray(){

      for(int i = 0; i < this.length; i++){
         this.compareArray[i] = i + 1;
      }

   }

   /**
    * Method for initializing a non-sorted array
    */
   private void initRandomArray(){

      int randomNumber = 0;
      for(int i = 0; i < this.length; i++){
         do{
            randomNumber = (int)(Math.random() * this.length);
         } while(this.compareArray[randomNumber] == 0);
         this.array[i] = this.compareArray[randomNumber];
         this.compareArray[randomNumber] = 0;
      }

   }

   /**
    * toString-Method
    * @Override
    */
   public String toString(){

      String returnString = "";
      for(int i = 0; i < this.length - 1; i++){
         returnString += this.array[i] + " ";
      }
      returnString += this.array[this.length - 1];
      return returnString;

   }

   public int[] getArray(){
      return this.array;
   }

   public void setArray(int newArray[]){
      this.array = newArray;
   }

}