package com.example.davinci.lecture2;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class Main2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
    }

    public void onClick(View view){
        Intent intent = new Intent(this,MainActivity.class);
        String firstName = ((EditText)findViewById(R.id.firstName)).getText().toString();
        String surName = ((EditText)findViewById(R.id.surName)).getText().toString();

        intent.putExtra("firstName",firstName);
        intent.putExtra("surName",surName);

        setResult(Activity.RESULT_OK, intent);
        finish();
    }
}
