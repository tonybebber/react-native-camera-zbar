package com.lwansbrough.RCTCameraOld;

import android.support.annotation.Nullable;

import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.uimanager.*;
import com.facebook.react.uimanager.annotations.ReactProp;

import java.util.List;
import java.util.ArrayList;

public class RCTCameraOldViewManager extends ViewGroupManager<RCTCameraOldView> {
    private static final String REACT_CLASS = "RCTCameraOld";

    @Override
    public String getName() {
        return REACT_CLASS;
    }

    @Override
    public RCTCameraOldView createViewInstance(ThemedReactContext context) {
        return new RCTCameraOldView(context);
    }

    @ReactProp(name = "aspect")
    public void setAspect(RCTCameraOldView view, int aspect) {
        view.setAspect(aspect);
    }

    @ReactProp(name = "captureMode")
    public void setCaptureMode(RCTCameraOldView view, final int captureMode) {
        // Note that this in practice only performs any additional setup necessary for each mode;
        // the actual indication to capture a still or record a video when capture() is called is
        // still ultimately decided upon by what it in the options sent to capture().
        view.setCaptureMode(captureMode);
    }

    @ReactProp(name = "captureTarget")
    public void setCaptureTarget(RCTCameraOldView view, int captureTarget) {
        // No reason to handle this props value here since it's passed again to the RCTCameraOldModule capture method
    }

    @ReactProp(name = "type")
    public void setType(RCTCameraOldView view, int type) {
        view.setCameraType(type);
    }

    @ReactProp(name = "captureQuality")
    public void setCaptureQuality(RCTCameraOldView view, String captureQuality) {
        view.setCaptureQuality(captureQuality);
    }

    @ReactProp(name = "torchMode")
    public void setTorchMode(RCTCameraOldView view, int torchMode) {
        view.setTorchMode(torchMode);
    }

    @ReactProp(name = "flashMode")
    public void setFlashMode(RCTCameraOldView view, int flashMode) {
        view.setFlashMode(flashMode);
    }

    @ReactProp(name = "orientation")
    public void setOrientation(RCTCameraOldView view, int orientation) {
        view.setOrientation(orientation);
    }

    @ReactProp(name = "captureAudio")
    public void setCaptureAudio(RCTCameraOldView view, boolean captureAudio) {
        // TODO - implement video mode
    }

    @ReactProp(name = "barcodeScannerEnabled")
    public void setBarcodeScannerEnabled(RCTCameraOldView view, boolean barcodeScannerEnabled) {
        view.setBarcodeScannerEnabled(barcodeScannerEnabled);
    }

    @ReactProp(name = "zoomEnabled")
    public void setZoomEnabled(RCTCameraOldView view, boolean zoomEnabled) {
        view.setZoomEnabled(zoomEnabled);
    }

    @ReactProp(name = "barCodeTypes")
    public void setBarCodeTypes(RCTCameraOldView view, ReadableArray barCodeTypes) {
        if (barCodeTypes == null) {
            return;
        }
        List<String> result = new ArrayList<String>(barCodeTypes.size());
        for (int i = 0; i < barCodeTypes.size(); i++) {
            result.add(barCodeTypes.getString(i));
        }
        view.setBarCodeTypes(result);
    }
}
