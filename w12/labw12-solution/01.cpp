#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Shape3D
{
public:
	virtual double volumn() = 0;                               
	virtual double surfaceArea() = 0;                          
};

class RightRectangularPyramid : public Shape3D                     
{                                                                  
      double width;                                                
      double length;                                               
      double height;                                               
public:                                                            
      RightRectangularPyramid(double width = 0,                    
                        double length = 0, double height = 0);     
      double volumn();                                             
      double surfaceArea();                                        
};                                                                 
                                                                   
class Sphere : public Shape3D                                      
{                                                                  
      double radius;                                               
public:                                                            
      Sphere(double radius = 0);                                   
      double volumn();                                             
      double surfaceArea();                                        
};                                                                 
                                                                   
RightRectangularPyramid::RightRectangularPyramid(                  
              double width, double length, double height)          
{                                                                  
      this->width = width;                                         
      this->length = length;                                       
      this->height = height;                                       
}                                                                  
                                                                   
double RightRectangularPyramid::volumn()                           
{                                                                  
      return (1.0/3) * width * length * height;                    
}                                                                  
                                                                   
double RightRectangularPyramid::surfaceArea()                      
{                                                                  
      double area = 0;                                             
      double slant;                                                
      slant = sqrt(0.25 * width * width + height * height);        
      area += length * slant;                                      
      slant = sqrt(0.25 * length * length + height * height);      
      area += width * slant;                                       
      area += width * length;                                      
      return area;                                                 
}                                                                  
                                                                   
Sphere::Sphere(double radius)                                      
{                                                                  
      this->radius = radius;                                       
}                                                                  
                                                                   
double Sphere::volumn()                                            
{                                                                  
      return (4.0/3) * M_PI * radius * radius * radius;            
}                                                                  
                                                                   
double Sphere::surfaceArea()                                       
{                                                                  
      return 4.0 * M_PI * radius * radius;                         
}                                                                  

int main()
{
	int tc;
	cin >> tc;
	if (tc == 1) {
		Shape3D **shapes = new Shape3D*[3];
		shapes[0] = new RightRectangularPyramid(1, 5.2, 7);
		shapes[1] = new Sphere(10.6);
		shapes[2] = new RightRectangularPyramid(3, 3.5, 4.13);
		for (int i = 0; i < 3; i++) {
			cout << "Volumn: " << (*shapes)->volumn() << endl;
			cout << "Surface Area: " << (*shapes)->surfaceArea() << endl;
			cout << "--------------------\n";
			*shapes++;
		}
	} else if (tc == 2) {
		RightRectangularPyramid rectangle;
		Sphere sphere;
		cout << rectangle.volumn() << endl;
		cout << rectangle.surfaceArea() << endl;
		cout << sphere.volumn() << endl;
		cout << sphere.surfaceArea() << endl;
	} else if (tc == 3) {
		RightRectangularPyramid rectangle(171.5, 45.33, 31.02);
		cout << rectangle.volumn() << endl;
		cout << rectangle.surfaceArea() << endl;
	} else if (tc == 4) {
		Sphere sphere(34.25);
		cout << sphere.volumn() << endl;
		cout << sphere.surfaceArea() << endl;
	} else if (tc == 5) {
		RightRectangularPyramid rectangle(171.5, 45.33, 31.02);
		Sphere sphere(34.25);
		Shape3D *shape = &rectangle;
		cout << shape->volumn() << " " << shape->surfaceArea() << endl;
		shape = &sphere;
		cout << shape->volumn() << " " << shape->surfaceArea() << endl;
	} else if(tc == 6) {
	Shape3D **shapes = new Shape3D*[4];
	shapes[0] = new RightRectangularPyramid(11.75, 5.2, 12.31);
	shapes[1] = new Sphere(7.11);
	shapes[2] = new RightRectangularPyramid(1.77, 0.342, 4.51);
     shapes[3] = new Sphere(91.715);
	for (int i = 0; i < 4; i++) {
		cout << "Volumn: " << (*shapes)->volumn() << endl;
		cout << "Surface Area: " << (*shapes)->surfaceArea() << endl;
		cout << "--------------------\n";
		*shapes++;
	}
	}

}