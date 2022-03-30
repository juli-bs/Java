import javax.swing.*;

public class Gui extends JFrame implements Constants{

   private JFrame mainFrame;

   private JPanel mainPanel;

   private MenuPanel mainMenuPanel;

   private Heading mainHeading;

   private Image toDoImage;

   private Textfield username;
   private Textfield password;

   public Gui(){

      mainFrame = new JFrame("ToDo");
      mainFrame.setDefaultCloseOperation(EXIT_ON_CLOSE);
      mainFrame.setResizable(false);
      mainFrame.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);

      initMainPanel();

      mainFrame.setVisible(true);
   
   }

   private void initMainPanel(){

      mainPanel = new JPanel();
      mainPanel.setBackground(WHITE);
      mainPanel.setLayout(null);
      mainFrame.add(mainPanel);

      mainHeading = new Heading("ToDo", 200, 100, 300, 100);
      mainPanel.add(mainHeading);

      mainMenuPanel = new MenuPanel(500, 100, 500, 600, 50);
      mainPanel.add(mainMenuPanel);

      toDoImage = new Image("to-do-list.png", 140, 300, 256, 256);
      mainPanel.add(toDoImage);

      username = new Textfield(50, 50, 300, 50);
      mainMenuPanel.add(username);
      password = new Textfield(50, 50, 300, 50);
      mainMenuPanel.add(password);

   }

}