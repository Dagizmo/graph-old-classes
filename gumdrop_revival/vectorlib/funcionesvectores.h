#include "vector4.h"

CVector2 Normalized(const CVector2 &V1){
         CVector2 Result(V1);
	     return Result.Normalize();
         }
CVector3 Normalized(const CVector3 &V1) {
         CVector3 Result(V1);
	     return Result.Normalize();
         }
CVector4 Normalized(const CVector4 &V1){
         CVector4 Result(V1);
         return Result.Normalize();
         }
float DotProduct(const CVector2 &V1, const CVector2 &V2){
      return V1.X*V2.X + V1.Y*V2.Y;
      }
float DotProduct(const CVector3 &V1, const CVector3 &V2){
      return V1.X*V2.X + V1.Y*V2.Y + V1.Z*V2.Z;
      }
float DotProduct(const CVector4 &V1, const CVector4 &V2){
      return V1.X*V2.X + V1.Y*V2.Y + V1.Z*V2.Z + V1.W*V2.W;
      }
void SwapVec(CVector2 &V1, CVector2 &V2){
     CVector2 Temp(V1);
	 V1 = V2;
	 V2 = Temp;
     }
void SwapVec(CVector3 &V1, CVector3 &V2){
     CVector3 Temp(V1);
	 V1 = V2;
     V2 = Temp;
     }
void SwapVec(CVector4 &V1, CVector4 &V2){
     CVector4 Temp(V1);
     V1 = V2;
	 V2 = Temp;
     }
CVector3 CrossProduct(const CVector3 &V1, const CVector3 &V2){
      return CVector3(V1.Y*V2.Z - V1.Z*V2.Y, V1.Z*V2.X - V1.X*V2.Z, V1.X*V2.Y - V1.Y*V2.X);
      }
bool NearlyEquals(const CVector2 &V1, const CVector2 &V2, float Radius){
      CVector2 Difference = V1 - V2;
	  return(DotProduct(Difference, Difference) < Radius*Radius);
     }
bool NearlyEquals(const CVector3 &V1, const CVector3 &V2, float Radius){
     CVector3 Difference = V1 - V2;
	 return(DotProduct(Difference, Difference) < Radius*Radius);
     }
bool NearlyEquals(const CVector4 &V1, const CVector4 &V2, float Radius){
     CVector4 Difference = V1 - V2;
     return(DotProduct(Difference, Difference) < Radius*Radius);
     }
