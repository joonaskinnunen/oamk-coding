import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.scene.text.Text ;
import javafx.stage.Stage; 
import javafx.scene.shape.* ;
import javafx.scene.paint.Color;


public class StepsFX extends Application
{
   public void start( Stage stage )
   {
      stage.setTitle( "StepsFX.java" ) ;

      Group group_for_steps = new Group() ;

      Scene scene = new Scene( group_for_steps, 680, 480 ) ;

      int step_size = 40 ;
      int number_of_steps_to_make = 7 ;

      int step_position_x = 60 ;
      int step_position_y = 320 ;

      for ( int step_counter = 0 ;
                step_counter < number_of_steps_to_make ;
                step_counter ++ )
      {
         Rectangle new_step = new Rectangle(
                     step_position_x,
                     step_position_y,
                     ( number_of_steps_to_make - step_counter ) * step_size,
                     step_size ) ;
         Color[] step_colors = { Color.DARKKHAKI, Color.AQUAMARINE, Color.LIGHTBLUE,
         Color.KHAKI, Color.ORANGE, Color.ROSYBROWN,
         Color.THISTLE, Color.TOMATO } ;

         new_step.setFill( step_colors[step_counter] ) ;
         new_step.setStroke( Color.CHOCOLATE ) ;
         new_step.setStrokeWidth( 4 ) ;

         group_for_steps.getChildren().add( new_step ) ;

         step_position_y = step_position_y - step_size ;
      }

      step_position_x = 660 ;
      step_position_y =  80 ;


      for ( int step_counter = 0 ;
                step_counter < number_of_steps_to_make ;
                step_counter ++ )
      {
         Line horizontal_line = new Line( step_position_x,
                                          step_position_y,
                                          step_position_x - step_size,
                                          step_position_y ) ;

         horizontal_line.setStroke( Color.CHOCOLATE ) ;
         horizontal_line.setStrokeWidth( 4 ) ;

         step_position_x = step_position_x - step_size ;

         Line vertical_line = new Line( step_position_x,
                                        step_position_y,
                                        step_position_x,
                                        step_position_y + step_size ) ;

         vertical_line.setStroke( Color.CHOCOLATE ) ;
         vertical_line.setStrokeWidth( 4 ) ;

         step_position_y = step_position_y + step_size ;

         group_for_steps.getChildren().addAll( horizontal_line, vertical_line ) ;
      }

      stage.setScene( scene ) ;
      stage.show();
   }


   public static void main( String[] command_line_parameters )
   {
      launch( command_line_parameters ) ;
   }
}