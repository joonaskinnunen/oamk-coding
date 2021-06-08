package com.example.explicitintent;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        textView = findViewById(R.id.text);
        Bundle extras = getIntent().getExtras();
        if (extras != null) {
            String str1 = extras.getString("key1");
            textView.setText(str1);
        }
    }
}