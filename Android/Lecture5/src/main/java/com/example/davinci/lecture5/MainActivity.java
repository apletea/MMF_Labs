package com.example.davinci.lecture5;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.example.davinci.lecture5.services.MyService;

public class MainActivity extends AppCompatActivity {

    Intent intent = new Intent(this,MyService.class);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onCLickEnd(View view) {
        stopService(intent);
    }

    public void onClickStart(View view){
        startService(intent);
    }


}
