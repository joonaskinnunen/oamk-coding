package com.example.tehtava3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick(View button) {
        Intent intent;
        switch (button.getId()) {
            case R.id.button:
                intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.oamk.fi"));
                startActivity(intent);
                break;
            case R.id.button2:
                intent = new Intent(Intent.ACTION_VIEW, Uri.parse("geo:65.004,25.319?z=14"));
                try {
                    startActivity(intent);
                } catch (ActivityNotFoundException e) {
                    Log.d("error: ", e.toString());
                }
                break;
            case R.id.button3:
                intent = new Intent(Intent.ACTION_VIEW, Uri.parse("geo:0,0?q=Bauhaus Oulu"));
                try {
                    startActivity(intent);
                } catch (ActivityNotFoundException e) {
                    Log.d("error: ", e.toString());
                }
                break;
        }
    }
}