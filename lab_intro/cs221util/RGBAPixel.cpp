#include "RGBAPixel.h"


using namespace cs221util; 

    RGBAPixel::RGBAPixel(){
        r = 255;
        g =   255;
        b =   255;
        a = 1.0;


    };
    RGBAPixel::RGBAPixel(unsigned char r, unsigned char g,unsigned char b){
       this->r =   r;
       this->g =   g;
       this->b =   b;
       this->a = 1.0;

    };
    RGBAPixel::RGBAPixel(unsigned char r, unsigned char g, unsigned char b, double alpha){
       this->r =   r;
       this->g =   g;
       this->b =   b;
       this->a = alpha;

    };

