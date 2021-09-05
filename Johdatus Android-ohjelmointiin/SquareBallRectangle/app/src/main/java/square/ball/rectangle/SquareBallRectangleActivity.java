
//  SquareBallRectangleActivity.java Copyright (c) Kari Laitinen

//  http://www.naturalprogramming.com/

//  2013-02-13  File created.
//  2015-12-11  Last modification.

/*  This application displays a square, ball, or rectangle,
    depending on which radio button is pressed.

    The application consists of the following files:

      main/java/square/ball/rectangle/SquareBallRectangleActivity.java
      main/java/square/ball/rectangle/SquareBallRectangleView.java
      main/res/layout/activity_square_ball_rectangle.xml

    To run this program in Android Studio, create a project
    with SquareBallRectangleActivity as its main class, and use the
    package name below.

    Then you have to copy the above-mentioned files to your project.
*/

package square.ball.rectangle;

import android.os.Bundle ;
import android.app.Activity ;
import android.view.* ;

public class SquareBallRectangleActivity extends Activity
{
    SquareBallRectangleView square_ball_rectangle_view ;

    public void onCreate( Bundle savedInstanceState )
    {
        super.onCreate( savedInstanceState ) ;

        setContentView( R.layout.activity_square_ball_rectangle ) ;

        square_ball_rectangle_view = (SquareBallRectangleView)
                findViewById( R.id.square_ball_rectangle_view ) ;
    }

    public void square_shape_selected( View view )
    {
        square_ball_rectangle_view.set_shape_to_draw( "Square" ) ;
    }

    public void ball_shape_selected( View view )
    {
        square_ball_rectangle_view.set_shape_to_draw( "Ball" ) ;
    }

    public void triangle_shape_selected( View view )
    {
        square_ball_rectangle_view.set_shape_to_draw( "Triangle" ) ;
    }
}