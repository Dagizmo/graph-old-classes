#include "libreriavector.h"
#include <math.h>

#ifdef USE_MATRIX_INLINE
#define DECL inline
#else
#define DECL
#endif

class CMatrix33 
	{
	public:
	CVector3       Column[3];

	CMatrix33(void) {
                    Identity();
                    }
	CMatrix33(float V1){
                    Column[0].Set(V1, V1, V1);
	                Column[1].Set(V1, V1, V1);
	                Column[2].Set(V1, V1, V1);
                    }
	CMatrix33(const CMatrix33 &Matrix){
                    Column[0] = Matrix[0];
	                Column[1] = Matrix[1];
	                Column[2] = Matrix[2];
                    }
	CMatrix33(const CVector3 &V1, const CVector3 &V2, const CVector3 &V3){
                    Column[0] = V1;
	                Column[1] = V2;
	                Column[2] = V3;
                    }

	// Operadores internos
	DECL CVector3 &operator [] (unsigned int Index){
                    assert (Index<3);
	                return (CVector3&) Column[Index];
                    }
	DECL const CVector3 &operator [] (unsigned int Index) const{
               	    assert (Index<3);
	                return (CVector3&) Column[Index];
                    }
	DECL CMatrix33 &operator =  (const CMatrix33 &Matrix) {
                    Column[0] = Matrix[0];
	                Column[1] = Matrix[1];
	                Column[2] = Matrix[2];
	                return *this;
                    }
	DECL CMatrix33 &operator += (const CMatrix33 &Matrix){
                 	Column[0] += Matrix[0];
	                Column[1] += Matrix[1];
	                Column[2] += Matrix[2];
	                return *this;
                    }
	DECL CMatrix33 &operator -= (const CMatrix33 &Matrix){
                    Column[0] -= Matrix[0];
	                Column[1] -= Matrix[1];
	                Column[2] -= Matrix[2];
	                return *this;
                    }
	DECL CMatrix33 &operator *= (const CMatrix33 &Matrix){
         CMatrix33 Temp;
         for (unsigned int Row = 0; Row < 3; Row++) {
		       for (unsigned int Col = 0; Col < 3; Col++) {
               float Float = 0;
			   Float += Column[0][Row] * Matrix[Col][0];
			   Float += Column[1][Row] * Matrix[Col][1];
			   Float += Column[2][Row] * Matrix[Col][2];
               Temp[Col][Row] = Float;
			}
		}
		*this = Temp;
        }
	DECL CMatrix33 &operator *= (float Float){
         Column[0] *= Float;
	     Column[1] *= Float;
	     Column[2] *= Float;
	     return *this;
         }

	// Operadores externos
	friend DECL bool operator == (const CMatrix33 &V1, const CMatrix33 &V2){
           return((V1[0] == V2[0]) && (V1[1] == V2[1]) && (V1[2] == V2[2]));
           }
	friend DECL bool operator != (const CMatrix33 &V1, const CMatrix33 &V2){
           return((V1[0] != V2[0]) || (V1[1] != V2[1]) || (V1[2] != V2[2]));
           }
	friend DECL CMatrix33 operator + (const CMatrix33 &V1, const CMatrix33 &V2){
           CMatrix33 Return(V1);
           Return += V2;
	       return Return;
           }
	friend DECL CMatrix33 operator - (const CMatrix33 &V1, const CMatrix33 &V2){
           	CMatrix33 Return(V1);
	        Return -= V2;
	        return Return;
           }
	friend DECL CMatrix33 operator * (const CMatrix33 &V1, const CMatrix33 &V2){
           	CMatrix33 Return(V1);
	        Return *= V2;
	        return Return;
           }
	friend DECL CVector3 operator * (const CMatrix33 &Matrix, const CVector3 &V1){
	       CVector3 Return;
	       Return.X = V1.X * Matrix[0][0] + V1.Y * Matrix[1][0] + V1.Z * Matrix[2][0];
	       Return.Y = V1.X * Matrix[0][1] + V1.Y * Matrix[1][1] + V1.Z * Matrix[2][1];
           Return.Z = V1.X * Matrix[0][2] + V1.Y * Matrix[1][2] + V1.Z * Matrix[2][2];
	       return Return;
           }
	friend DECL CVector3 operator * (const CVector3 &V1, const CMatrix33 &Matrix){
	       CVector3 Return;
	       Return.X = DotProduct(Matrix[0], V1);
	       Return.Y = DotProduct(Matrix[1], V1);
	       Return.Z = DotProduct(Matrix[2], V1);
	       return Return;
           }
	friend DECL CMatrix33 operator * (const CMatrix33 &Matrix, float Float){
           	CMatrix33 Return(Matrix);
	        Return *= Float;
	        return Return;
           }
	friend DECL CMatrix33 operator * (float Float, const CMatrix33 &Matrix){
           	CMatrix33 Return(Matrix);
	        Return *= Float;
	        return Return;
           }

	// Funcoes
	DECL CMatrix33 &Initialize(float Value){
         	Column[0].Set(Value,Value,Value);
            Column[1].Set(Value,Value,Value);
	        Column[2].Set(Value,Value,Value);
         }
	DECL CMatrix33 &Identity(void) {
         	Column[0].Set(1.0, 0.0, 0.0);
	        Column[1].Set(0.0, 1.0, 0.0);
            Column[2].Set(0.0, 0.0, 1.0);
	        return *this;
         }
	DECL CMatrix33 &Transpose(void){
         	float Temp;
	for (unsigned int Col = 0; Col < 3; Col++)
		{
		for (unsigned int Row = Col + 1; Row < 3; Row++)
			{
			Temp = Column[Col][Row];
			Column[Col][Row] = Column[Row][Col];
			Column[Row][Col] = Temp;
			} 
		}
	return *this;
         }
	DECL CMatrix33 &Invert(void) {
	CMatrix33 V1(*this);
	CMatrix33 V2(IdentityMatrix33());

	unsigned int Col, Row;
	unsigned int cc;
	unsigned int RowMax;
	unsigned int row;
	float tmp;

	// Go through columns
	for (Col=0; Col<3; Col++)
		{
		RowMax = Col;
		for (Row=Col+1; Row<3; Row++)
			{
			if (fabs(V1[Col][Row]) > fabs(V1[Col][RowMax]))
				{
				RowMax = Row;
				}
			}

		// If the max value here is 0, we can't invert.  Return identity.
		if (V1[RowMax][Col] == 0.0F)
			return (Identity());

		// Swap row "RowMax" with row "Col"
		for (cc=0; cc<3; cc++)
			{
			tmp = V1[cc][Col];
			V1[cc][Col] = V1[cc][RowMax];
			V1[cc][RowMax] = tmp;
			tmp = V2[cc][Col];
			V2[cc][Col] = V2[cc][RowMax];
			V2[cc][RowMax] = tmp;
			}

		// Now everything we do is on row "Col".
		// Set the max cell to 1 by dividing the entire row by that value
		tmp = V1[Col][Col];
		for (cc=0; cc<3; cc++)
			{
			V1[cc][Col] /= tmp;
			V2[cc][Col] /= tmp;
			}

		// Now do the other rows, so that this column only has V1 1 and 0's
		for (row = 0; row < 3; row++)
			{
			if (row != Col)
				{
				tmp = V1[Col][row];
				for (cc=0; cc<3; cc++)
					{
					V1[cc][row] -= V1[cc][Col] * tmp;
					V2[cc][row] -= V2[cc][Col] * tmp;
					}
				}
			}
		}

	*this = V2;
	return *this;         
         }
	};

