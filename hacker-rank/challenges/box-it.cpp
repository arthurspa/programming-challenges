
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
private:
    int l, b, h;

public:
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    
    Box(int l, int b, int h): l(l), b(b), h(h) {}
    
    Box(Box const & box){
        l = box.l;
        b = box.b;
        h = box.h;
    }
    
    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }
    long long CalculateVolume() { return (long long)l*b*h; }
    
    bool operator<(Box& box){
        if( (l < box.l) ||
          (b < box.b && l == box.l) ||
          (h < box.h && l == box.l && b == box.b))
            return true;
        
        return false;
    }
    
    friend ostream& operator<<(ostream& out, Box& box){
        out << box.l << " " << box.b << " " << box.h;
        
        return out;
    }
};