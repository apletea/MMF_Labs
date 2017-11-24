package com.example.davinci.lecture2;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.example.davinci.lecture2.interfaces.IExitDialog;

public class MainActivity extends Activity implements IExitDialog {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick_OpenNewActivity(View v){
        Intent intent = new Intent(MainActivity.this,Main2Activity.class);
        startActivityForResult(intent,1);
    }

    @Override
    protected void onActivityResult(int reqCode, int resCode, Intent data){
        if (reqCode == 1) {
            if (resCode == Activity.RESULT_OK) {
                String firstName = data.getStringExtra("firstName");
                String surNmae = data.getStringExtra("surName");

                TextView textView = (TextView) findViewById(R.id.TextView);
                textView.setText("Hi " + firstName + "  " + surNmae);
            }
        }
    }

    public void onExit(){
        Toast toast = Toast.makeText(getApplicationContext(), "Bye!", Toast.LENGTH_SHORT);
        toast.show();
        this.finishAndRemoveTask();
    }
}
