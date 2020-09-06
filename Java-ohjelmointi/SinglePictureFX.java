import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.geometry.Rectangle2D;


public class SinglePictureFX extends Application
{
   public void start( Stage stage )
   {
      Group group_for_imageviews = new Group() ;

      stage.setTitle( "SinglePictureFX.java" ) ;

      Scene scene = new Scene( group_for_imageviews, 960, 744 ) ;

      scene.setFill( Color.LIGHTYELLOW ) ;

      Image picture_to_show = new Image( "gauguin_two_women_on_the_beach_1891.jpg" ) ;

      ImageView natural_size_view = new ImageView( picture_to_show ) ;

      natural_size_view.setX( (scene.getWidth() - picture_to_show.getWidth()) / 2) ;
      natural_size_view.setY( (scene.getHeight() - picture_to_show.getHeight()) / 2 ) ;

      group_for_imageviews.getChildren().add( natural_size_view) ;
           
      stage.setScene( scene ) ;
      stage.show() ;

   }

   public static void main( String[] command_line_parameters )
   {
      launch( command_line_parameters ) ;
   }
}