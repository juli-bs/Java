import javax.swing.*;
import java.awt.Image.*;

public class Image extends JLabel implements Constants {
   
   public Image(String image, int x, int y, int w, int h){

      super(new ImageIcon(new ImageIcon(image).getImage().getScaledInstance(w, h, 1)));
      this.setBounds(x, y, w, h);

   }

}
