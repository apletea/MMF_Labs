package com.example.davinci.lecture7;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

/**
 * Created by davinci on 25.11.17.
 */

public class MainGLSurfaceView extends GLSurfaceView {
    private final MainRender mRenderer;

    public MainGLSurfaceView(Context context) {
        super(context);

        mRenderer = new MainRender();
        setRenderer(mRenderer);

        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    }

    private final float TOUCH_SCALE_FACTOR = 180.0f / 320;
    private float mPreviousX;
    private float mPreviousY;


    boolean is_first = true;

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        // MotionEvent reports input details from the touch screen
        // and other input controls. In this case, we are only
        // interested in events where the touch position changed.

        float x = e.getX();
        float y = e.getY();

        switch (e.getAction()) {
            case MotionEvent.ACTION_MOVE:

                float dx = x - mPreviousX;
                float dy = y - mPreviousY;

                // reverse direction of rotation above the mid-line
                if (y > getHeight() / 2) {
                    dx = dx * -1 ;
                }

                // reverse direction of rotation to left of the mid-line
                if (x < getWidth() / 2) {
                    dy = dy * -1 ;
                }

                mRenderer.setAngle(
                        mRenderer.getAngle() +
                                ((dx + dy) * TOUCH_SCALE_FACTOR));  // = 180.0f / 320
                requestRender();
            case MotionEvent.ACTION_DOWN:
                if (is_first)
                    mRenderer.inLarge(2);

                else
                    mRenderer.inLarge(1);
                is_first = !is_first;
                requestRender();

        }

        mPreviousX = x;
        mPreviousY = y;
        return true;
    }
}
