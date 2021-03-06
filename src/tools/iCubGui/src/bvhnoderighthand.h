/*
 * bvhnoderighthand.h
 */

/*
 * Copyright (C) 2009 RobotCub Consortium
 * Author: Alessandro Scalzo alessandro.scalzo@iit.it
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
 *
 * Based on:
 *
 *   Qavimator
 *   Copyright (C) 2006 by Zi Ree   *
 *   Zi Ree @ SecondLife   *
 *   Released under the terms of the GNU GPL v2.0.
 */

#ifndef BVHNODERIGHTHAND_H
#define BVHNODERIGHTHAND_H

#include "bvhnodeend.h"

class BVHNodeRIGHTHAND : public BVHNodeEND
{
public:

    BVHNodeRIGHTHAND(const QString& name,int enc,double a,double d,double alpha,double theta0,iCubMesh* mesh=0)
        : BVHNodeEND(name,enc,a,d,alpha,theta0,mesh){ nEnc=enc; }

    void FingerSegment(double length)
    {
        length-=1.0;
        gluDisk(cyl,0.0,5.0,16,16);
        gluCylinder(cyl,5.0,5.0,length,16,16);
        glTranslated(0.0,0.0,length);
        gluDisk(cyl,0.0,5.0,16,16);
        glTranslated(0.0,0.0,1.0);
    }

    virtual void draw(double* encoders,BVHNode* pSelected)
    {
        glPushMatrix();

        glRotated(dTheta0+encoders[nEnc],0.0,0.0,1.0);
        glTranslated(dA,0.0,dD);

        glRotated(dAlpha,1.0,0.0,0.0);

        drawArrows();

        glColor4f(0.2,0.2,0.2,1.0);
        glBegin(GL_QUADS);
        glNormal3d(0.0,0.0,-1.0);
        glVertex3d(-63.0,-12.0,-16.0);
        glNormal3d(0.0,0.0,-1.0);
        glVertex3d(15.0,-30.0,-16.0);
        glNormal3d(0.0,0.0,-1.0);
        glVertex3d(15.0,30.0,-16.0);
        glNormal3d(0.0,0.0,-1.0);
        glVertex3d(-63.0,12.0,-16.0);
        glNormal3d(0.0,0.0,1.0);
        glVertex3d(-63.0,-12.0,-6.0);
        glNormal3d(0.0,0.0,1.0);
        glVertex3d(15.0,-30.0,-6.0);
        glNormal3d(0.0,0.0,1.0);
        glVertex3d(15.0,30.0,-6.0);
        glNormal3d(0.0,0.0,1.0);
        glVertex3d(-63.0,12.0,-6.0);

        glNormal3d(0.0,-1.0,0.0);
        glVertex3d(-63.0,-12.0,-16.0);
        glNormal3d(0.0,-1.0,0.0);
        glVertex3d(-63.0,-12.0,-6.0);
        glNormal3d(0.0,-1.0,0.0);
        glVertex3d(15.0,-30.0,-6.0);
        glNormal3d(0.0,-1.0,0.0);
        glVertex3d(15.0,-30.0,-16.0);

        glNormal3d(0.0,1.0,0.0);
        glVertex3d(15.0,30.0,-16.0);
        glNormal3d(0.0,1.0,0.0);
        glVertex3d(15.0,30.0,-6.0);
        glNormal3d(0.0,1.0,0.0);
        glVertex3d(-63.0,12.0,-6.0);
        glNormal3d(0.0,1.0,0.0);
        glVertex3d(-63.0,12.0,-16.0);
        glEnd();

        glColor4f(0.5,0.5,0.5,1.0);

        //thumb
        glPushMatrix();
        glTranslated(-30.0,-7.5,-5.0);
        //glRotated(-75.0,0.0,0.0,1.0);
        glRotated(-90.0,0.0,0.0,1.0);

        glRotated(70.0-encoders[nEnc+2],0.0,1.0,0.0);
        FingerSegment(10.0);

        glRotated(-encoders[nEnc+3],1.0,0.0,0.0);
        FingerSegment(20.0);

        glRotated(-encoders[nEnc+4],1.0,0.0,0.0);
        FingerSegment(20.0);

        glRotated(-encoders[nEnc+4],1.0,0.0,0.0);
        FingerSegment(20.0);
        glPopMatrix();

        // middle
        glPushMatrix();
        glTranslated(15.0,-7.5,-11.0);
        glRotated(-10.0+0.1666*encoders[nEnc+1],0.0,0.0,1.0);
        glRotated(90.0-encoders[nEnc+7],0.0,1.0,0.0);
        FingerSegment(35.0);

        glRotated(-encoders[nEnc+8],0.0,1.0,0.0);
        FingerSegment(22.0);

        glRotated(-encoders[nEnc+8],0.0,1.0,0.0);
        FingerSegment(13.0);
        glPopMatrix();

        // index
        glPushMatrix();
        glTranslated(15.0,-22.5,-11.0);
        glRotated(-30.0+0.5*encoders[nEnc+1],0.0,0.0,1.0);
        glRotated(90.0-encoders[nEnc+5],0.0,1.0,0.0);
        FingerSegment(31.0);

        glRotated(-encoders[nEnc+6],0.0,1.0,0.0);
        FingerSegment(19.0);

        glRotated(-encoders[nEnc+6],0.0,1.0,0.0);
        FingerSegment(12.0);
        glPopMatrix();

        // ring
        glPushMatrix();
        glTranslated(15.0,7.5,-11.0);
        glRotated(10.0-0.1666*encoders[nEnc+1],0.0,0.0,1.0);
        glRotated(90.0-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(31.0);

        glRotated(-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(19.0);

        glRotated(-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(12.0);
        glPopMatrix();

        // pinky
        glPushMatrix();
        glTranslated(15.0,22.5,-11.0);
        glRotated(30.0-0.5*encoders[nEnc+1],0.0,0.0,1.0);
        glRotated(90.0-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(27.0);

        glRotated(-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(17.0);

        glRotated(-encoders[nEnc+9],0.0,1.0,0.0);
        FingerSegment(10.0);
        glPopMatrix();

        if (pMesh)
        {
            glColor4f(0.9,0.8,0.7,1.0);
            pMesh->Draw();
        }

        glPopMatrix();
    }
};

#endif
