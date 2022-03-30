import javax.swing.*;
import java.awt.Color;

public class Heading extends JLabel implements Constants {
   
   public Heading(String heading, int x, int y, int w, int h, Color color){

      super(heading);
      this.setFont(HEADING);
      this.setForeground(color);
      this.setBounds(x, y, w, h);

   }

   public Heading(String heading, int x, int y, int w, int h){

      this(heading, x, y, w, h, BLUE);

   }

}