DECL CMatrix33    IdentityMatrix33(){
     	{
	CMatrix33 Return;
	return Return.Identity();
     }
DECL CMatrix33    TransposeMatrix33(const CMatrix33 &Matrix){
     	CMatrix33 Return(Matrix);
        return Return.Transpose();
     };
DECL CMatrix33    InvertMatrix33(const CMatrix33 &Matrix){
     	CMatrix33 Return(Matrix);

	return Return.Invert();
     }
DECL CMatrix33    RotateRadMatrix33(float Radians){
     	CMatrix33 Return;
	float sinA, cosA;

	sinA = (float)sin(rad);
	cosA = (float)cos(rad);

	Return[0][0] = cosA; Return[1][0] = -sinA; Return[2][0] = 0.0F;
	Return[0][1] = sinA; Return[1][1] =  cosA; Return[2][1] = 0.0F;
	Return[0][2] = 0.0F; Return[1][2] =  0.0F; Return[2][2] = 1.0F;

	return Return;
     }
DECL CMatrix33    TranslateMatrix33(float X, float Y){
     	CMatrix33 Return;

	Return.Identity();
	Return[2][0] = X;
	Return[2][1] = Y;

	return Return;
     }
DECL CMatrix33    ScaleMatrix33(float X, float Y, float Z = 1.0){
     	CMatrix33 Return;

	Return.Identity();
	Return[0][0] = X;
	Return[1][1] = Y;
	Return[2][2] = Z;

	return Return;
     }
     