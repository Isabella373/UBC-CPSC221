#ifndef CS221UTIL_RGBAPixel_H
#define CS221UTIL_RGBAPixel_H
namespace cs221util {
class RGBAPixel{

    public:


    unsigned char r;
    unsigned char g;
    unsigned char b;
    double a;
    
    RGBAPixel();
    RGBAPixel(unsigned char r, unsigned char g,unsigned char b);
    RGBAPixel(unsigned char r, unsigned char g, unsigned char b, double alpha);

};
}

#endif
