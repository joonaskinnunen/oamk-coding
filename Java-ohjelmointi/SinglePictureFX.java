import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.geometry.Rectangle2D;
import javafx.scene.shape.* ;
import javafx.scene.input.* ;


public class SinglePictureFX extends Application
{
   public void start( Stage stage )
   {
      Group group_for_imageviews = new Group() ;

      stage.setTitle( "SinglePictureFX.java" ) ;

      Scene scene = new Scene( group_for_imageviews, 960, 744 ) ;

      scene.setFill( Color.ORANGE ) ;


      int brick_position_x  =  0 ;
      int brick_position_y  =  0 ;

      int brick_height  =   28 ;
      int brick_length  =  112 ;
      int gap_between_bricks =  4 ;
      int row_counter = 0 ;

      while ( brick_position_y  <  scene.getHeight() )
      {
         while ( brick_position_x < scene.getWidth() )
         {
            Rectangle new_brick =
                        new Rectangle( brick_position_x, brick_position_y,
                                       brick_length, brick_height ) ;

            new_brick.setFill( Color.FIREBRICK ) ;

            group_for_imageviews.getChildren().add( new_brick ) ;

            brick_position_x = brick_position_x
                             + brick_length + gap_between_bricks ;
         }

         // Now we must prepare to do the next row of bricks.
         // Every second row must start with a half brick.
         row_counter ++ ;

         if ( row_counter % 2 == 1 )
         {
            // This row will start with a half brick.

            brick_position_x = - brick_length / 2 ;
         }
         else
         {
            brick_position_x = 0 ;
         }

         brick_position_y = brick_position_y + brick_height + gap_between_bricks ;

      }
      
      Image picture_to_show = new Image( "gauguin_two_women_on_the_beach_1891.jpg" ) ;

      ImageView natural_size_view = new ImageView( picture_to_show ) ;
      double picture_width = picture_to_show.getWidth();
      double picture_height = picture_to_show.getHeight();
      double scene_width = scene.getWidth();
      double scene_height = scene.getHeight();

      natural_size_view.setX( (scene.getWidth() - picture_width) / 2) ;
      natural_size_view.setY( (scene.getHeight() - picture_height) / 2 ) ;
      
      Rectangle picture_frame = new Rectangle(((int) Math.round(scene_width - picture_width) / 2) -10, ((int) Math.round(scene_height - picture_height) / 2) -10, picture_width + 20, picture_height + 20) ;
      picture_frame.setFill(Color.RED);

      group_for_imageviews.getChildren().addAll( picture_frame, natural_size_view) ;
            
      scene.setOnKeyPressed( ( KeyEvent event ) ->
      {
         KeyCode code_of_last_pressed_key = event.getCode() ;
         if(code_of_last_pressed_key == KeyCode.UP) {
             natural_size_view.setScaleY( natural_size_view.getScaleY() + 0.05 ) ;
             picture_frame.setScaleY( natural_size_view.getScaleY() + 0.05 ) ;
         } else if(code_of_last_pressed_key == KeyCode.DOWN) {
             natural_size_view.setScaleY( natural_size_view.getScaleY() - 0.05 ) ;
             picture_frame.setScaleY( natural_size_view.getScaleY() - 0.05 ) ;
         } else if(code_of_last_pressed_key == KeyCode.LEFT) {
             natural_size_view.setScaleX( natural_size_view.getScaleX() - 0.05 ) ;
             picture_frame.setScaleX( natural_size_view.getScaleX() - 0.05 ) ;
         } else if(code_of_last_pressed_key == KeyCode.RIGHT) {
             natural_size_view.setScaleX( natural_size_view.getScaleX() + 0.05 ) ;
             picture_frame.setScaleX( natural_size_view.getScaleX() + 0.05 ) ;
         }
      } ) ;
      
      scene.setOnKeyReleased( ( KeyEvent event ) ->
      {
         System.out.print( "\n KeyReleased." ) ;
      } ) ;
   
      scene.setOnKeyTyped( ( KeyEvent event ) ->
      {
         System.out.print( "\n KeyTyped.   Character  =  " 
                        +  event.getCharacter() ) ;
      } ) ;
           
      stage.setScene( scene ) ;
      stage.show() ;

   }

   public static void main( String[] command_line_parameters )
   {
      launch( command_line_parameters ) ;
   }
}