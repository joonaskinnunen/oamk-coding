/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package musicplayerfx;

import java.io.File;
import java.util.ArrayList;
import java.util.Random;
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
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
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
    ArrayList<Integer> trackHistory = new ArrayList<>();
    Media sound = new Media(new File("sounds/" + tracks[0]).toURI().toString());
    MediaPlayer mediaPlayer = new MediaPlayer(sound);
    Label trackName = new Label("Paused " + tracks[0]);
    Slider timeSlider = new Slider(0, 0, 0);
    Button playButton = new Button("play");
    Button nextButton = new Button("next");
    Button previousButton = new Button("prev");
    Button volumeDownButton = new Button();
    Button volumeUpButton = new Button();
    Label title = new Label("Music player");
    Label volumeLabel = new Label("Volume: " + (int) Math.round(mediaPlayer.getVolume() * 100) + "%");
    Image vUpImg = new Image("https://i.ibb.co/X2W6L2Z/volumeup.png");
    ImageView vUpView = new ImageView(vUpImg);
    Image vDownImg = new Image("https://i.ibb.co/yPNX3JW/volumedown.png");
    ImageView vDownView = new ImageView(vDownImg);
    Image playImg = new Image("https://i.ibb.co/jw2CfR2/playbutton.png");
    ImageView playView = new ImageView(playImg);
    Image pauseImg = new Image("https://i.ibb.co/sgwzKHJ/pausebutton.png");
    ImageView pauseView = new ImageView(pauseImg);
    Image nextImg = new Image("https://i.ibb.co/4mHN7CK/nextbutton.png");
    ImageView nextView = new ImageView(nextImg);
    Image prevImg = new Image("https://i.ibb.co/71QDqMx/previousbutton.png");
    ImageView prevView = new ImageView(prevImg);
    CheckBox autoplayCb = new CheckBox("autoplay");
    CheckBox shuffleCb = new CheckBox("shuffle");

    @Override
    public void start(Stage primaryStage) throws Exception {
        vUpView.setFitHeight(10);
        vUpView.setPreserveRatio(true);
        vDownView.setFitHeight(10);
        vDownView.setPreserveRatio(true);
        playView.setFitHeight(15);
        playView.setPreserveRatio(true);
        pauseView.setFitHeight(15);
        pauseView.setPreserveRatio(true);
        nextView.setFitHeight(15);
        nextView.setPreserveRatio(true);
        prevView.setFitHeight(15);
        prevView.setPreserveRatio(true);
        volumeUpButton.setGraphic(vUpView);
        volumeDownButton.setGraphic(vDownView);
        playButton.setGraphic(playView);
        nextButton.setGraphic(nextView);
        previousButton.setGraphic(prevView);
        timeSlider.setMinWidth(50);
        timeSlider.setMaxWidth(Double.MAX_VALUE);
        createMediaPlayer();
        
        previousButton.setDisable(true);

        playButton.setOnAction((ActionEvent event)
                -> {
            isPlaying = !isPlaying;
            trackName.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
            playButton.setText(isPlaying ? "pause" : "play");
            playButton.setGraphic(isPlaying ? pauseView : playView);
            togglePlayer();
        });

        volumeDownButton.setOnAction((ActionEvent event)
                -> {
            System.out.println("Volume down");
            if (mediaPlayer.getVolume() > 0.1) {
                mediaPlayer.setVolume(mediaPlayer.getVolume() - 0.1);
            }
            volumeLabel.setText("Volume: " + (int) Math.round(mediaPlayer.getVolume() * 100) + "%");

        });

        volumeUpButton.setOnAction((ActionEvent event)
                -> {
            System.out.println("Volume up");
            if (mediaPlayer.getVolume() < 1.0) {
                mediaPlayer.setVolume(mediaPlayer.getVolume() + 0.1);
            }
            volumeLabel.setText("Volume: " + (int) Math.round(mediaPlayer.getVolume() * 100) + "%");
        });

        nextButton.setOnAction((ActionEvent event)
                -> {
            trackHistory.add(trackIndex);
            System.out.println(trackHistory);
            previousButton.setDisable(false);
            System.out.println("next track");
            if (shuffleCb.isSelected()) {
                Random random = new Random();
                trackIndex = random.nextInt(10);
            } else {
                if (trackIndex < tracks.length - 1) {
                    trackIndex++;
                } else {
                    trackIndex = 0;
                }
            }
            createMediaPlayer();
            togglePlayer();

        });

        previousButton.setOnAction((ActionEvent event)
                -> {
            System.out.println("previous track");
            trackIndex = trackHistory.get(trackHistory.size() - 1);
            trackHistory.remove(trackHistory.size() - 1);
            if(trackHistory.size() == 0) previousButton.setDisable(true);
            createMediaPlayer();
            togglePlayer();
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
        GridPane.setHalignment(volumeLabel, HPos.CENTER);
        title.setFont(Font.font("Tahoma", 30));
        trackName.setFont(Font.font("Tahoma", 15));
        title.setMinHeight(70);
        trackName.setTextFill(Color.ORANGE);
        title.setTextFill(Color.WHITE);
        trackName.setBackground(new Background(
                new BackgroundFill(
                        Color.color(
                                Color.YELLOW.getRed(),
                                Color.YELLOW.getGreen(),
                                Color.YELLOW.getBlue(), 0.4d),
                        new CornerRadii(2),
                        null)));
        volumeLabel.setTextFill(Color.WHITE);
        HBox hbButtons = new HBox();
        HBox hbVolumeButtons = new HBox();
        HBox hbCheckBoxes = new HBox();
        hbButtons.setSpacing(10.0);
        hbButtons.setPadding(new Insets(20, 0, 20, 0));
        hbButtons.getChildren().addAll(playButton, previousButton, nextButton);
        hbVolumeButtons.setSpacing(10.0);
        hbVolumeButtons.setPadding(new Insets(5, 0, 0, 0));
        hbVolumeButtons.setAlignment(Pos.CENTER);
        hbVolumeButtons.getChildren().addAll(volumeDownButton, volumeUpButton);
        hbCheckBoxes.setSpacing(10.0);
        hbCheckBoxes.setPadding(new Insets(5, 0, 0, 0));
        hbCheckBoxes.setAlignment(Pos.CENTER);
        hbCheckBoxes.getChildren().addAll(autoplayCb, shuffleCb);
        autoplayCb.setTextFill(Color.WHITE);
        shuffleCb.setTextFill(Color.WHITE);
        timeSlider.setPadding(new Insets(5, 0, 0, 0));
        hbCheckBoxes.setPadding(new Insets(0, 0, 15, 0));
        grid.add(title, 1, 0);
        grid.add(trackName, 1, 1);
        grid.add(timeSlider, 1, 2);
        grid.add(hbButtons, 1, 3);
        grid.add(hbCheckBoxes, 1, 4);
        grid.add(volumeLabel, 1, 5);
        grid.add(hbVolumeButtons, 1, 6);
        Scene scene = new Scene(grid, 300, 300);
        primaryStage.setTitle("Music player");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void createMediaPlayer() {
        double volume = mediaPlayer.getVolume();
        mediaPlayer.dispose();
        sound = new Media(new File("sounds/" + tracks[trackIndex]).toURI().toString());
        trackName.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
        mediaPlayer = new MediaPlayer(sound);
        mediaPlayer.setVolume(volume);
        sound.durationProperty().addListener(change -> {
            timeSlider.setMax(sound.getDuration().toSeconds());
            timeSlider.setOnMouseDragged(drag -> {
                mediaPlayer.seek(Duration.seconds(timeSlider.getValue()));
            });
        });
        mediaPlayer.currentTimeProperty().addListener(c -> {
            timeSlider.setValue(mediaPlayer.getCurrentTime().toSeconds());
            if (mediaPlayer.getCurrentTime().toSeconds() == sound.getDuration().toSeconds()) {
                if(autoplayCb.isSelected()) {
                    nextButton.fire();
                } else {
                    mediaPlayer.seek(Duration.seconds(0));
                        playButton.setText("play");
                        playButton.setGraphic(playView);
                }
            }
        });
    }

    public void togglePlayer() {
        try {
            if (isPlaying) {
                mediaPlayer.play();
                System.out.println("playing..");
            } else {
                mediaPlayer.pause();
                System.out.println("paused");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        launch(args);
    }

}
