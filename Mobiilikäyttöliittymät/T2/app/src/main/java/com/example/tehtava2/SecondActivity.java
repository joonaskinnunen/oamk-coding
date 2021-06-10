package com.example.tehtava2;

import android.content.Intent;
import android.os.Bundle;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {
    EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        editText = findViewById(R.id.editText);
    }
    @Override

    public void onBackPressed() {
        Intent intent = new Intent();
        String str1 = editText.getText().toString();
        intent.putExtra("str", str1);
        setResult(RESULT_OK, intent);
        super.onBackPressed();
    }
}