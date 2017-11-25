package com.example.davinci.lecture5.services;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;


public class MyService extends Service
{
    @Override
    public IBinder onBind(Intent arg0)
    {
        return null;
    }

    @Override
    public void onCreate()
    {
        super.onCreate();
        Log.e("service","Service is Created");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId)
    {
        Log.e("service","Service is Started");
        return START_STICKY;
    }

    @Override
    public void onDestroy()
    {
        super.onDestroy();
        Log.e("service","Service is  Destroyed   ");
    }
}
