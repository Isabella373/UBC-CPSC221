#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
/* YOUR CODE HERE */
if(data.size()==0){
    return 0;
}
return data[0].size();
}
int Block::height() const
{
/* YOUR CODE HERE */
return data.size();
}

void Block::render(PNG &im, int column, int row) const
{
/* YOUR CODE HERE */
for(int i=0;i<height(); i++){
    for(int j=0;j<width(); j++){
        *(im.getPixel(column+j,row+i))= data[i][j];
    }
}
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* YOUR CODE HERE */
data.resize(height);
for(int i=0; i<height; i++){
    data[i].resize(width);
}
for(int i=0; i<height;i++){
    for(int j=0;j<width; j++){
        data[i][j] = *(im.getPixel(column+j,row+i));
    }
}
}

void Block::flipVert(){
if(height() == 1 || height()==0){
    return;
}
int horizon = (height())/2;
for(int i = 0; i<horizon; i++){
    for(int j = 0;j<width();j++){
        RGBAPixel swap = data[i][j];
        data[i][j] = data[height()-i-1][j];
        data[height()-i-1][j] = swap;
    }
}
}

void Block::flipHoriz(){
    if(width() == 1||width() == 0){
    return;
}
    int vertical = (width())/2;
    for(int j = 0; j<vertical;j++){
        for(int i = 0;i<height();i++){
            RGBAPixel swap = data[i][j];
            data[i][j] = data[i][width()-j-1];
            data[i][width()-j-1] =swap;
        }
    }
}

void Block::rotateRight()
{
/* YOUR CODE HERE */
flipVert();
for(int i = 0; i<height(); i++){
    for(int j = i+1; j<width();j++){
        RGBAPixel swap = data[i][j];
        data[i][j] = data[j][i];
        data[j][i] = swap;

    }
}
}
