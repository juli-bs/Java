import javax.swing.*;
import java.awt.Color;

public class Textfield extends JTextField implements Constants {
   
   public Textfield(int x, int y, int w, int h){

      super();
      this.setBounds(x, y, w, h);
      this.setBackground(WHITE);
      this.setBorder(null);
      this.setFont(TEXTFIELD_FONT);

   }

}
