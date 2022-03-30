import java.awt.*;
import javax.swing.*;

public class MenuPanel extends JPanel implements Constants {

   protected int strokeSize = 0;
   
   protected Color shadowColor = Color.black;
   
   protected boolean shady = false;
   
   protected boolean highQuality = true;
   
   protected Dimension arcs = new Dimension(30, 30);
   
   protected int shadowGap = 3;
   
   protected int shadowOffset = 4;
   
   protected int shadowAlpha = 50;

   public MenuPanel(int x, int y, int w, int h) {

      super();
      setOpaque(false);
      this.setBounds(x, y, w, h);
      this.setLayout(null);
      this.setBackground(BLUE);

   }

   public MenuPanel(int x, int y, int w, int h, int r){
      this(x, y, w, h);
      arcs = new Dimension(r, r);
   }

   @Override
   protected void paintComponent(Graphics g) {

      super.paintComponent(g);
      int width = getWidth();
      int height = getHeight();
      int shadowGap = this.shadowGap;
      Color shadowColorA = new Color(shadowColor.getRed(), shadowColor.getGreen(), shadowColor.getBlue(), shadowAlpha);
      Graphics2D graphics = (Graphics2D) g;

      if (highQuality) {
         graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      }

      if (shady) {
         graphics.setColor(shadowColorA);
         graphics.fillRoundRect(shadowOffset, shadowOffset, width - strokeSize - shadowOffset, height - strokeSize - shadowOffset, arcs.width, arcs.height);
       } else {
           shadowGap = 1;
       }

       graphics.setColor(getBackground());
       graphics.fillRoundRect(0, 0, width - shadowGap,
       height - shadowGap, arcs.width, arcs.height);
       graphics.setColor(getForeground());
       graphics.setStroke(new BasicStroke(strokeSize));
       graphics.drawRoundRect(0, 0, width - shadowGap,
       height - shadowGap, arcs.width, arcs.height);

       graphics.setStroke(new BasicStroke());
   }
} 