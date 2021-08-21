#include "vector3.h"

class CVector4
	{
	public:
	float X, Y, Z, W;

	CVector4(void): X(0), Y(0), Z(0), W(0) {};
	CVector4(float NewX, float NewY, float NewZ, float inW): X(NewX), Y(NewY), Z(NewZ), W(inW) {};
	CVector4(const CVector4 &V1): X(V1.X), Y(V1.Y), Z(V1.Z), W(V1.W) {};
	explicit CVector4(const CVector3 &V1): X(V1.X), Y(V1.Y), Z(V1.Z), W(0.0F) {};
	explicit CVector4(const CVector2 &V1): X(V1.X), Y(V1.Y), Z(0.0F), W(0.0F) {};

	// Operadores internos
	float &operator [] (unsigned int Index){
            return *(&X+Index);
            }
	const float &operator [] (unsigned int Index) const {
	        return *(&X+Index);
            }
	CVector4 &operator =  (const CVector3 &V1){
            X = V1.X;
	        Y = V1.Y;
	        Z = V1.Z;
	        W = 0.0F;
	        return *this;
            }
	CVector4 &operator =  (const CVector2 &V1){
            X = V1.X;
	        Y = V1.Y;
	        Z = 0.0F;
	        W = 0.0F;
	        return *this;
            }
	CVector4 &operator += (const CVector4 &V1){
 	        X += V1.X;
	        Y += V1.Y;
	        Z += V1.Z;
	        W += V1.W;
         	return *this;
            }
	CVector4 &operator -= (const CVector4 &V1){
            X -= V1.X;
	        Y -= V1.Y;
	        Z -= V1.Z;
         	W -= V1.W;
            }
	CVector4 &operator *= (float Value){
            X *= Value;
	        Y *= Value;
	        Z *= Value;
	        W *= Value;
            }
	CVector4 &operator /= (float Value){
            X /= Value;
	        Y /= Value;
	        Z /= Value;
            W /= Value;
	        return *this;
            }

	bool operator == (const CVector4 &Other){
            return((X == Other.X) && (Y == Other.Y) && (Z == Other.Z) && (W == Other.W));
            }
	bool operator != (const CVector4 &Other){
            return((X != Other.X) || (Y != Other.Y) || (Z != Other.Z) || (W != Other.W));
            }
	CVector4 operator - (void){
            return CVector4(-X, -Y, -Z, -W);
            }
	CVector4 operator + (const CVector4 &Other){
            CVector4 Return(*this);
	        Return += Other;
            return Return;
            }
	CVector4 operator - (const CVector4 &Other){
            CVector4 Return(*this);
	        Return -= Other;
            return Return;
            }
	CVector4 operator * (float Value){
            return CVector4(Value * X, Value * Y, Value * Z, Value * W);
            }
	CVector4 operator / (float Value){
            return CVector4(X / Value, Y / Value, Z / Value, W / Value);
            }

	// Operadores externos
	friend bool operator == (const CVector4 &V1, const CVector4 &V2){
           	return((V1.X == V2.X) && (V1.Y == V2.Y) && (V1.Z == V2.Z) && (V1.W == V2.W));
           }
	friend bool operator != (const CVector4 &V1, const CVector4 &V2){
           return((V1.X != V2.X) || (V1.Y != V2.Y) || (V1.Z != V2.Z) || (V1.W != V2.W));
           }
	friend CVector4 operator - (const CVector4 &V1){
           return CVector4(-V1.X, -V1.Y, -V1.Z, -V1.W);
           }
	friend CVector4 operator + (const CVector4 &V1, const CVector4 &V2){
           	CVector4 Return(V1);
	        Return += V2;
	        return Return;
           }
	friend CVector4 operator - (const CVector4 &V1, const CVector4 &V2){
           CVector4 Return(V1);
           Return -= V2;
	       return Return;
           }
	friend CVector4 operator * (const CVector4 &V1, float Value){
           return CVector4(Value * V1.X, Value * V1.Y, Value * V1.Z, Value * V1.W);
           }
	friend CVector4 operator * (float Value, const CVector4 &V1){
           return CVector4(Value * V1.X, Value * V1.Y, Value * V1.Z, Value * V1.W);
           }
	friend CVector4 operator / (const CVector4 &V1, float Value){
           return CVector4(V1.X / Value, V1.Y / Value, V1.Z / Value, V1.W / Value);
           }

	// Funcoes
	void Set(float NewX, float NewY, float NewZ, float NewW){
           X = NewX;
	       Y = NewY;
	       Z = NewZ;
	       W = NewW;
           }
	float Length(void) const{
           return(float) sqrt(X*X + Y*Y + Z*Z + W*W);
           }
	float LengthSqr(void) const{
           return(X*X + Y*Y + Z*Z + W*W);
           }
	bool IsZero(void) const {
           return((X == 0.0F) && (Y == 0.0F) && (Z == 0.0F) && (W == 0.0F));
           }
	CVector4&Normalize(void){
           float m = Length();
           if (m > 0.0F)
	          m = 1.0F / m;
           else
	          m = 0.0F;
	       X *= m;
	       Y *= m;
	       Z *= m;
	       W *= m;
	       return *this;
           }
	};
