#include "vector2.h"

class CVector3
	{
	public:
	float X, Y, Z;

	CVector3(void): X(0),Y(0),Z(0) {};
	CVector3(float NewX, float NewY, float NewZ): X(NewX), Y(NewY), Z(NewZ) {};
	CVector3(const CVector3 &V1): X(V1.X), Y(V1.Y), Z(V1.Z) {};
	explicit CVector3(const CVector2 &V1): X(V1.X), Y(V1.Y), Z(0.0F) {};

	// Operadores internos
	float &operator [] (unsigned int Index) {
	      return *(&X+Index);
          }
	const float &operator [] (unsigned int Index) const{
          return *(&X+Index);
          }
	CVector3 &operator =  (const CVector2 &V1){
          	X = V1.X;
           	Y = V1.Y;
           	Z = 0.0F;
            return *this;
           }
	CVector3                 &operator += (const CVector3 &V1){
           	X += V1.X;
	        Y += V1.Y;
         	Z += V1.Z;
	        return *this;
           }
	CVector3  &operator -= (const CVector3 &V1){
	        X -= V1.X;
          	Y -= V1.Y;
	        Z -= V1.Z;
        	return *this;
            }
	CVector3   &operator *= (float Scalar){
            X *= Scalar;
	        Y *= Scalar;
	        Z *= Scalar;
	        return *this;
            }
	CVector3 &operator /= (float Scalar){
            X /= Scalar;
            Y /= Scalar;
            Z /= Scalar;
            return *this;
            }

	bool operator == (const CVector3 &V1){
            return((X == V1.X) && (Y == V1.Y) && (Z == V1.Z));
            }
	bool operator != (const CVector3 &V1){
            return((X != V1.X) || (Y != V1.Y) || (Z != V1.Z));
            }
	CVector3 operator - (void){
            return CVector3(-X, -Y, -Z);
            }
	CVector3 operator + (const CVector3 &V1){
            CVector3 Return(*this);
	        Return += V1;
	        return Return;
            }
	CVector3 operator - (const CVector3 &V1){
            CVector3 Return(*this);
	        Return -= V1;
	        return Return;
            }
	CVector3 operator * (float Scalar){
            return CVector3(Scalar * X, Scalar * Y, Scalar * Z);
             }
	CVector3 operator / (float Scalar) {
             return CVector3(X / Scalar, Y / Scalar, Z / Scalar);
             }

	//externos
	friend bool operator == (const CVector3 &V1, const CVector3 &V2){
             return((V1.X == V2.X) && (V1.Y == V2.Y) && (V1.Z == V2.Z));
             }
	friend bool operator != (const CVector3 &V1, const CVector3 &V2){
             return((V1.X != V2.X) || (V1.Y != V2.Y) || (V1.Z != V2.Z));
             }
	friend CVector3 operator - (const CVector3 &V1) {
             return CVector3(-V1.X, -V1.Y, -V1.Z);
            }
	friend CVector3 operator + (const CVector3 &V1, const CVector3 &V2){
           	CVector3 Return(V1);
	        Return += V2;
	        return Return;
           }
	friend CVector3 operator - (const CVector3 &V1, const CVector3 &V2){
           	CVector3 Return(V1);
            Return -= V2;
	        return Return;
           }
	friend CVector3 operator * (const CVector3 &V1, float Value){
           return CVector3(Value * V1.X, Value * V1.Y, Value * V1.Z);
           }
	friend CVector3 operator * (float Value, const CVector3 &V1){
           return CVector3(Value * V1.X, Value * V1.Y, Value * V1.Z);
           }
	friend CVector3 operator / (const CVector3 &V1, float Value){
           return CVector3(V1.X / Value, V1.Y / Value, V1.Z / Value);
           }
	void Set(float NewX, float NewY, float NewZ){
           X = NewX;
           Y = NewY;
           Z = NewZ;
           }
	float Length(void) const{
           return(float) sqrt(X*X + Y*Y + Z*Z);
           }
	float LengthSqr(void) const{
           return(X*X + Y*Y + Z*Z);
           }
	bool IsZero(void) const{
           return((X == 0.0F) && (Y == 0.0F) && (Z == 0.0F));
           }
	CVector3 &Normalize(void){
           float temp = Length();
	       if (temp > 0.0F)
        		temp = 1.0F / temp;
          	else
           		temp = 0.0F;
            X *= temp;
            Y *= temp;
            Z *= temp;
            return *this;
            }
	};
