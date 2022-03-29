/**
 * class for sorting-algorithms
 * @author juli-bs
 */

public class Sort{

   /**
    * Bubblesort-Algorithm
    * @param array
    */
   public static void bubblesort(Array a){

      int array [] = a.getArray();
      for(int i = 0; i < array.length; i++){
         for(int j = 0; j < array.length - i - 1; j++){
            if(array[j] > array[j + 1]){
               int save = array[j];
               array[j] = array[j + 1];
               array[j + 1] = save;
            }
         }
      }
      a.setArray(array);

   }

   public static void mergeSort(Array a){

      int array [] = a.getArray();
      mergeSort(array, 0, array.length - 1);

   }

   private static void mergeSort(int [] array, int a, int c){

      

   }

}