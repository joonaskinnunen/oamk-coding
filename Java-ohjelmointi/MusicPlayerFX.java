/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package drummachine;

import java.io.File;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.geometry.HPos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.util.Duration;

/**
 *
 * @author joonaskinnunen
 */
public class MusicPlayerFX extends Application {

    boolean isPlaying = false;
    String[] tracks = {"clip1.wav", "clip2.wav", "clip3.wav", "clip4.wav", "clip5.wav", "clip6.wav", "clip7.wav", "clip8.wav", "clip9.wav", "clip10.wav"};
    int trackIndex = 0;
    Media sound = new Media(new File("sounds/" + tracks[0]).toURI().toString());
    MediaPlayer mediaPlayer = new MediaPlayer(sound);
    Label trackName = new Label("Paused " + tracks[0]);
    Slider timeSlider = new Slider(0, 0, 0);

    @Override
    public void start(Stage primaryStage) throws Exception {
        Button playButton = new Button("play");
        Button nextButton = new Button("next");
        Button previousButton = new Button("previous");
        Label title = new Label("Music player");
        timeSlider.setMinWidth(50);
        timeSlider.setMaxWidth(Double.MAX_VALUE);
        createMediaPlayer();

        playButton.setOnAction((ActionEvent event)
                -> {
            isPlaying = !isPlaying;
            trackName.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
            playButton.setText(isPlaying ? "pause" : "play");
            playAudio();

        });
        nextButton.setOnAction((ActionEvent event)
                -> {
            if (trackIndex < 9) {
                trackIndex++;
            } else {
                trackIndex = 0;
            }
            System.out.println("next track");
            createMediaPlayer();
            playAudio();

        });
        previousButton.setOnAction((ActionEvent event)
                -> {
            if (trackIndex > 0) {
                trackIndex--;
            } else {
                trackIndex = 9;
            }
            System.out.println("previous track");
            createMediaPlayer();
            playAudio();
        });

        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setStyle("-fx-border-style: solid inside;"
                + "-fx-border-width: 2;"
                + "-fx-border-insets: 5;"
                + "-fx-border-radius: 5;"
                + "-fx-border-color: orange;"
                + "-fx-background-color: black;");
        GridPane.setHalignment(title, HPos.CENTER);
        GridPane.setHalignment(trackName, HPos.CENTER);
        title.setFont(Font.font("Tahoma", 30));
        trackName.setFont(Font.font("Tahoma", 15));
        title.setMinHeight(120);
        trackName.setTextFill(Color.ORANGE);
        title.setTextFill(Color.BLUE);
        trackName.setBackground(new Background(
                new BackgroundFill(
                        Color.color(
                                Color.YELLOW.getRed(),
                                Color.YELLOW.getGreen(),
                                Color.YELLOW.getBlue(), 0.4d),
                        new CornerRadii(2),
                        null)));
        HBox hbButtons = new HBox();
        hbButtons.setSpacing(10.0);
        hbButtons.setPadding(new Insets(20, 0, 0, 0));
        hbButtons.getChildren().addAll(playButton, nextButton, previousButton);
        grid.add(title, 1, 0);
        grid.add(trackName, 1, 1);
        grid.add(timeSlider, 1, 2);
        grid.add(hbButtons, 1, 3);
        Scene scene = new Scene(grid, 300, 250);
        primaryStage.setTitle("Music player");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void createMediaPlayer() {
        mediaPlayer.dispose();
        sound = new Media(new File("sounds/" + tracks[trackIndex]).toURI().toString());
        trackName.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
        mediaPlayer = new MediaPlayer(sound);
        sound.durationProperty().addListener(change -> {
            timeSlider.setMax(sound.getDuration().toSeconds());
            timeSlider.setOnMouseDragged(drag -> {
                mediaPlayer.seek(Duration.seconds(timeSlider.getValue()));
            });
        });
        mediaPlayer.currentTimeProperty().addListener(c -> {
            timeSlider.setValue(mediaPlayer.getCurrentTime().toSeconds());
        });
    }

    public void playAudio() {
        System.out.println("playing..");
        try {
            if (isPlaying) {
                mediaPlayer.play();
            } else {
                mediaPlayer.pause();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        launch(args);
    }

}
