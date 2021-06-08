package com.example.explicitintent

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.receiver_activity.*

class ReceiverActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.receiver_activity)
        val extras = intent.extras
        if (extras != null) {
            val str = extras.getString("text")
            textView.text = str
        }
    }
}