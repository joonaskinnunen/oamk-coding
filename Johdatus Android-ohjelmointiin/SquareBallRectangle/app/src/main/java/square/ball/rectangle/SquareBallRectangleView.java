
//  SquareBallRectangleView.java by Kari Laitinen

//  http://www.naturalprogramming.com/

//  2013-02-13  File created.
//  2019-01-14  Last modification.


package square.ball.rectangle ;

import android.graphics.* ;
import android.view.* ;
import android.content.Context ;
import android.util.AttributeSet ;

public class SquareBallRectangleView extends View
{
    int view_center_point_x = 100 ;
    int view_center_point_y = 100 ;

    String shape_to_draw = "Square" ;

    public SquareBallRectangleView( Context context )
    {
        super( context ) ;
    }

    //  The following constructor is needed when SquareBallRectangleView object is
    //  specified in an XML file, and is thus created automatically.

    public SquareBallRectangleView( Context context, AttributeSet attributes )
    {
        super( context, attributes ) ;
    }

    public void onSizeChanged( int current_width_of_this_view,
                               int current_height_of_this_view,
                               int old_width_of_this_view,
                               int old_height_of_this_view )
    {
        view_center_point_x  = current_width_of_this_view / 2 ;
        view_center_point_y  = current_height_of_this_view  / 2 ;
    }

    public void set_shape_to_draw( String given_shape_to_draw )
    {
        shape_to_draw = given_shape_to_draw ;
        invalidate() ;
    }

    @Override
    protected void onDraw( Canvas canvas )
    {
        Paint filling_paint = new Paint() ;
        filling_paint.setStyle( Paint.Style.FILL ) ;

        Paint outline_paint = new Paint() ;  // Default color for Paint is black.
        outline_paint.setStyle( Paint.Style.STROKE ) ;

        if ( shape_to_draw.equals( "Square" ) )
        {
            filling_paint.setColor( Color.CYAN ) ;

            canvas.drawRect( view_center_point_x - 80, view_center_point_y - 80,
                    view_center_point_x + 80, view_center_point_y + 80,
                    filling_paint ) ;

            canvas.drawRect( view_center_point_x - 80, view_center_point_y - 80,
                    view_center_point_x + 80, view_center_point_y + 80,
                    outline_paint ) ;
        }
        else if ( shape_to_draw.equals( "Ball" ) )
        {
            filling_paint.setColor( Color.MAGENTA ) ;

            canvas.drawCircle( view_center_point_x,
                    view_center_point_y, 80, filling_paint ) ;

            canvas.drawCircle( view_center_point_x,
                    view_center_point_y, 80, outline_paint ) ;
        }
        else if ( shape_to_draw.equals( "Triangle" ) )
        {
            filling_paint.setColor( Color.YELLOW ) ;

            Path triangle_path = new Path() ;
            triangle_path.moveTo( view_center_point_x, view_center_point_y - 80 ) ;
            triangle_path.lineTo( view_center_point_x + 96, view_center_point_y + 80 ) ;
            triangle_path.lineTo( view_center_point_x - 96, view_center_point_y + 80 ) ;
            canvas.drawPath( triangle_path, filling_paint ) ;
            triangle_path.close() ;

        }

        else if ( shape_to_draw.equals( "Piece of Cake" ) )
        {
            filling_paint.setColor( Color.GREEN ) ;
            outline_paint.setColor( Color.BLACK ) ;

            int view_width  = getWidth() ;
            int view_height = getHeight() ;

            RectF square_around_pie = new RectF(
                    view_center_point_x - 120,
                    view_center_point_y - 120,
                    view_center_point_x + 120,
                    view_center_point_y + 120 ) ;

            canvas.drawArc( square_around_pie, 45,  90, true, filling_paint ) ;
            canvas.drawArc( square_around_pie, 45,  90, true, outline_paint ) ;

        }
    }
}


/**

 // With the Path class you can create some complex
 // graphical shapes. The following Path will be a 5-point star

 Path star_shape_5  =  new Path() ;

 //  The following coordinates are fixed supposing that the
 //  radius of the star is 80 pixels (points).
 //  Larger or smaller stars are drawn by adjusting the scale of
 //  the coordinate system. If you want to change the default
 //  star radius (80 points), you must modify these coordinates
 //  as well.

 star_shape_5.moveTo( view_center_point_x + 76.08F,
 view_center_point_y - 24.72F ) ; // start from upper right point
 star_shape_5.lineTo( view_center_point_x - 47.02F,
 view_center_point_y + 64.72F ) ; // to lower left point
 star_shape_5.lineTo( view_center_point_x,
 view_center_point_y - 80.0F  ) ; // to upper middle point
 star_shape_5.lineTo( view_center_point_x + 47.02F,
 view_center_point_y + 64.72F ) ; // to lower right point
 star_shape_5.lineTo( view_center_point_x - 76.08F,
 view_center_point_y - 24.72F ) ; // to upper left point
 star_shape_5.close() ;                // to upper right point

 canvas.drawPath( star_shape_5, filling_paint ) ;

 canvas.drawPath( star_shape_5, outline_paint ) ;

 // The following lines specify a Path for triangle shape.

 Path  triangle_path  =  new  Path() ;

 triangle_path.moveTo( view_center_point_x, view_center_point_y - 80 ) ;
 triangle_path.lineTo( view_center_point_x + 96, view_center_point_y + 80 ) ;
 triangle_path.lineTo( view_center_point_x - 96, view_center_point_y + 80 ) ;
 triangle_path.close() ;

 **/
