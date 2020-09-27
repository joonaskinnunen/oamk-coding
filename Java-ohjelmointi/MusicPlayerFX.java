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
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
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
    Label trackNameLabel = new Label("Paused " + tracks[0]);
    Slider timeSlider = new Slider(0, 0, 0);
    Button playButton = new Button("play");
    Button nextButton = new Button("next");
    Button previousButton = new Button("prev");
    Button volumeDownButton = new Button();
    Button volumeUpButton = new Button();
    Label titleLabel = new Label("Music player");
    Label volumeLabel = new Label("Volume: " + (int) Math.round(mediaPlayer.getVolume() * 100) + "%");
    Label timeLabel = new Label();
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
    public void start(Stage stage) throws Exception {
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
        timeSlider.setMinWidth(200);
        timeSlider.setMaxWidth(250);
        
        createMediaPlayer();

        previousButton.setDisable(true);

        playButton.setOnAction((ActionEvent event)
                -> {
            isPlaying = !isPlaying;
            trackNameLabel.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
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
            if (trackHistory.isEmpty()) {
                previousButton.setDisable(true);
            }
            createMediaPlayer();
            togglePlayer();
        });

        VBox vbox = new VBox();
        HBox hbButtons = new HBox();
        HBox hbVolumeButtons = new HBox();
        HBox hbCheckBoxes = new HBox();

        vbox.setStyle("-fx-border-style: solid inside;"
                + "-fx-border-width: 2;"
                + "-fx-border-insets: 5;"
                + "-fx-border-radius: 5;"
                + "-fx-border-color: orange;"
                + "-fx-background-color: black;"
                + "-fx-alignment: center");
        titleLabel.setStyle("-fx-padding: 0 0 15 0;"
                + "-fx-font: 30px Tahoma;"
                + "-fx-text-fill: white");
        trackNameLabel.setStyle("-fx-font: 15px Tahoma;"
                + "-fx-text-fill: orange");
        timeLabel.setStyle("-fx-font: 10px Tahoma;"
                + "-fx-text-fill: white");
        trackNameLabel.setBackground(new Background(
                new BackgroundFill(
                        Color.color(
                                Color.YELLOW.getRed(),
                                Color.YELLOW.getGreen(),
                                Color.YELLOW.getBlue(), 0.4d),
                        new CornerRadii(2),
                        null)));
        hbButtons.setStyle("-fx-padding: 10 0 10 0;"
                + "-fx-spacing: 10;"
                + "-fx-alignment: center");
        hbVolumeButtons.setStyle("-fx-padding: 5 0 0 0;"
                + "-fx-spacing: 10;"
                + "-fx-alignment: center");
        hbCheckBoxes.setStyle("-fx-padding: 5 0 15 0;"
                + "-fx-spacing: 10;"
                + "-fx-alignment: center");

        volumeLabel.setTextFill(Color.WHITE);
        autoplayCb.setTextFill(Color.WHITE);
        shuffleCb.setTextFill(Color.WHITE);
        timeSlider.setPadding(new Insets(25, 0, 0, 0));

        hbButtons.getChildren().addAll(playButton, previousButton, nextButton);
        hbCheckBoxes.getChildren().addAll(autoplayCb, shuffleCb);
        hbVolumeButtons.getChildren().addAll(volumeDownButton, volumeUpButton);

        vbox.getChildren().addAll(titleLabel, trackNameLabel, timeSlider, timeLabel, hbButtons, hbCheckBoxes, volumeLabel, hbVolumeButtons);

        Scene scene = new Scene(vbox, 300, 300);
        stage.setTitle("Music player");
        stage.setScene(scene);
        stage.show();
    }

    public void createMediaPlayer() {
        double volume = mediaPlayer.getVolume();
        mediaPlayer.dispose();
        sound = new Media(new File("sounds/" + tracks[trackIndex]).toURI().toString());
        trackNameLabel.setText(isPlaying ? "Now playing: " + tracks[trackIndex] : "Paused: " + tracks[trackIndex]);
        mediaPlayer = new MediaPlayer(sound);
        mediaPlayer.setVolume(volume);

        sound.durationProperty().addListener(change -> {
            timeSlider.setMax(sound.getDuration().toSeconds());
            timeSlider.setOnMouseDragged(drag -> {
                mediaPlayer.seek(Duration.seconds(timeSlider.getValue()));
            });
        });

        mediaPlayer.currentTimeProperty().addListener(c -> {
            timeLabel.setText(getTimeString((long) mediaPlayer.getCurrentTime().toMillis()) + "/" + getTimeString((long) sound.getDuration().toMillis()));
            timeSlider.setValue(mediaPlayer.getCurrentTime().toSeconds());

        });

        mediaPlayer.setOnEndOfMedia(() -> {
            if (autoplayCb.isSelected()) {
                nextButton.fire();
            } else {
                mediaPlayer.seek(Duration.seconds(0));
                timeSlider.setValue(0);
                playButton.fire();
                timeLabel.setText(getTimeString((long) mediaPlayer.getCurrentTime().toMillis()) + "/" + getTimeString((long) sound.getDuration().toMillis()));
            }
        });
    }

    public String getTimeString(long millis) {
        StringBuilder str = new StringBuilder();

        int minutes = (int) ((millis % (1000 * 60 * 60)) / (1000 * 60));
        int seconds = (int) (((millis % (1000 * 60 * 60)) % (1000 * 60)) / 1000);

        str
                .append(String.format("%02d", minutes))
                .append(":")
                .append(String.format("%02d", seconds));

        return str.toString();
    }

    public void togglePlayer() {
        if (isPlaying) {
            mediaPlayer.play();
            System.out.println("playing");
        } else {
            mediaPlayer.pause();
            System.out.println("paused");
        }
    }

    public static void main(String[] args) {
        launch(args);
    }

}
