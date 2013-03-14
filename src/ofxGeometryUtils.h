//
//  ofxGeometryUtils.h
//  ofxLivedrawEngineExample
//
//  Created by Christopher P. Baker on 8/27/12.
//
//

#pragma once

//ofRectangle ofxScaleInto(const ofRectangle& target,
//                           const ofRectangle& subject,
//               
//           float subjectWidth, float subjectHeight,
//           float )
//
//float w = transform.getWidth();
//float h = transform.getHeight();
//
//float fw = frame->getWidth();
//float fh = frame->getHeight();
//
//if(layerStretchMode == CENTER) {
//    frame->draw((w - fw) * 0.5f,
//                (h - fh) * 0.5f,
//                fw,
//                fh);
//} else if(layerStretchMode == FILL) {
//    float resultScale = MAX(fabs(w) / fabs(fw),
//                            fabs(h) / fabs(fh));
//    
//    frame->draw(( w - fw * resultScale ) * 0.5f,
//                ( h - fh * resultScale ) * 0.5f,
//                ( fw * resultScale ),
//                ( fh * resultScale ));
//} else if(layerStretchMode == FIT) {
//    // find the scaling factor, fabs for -w and/or -h
//    float resultScale = MIN(fabs(w) / fabs(fw),
//                            fabs(h) / fabs(fh));
//    
//    frame->draw(( w - fw * resultScale ) * 0.5f,
//                ( h - fh * resultScale ) * 0.5f,
//                ( fw * resultScale ),
//                ( fh * resultScale ));
//    
//} else if(layerStretchMode == STRETCH) {
//    frame->draw(0,0,w,h);
//} else {
//    frame->draw(0,0,w,h);
//    ofLogWarning("Layer") << "update(): Unknown layer stretch mode." << endl;
//}
//
//
//fbo->end(); // end the fbo
