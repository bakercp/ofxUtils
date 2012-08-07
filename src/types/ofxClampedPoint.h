/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/


// TODO: would like to use this with ofParameter in some way

#pragma once

#include "ofMain.h"

class ofxClampedPoint : public ofPoint {
public:
	
	ofxClampedPoint(const ofPoint& pnt)
		: ofPoint(pnt) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);

    }
	
	ofxClampedPoint(float _x=0.0f, float _y=0.0f, float _z=0.0f)
		: ofPoint(_x,_y,_z) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);
			
	};
	 
	~ofxClampedPoint() {}
	
	ofPoint getClamped() const {
		return ofPoint(getClampedX(), getClampedY(), getClampedZ());
	}
    
	float getClampedX() const {return ofClamp(x,minLimit.x,maxLimit.x);}
	float getClampedY() const {return ofClamp(y,minLimit.y,maxLimit.y);}
	float getClampedZ() const {return ofClamp(z,minLimit.z,maxLimit.z);}

	void setMinLimits(const ofPoint& pnt) {
        setMinX(pnt.x);
        setMinY(pnt.y);
        setMinZ(pnt.z);
    };
	void setMaxLimits(const ofPoint& pnt) {
        setMaxX(pnt.x);
        setMaxY(pnt.y);
        setMaxZ(pnt.z);
    }

	void setMinX(float x) {
        if(areSame(x,minLimit.x)) return;
        minLimit.x = x; 
        onLimitMinXChanged();
    }
    
	void setMaxX(float x) {
        if(areSame(x,maxLimit.x)) return;
        maxLimit.x = x; 
        onLimitMaxXChanged();
    }

	void setMinY(float y) {
        if(areSame(y,minLimit.y)) return;
        minLimit.y = y; 
        onLimitMinYChanged();
    }
	
    void setMaxY(float y) {
        if(areSame(y,maxLimit.y)) return;
        maxLimit.y = y; 
        onLimitMaxYChanged();
    }

	void setMinZ(float z) {
        if(areSame(z,minLimit.z)) return;
        minLimit.z = z; 
        onLimitMinZChanged();
    }
    
	void setMaxZ(float z) {
        if(areSame(z,minLimit.z)) return;
        maxLimit.z = z; 
        onLimitMaxZChanged();
    }

	void clearMaxLimits() { 
        setMaxLimits(ofPoint(FLT_MAX,FLT_MAX,FLT_MAX));
    }
	
    void clearMinLimits() { 
        setMinLimits(ofPoint(-FLT_MAX,-FLT_MAX,-FLT_MAX));
    }

    // callbacks
    void onLimitMinXChanged() {}
	void onLimitMinYChanged() {}
	void onLimitMinZChanged() {}

	void onLimitMaxXChanged() {}
	void onLimitMaxYChanged() {}
	void onLimitMaxZChanged() {}

	
protected:
	
    bool areSame(float a, float b) const {
        return std::fabs(a - b) < std::numeric_limits<float>::epsilon();
    }
    
	ofPoint minLimit;
	ofPoint maxLimit;
		
		
};


