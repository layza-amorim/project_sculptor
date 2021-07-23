/**
 * Created by Layza on 21/07/2021
 */

#include <iostream>
#include "Sculptor.hpp"

int main() {
    Sculptor sculptor(16,16,16); //create a sculptor object

    sculptor.setColor(0.6,0.3,0.0,0.8);//change color to brown
    sculptor.putBox(0,15,0,15,0,15);//activate voxels in interval

    sculptor.cutBox(0,15,15,15,0,5);//disable voxels in interval
    sculptor.cutBox(0,15,15,15,10,15);//disable voxels in interval

    sculptor.cutBox(0,15,14,14,0,4);//disable voxels in interval
    sculptor.cutBox(0,15,14,14,11,15);//disable voxels in interval

    sculptor.cutBox(0,15,13,13,0,3);//disable voxels in interval
    sculptor.cutBox(0,15,13,13,12,15);//disable voxels in interval

    sculptor.cutBox(0,15,12,12,0,2);//disable voxels in interval
    sculptor.cutBox(0,15,12,12,13,15);//disable voxels in interval

    sculptor.cutBox(0,15,11,11,0,1);//disable voxels in interval
    sculptor.cutBox(0,15,11,11,14,15);//disable voxels in interval

    sculptor.cutBox(0,15,9,10,0,0);//disable voxels in interval
    sculptor.cutBox(0,15,9,10,15,15);//disable voxels in interval

    sculptor.cutBox(0,15,0,5,0,0);//disable voxels in interval
    sculptor.cutBox(0,15,0,5,15,15);//disable voxels in interval

    sculptor.cutBox(0,15,4,4,0,3);//disable voxels in interval
    sculptor.cutBox(0,15,4,4,12,15);//disable voxels in interval

    sculptor.cutBox(0,15,3,3,1,1);//disable voxels in interval
    sculptor.cutBox(0,15,3,3,14,14);//disable voxels in interval

    sculptor.cutBox(0,15,0,0,1,1);//disable voxels in interval
    sculptor.cutBox(0,15,0,0,14,14);//disable voxels in interval

    sculptor.cutBox(0,15,0,0,7,8);//disable voxels in interval

    sculptor.setColor(0.0,0.0,0.0,1.0);//change color to black
    sculptor.putBox(0,15,0,3,1,14);//character's feet

    sculptor.setColor(0.9,0.7,0.6,0.8);//change color to light pink
    sculptor.putBox(0,15,5,5,5,10);//character's body
    sculptor.putBox(0,15,3,4,4,11);//character's body
    sculptor.putBox(0,15,2,2,6,9);//character's body
    sculptor.putBox(0,15,1,1,7,8);//character's body

    sculptor.putBox(0,15,7,10,4,6);//character's eye
    sculptor.putBox(0,15,7,10,9,11);//character's eye

    sculptor.setColor(0.0,0.0,0.0,1.0);//change color to black
    sculptor.putBox(0,15,8,10,5,5);//character's eye
    sculptor.putBox(0,15,8,10,10,10);//character's eye
    sculptor.putBox(0,15,9,9,6,9);//character's eye

    sculptor.putBox(0,15,11,11,3,4);//character's left eyebrow
    sculptor.putBox(0,15,11,11,11,12);//character's right eyebrow

    sculptor.setColor(0.6,0.3,0.0,0.8);//change color to brown
    sculptor.putBox(0,15,10,10,6,9);//finishes the character's eye

    sculptor.writeOFF("sculptor.off");//create the file
    return 0;
}