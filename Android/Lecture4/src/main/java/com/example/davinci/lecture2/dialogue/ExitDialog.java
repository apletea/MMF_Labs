package com.example.davinci.lecture2.dialogue;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;

import com.example.davinci.lecture2.interfaces.IExitDialog;

/**
 * Created by davinci on 25.11.17.
 */

public class ExitDialog extends DialogFragment {
    @Override
    public Dialog onCreateDialog(Bundle instanceState){
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setMessage("Is that relly?")
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {

                        ((IExitDialog)getActivity()).onExit();
                    }
                })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {

                    }
                });
        return builder.create();
    }
}
