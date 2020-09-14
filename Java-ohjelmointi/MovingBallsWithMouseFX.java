
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;

import javax.swing.*;
import java.awt.*;

import javafx.scene.*;

import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.geometry.*; // Point2D
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;

import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;

import javafx.scene.shape.Circle;

import javafx.collections.*; // ObservableList etc.
import java.awt.geom.Rectangle2D;

class Ball extends Circle {

    public Ball(double given_center_point_x,
            double given_center_point_y,
            double given_radius,
            Color given_color) {
        super(given_center_point_x, given_center_point_y, given_radius, given_color);

        setStroke(Color.BLACK);
        setStrokeWidth(2);
    }

    public void activate_ball() {
        setStrokeWidth(6);
    }

    public void deactivate_ball() {
        setStrokeWidth(2);
    }

    public void move_this_ball(double movement_in_direction_x,
            double movement_in_direction_y) {
        setCenterX(getCenterX() + movement_in_direction_x);
        setCenterY(getCenterY() + movement_in_direction_y);
    }

}

class GradientBall extends Ball {

    public GradientBall(double given_center_point_x,
            double given_center_point_y,
            double given_radius,
            Color given_color) {
        super(given_center_point_x, given_center_point_y, given_radius, given_color);
        Stop[] color_stops = {new Stop(0, Color.WHITE),
            new Stop(1, given_color)};
        LinearGradient gradient_color = new LinearGradient(0, 0, 1, 1, true,
                CycleMethod.NO_CYCLE, color_stops);
        setStroke(Color.BLACK);
        setStrokeWidth(2);
        setFill(gradient_color);
    }
}

public class MovingBallsWithMouseFX extends Application {

    static final int SCENE_WIDTH = 800;
    static final int SCENE_HEIGHT = 600;

    boolean ball_movement_going_on = false;

    double previous_cursor_position_x, previous_cursor_position_y;

    Group group_for_balls = new Group();

    private void set_mouse_activities_for_balls() {
        // The following 'foreach' loop specifies, for each Ball object,
        // the activities to be performed when mouse events take place
        // on the balls.

        for (Node child_in_list : group_for_balls.getChildren()) {
            Ball ball_in_list = (Ball) child_in_list;

            ball_in_list.setOnMousePressed((MouseEvent event)
                    -> {
                if (ball_movement_going_on == false) {
                    ball_in_list.activate_ball();
                    previous_cursor_position_x = event.getSceneX();
                    previous_cursor_position_y = event.getSceneY();
                    ball_movement_going_on = true;
                }
            });

            ball_in_list.setOnMouseDragged((MouseEvent event)
                    -> {
                if (ball_movement_going_on == true) {
                    double mouse_movement_x = event.getSceneX()
                            - previous_cursor_position_x;

                    double mouse_movement_y = event.getSceneY()
                            - previous_cursor_position_y;

                    previous_cursor_position_x = event.getSceneX();
                    previous_cursor_position_y = event.getSceneY();

                    ball_in_list.move_this_ball(mouse_movement_x,
                            mouse_movement_y);

                }
            });

            ball_in_list.setOnMouseReleased((MouseEvent event)
                    -> {
                if (ball_movement_going_on == true) {
                    ball_in_list.deactivate_ball();
                    ball_movement_going_on = false;
                }
            });
        }
    }

    public void start(Stage stage) {

        group_for_balls.getChildren().add(
                new Ball(SCENE_WIDTH / 5, SCENE_HEIGHT / 2, 64, Color.RED));

        group_for_balls.getChildren().add(
                new Ball(SCENE_WIDTH / 5 * 2, SCENE_HEIGHT / 2, 64, Color.GREEN));

        group_for_balls.getChildren().add(
                new Ball(SCENE_WIDTH * 3 / 5, SCENE_HEIGHT / 2, 64, Color.BLUE));

        group_for_balls.getChildren().add(
                new Ball(SCENE_WIDTH * 4 / 5, SCENE_HEIGHT / 2, 64, Color.PURPLE));

        group_for_balls.getChildren().add(
                new GradientBall(SCENE_WIDTH * 4 / 5, SCENE_HEIGHT / 4, 64, Color.YELLOW));

        set_mouse_activities_for_balls();

        Scene scene = new Scene(group_for_balls, SCENE_WIDTH, SCENE_HEIGHT);

        scene.setFill(Color.LIGHTYELLOW);

        stage.setTitle("MovingBallsWithMouseFX.java");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] command_line_parameters) {
        launch(command_line_parameters);
    }
}
