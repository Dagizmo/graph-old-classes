#include "libreriavector.h"
#include "matriz33.h"
#include <math.h>

#ifdef USE_MATRIX_INLINE
#define DECL inline
#else
#define DECL
#endif
class CMatrix44 
	{
	public:
	CVector4 Column[4];

	CMatrix44(void) {
	                Identity();
                    }
	CMatrix44(float Value){
                    Column[0].Set(Value, Value, Value, Value);
                    Column[1].Set(Value, Value, Value, Value);
                    Column[2].Set(Value, Value, Value, Value);
                    Column[3].Set(Value, Value, Value, Value);
                    }
	CMatrix44(const CMatrix44 &Other){
                    Column[0] = Other[0];
                    Column[1] = Other[1];
                    Column[2] = Other[2];
                    Column[3] = Other[3];
                    }
	CMatrix44(const CVector4 &V0,const CVector4 &V1,const CVector4 &V2, const CVector4 &V3){
                    Column[0] = V0;
                    Column[1] = V1;
                    Column[2] = V2;
                    Column[3] = V3;
                    }
	explicit CMatrix44(const CMatrix33 &Other){
                    Column[0] = Other[0];
                    Column[1] = Other[1];
                    Column[2] = Other[2];
                    Column[3].Set(0.0, 0.0, 0.0, 1.0);
                    }

	// Operadores internos
	DECL CVector4            &operator [] (unsigned int Index){
            assert (Index<4);
            return Column[Index];
         }
	DECL const CVector4      &operator [] (unsigned int Index) const{
         	assert (Index<4);
	        return Column[Index];
         }
	DECL CMatrix44           &operator =  (const CMatrix44 &Other){
         	Column[0] = Other[0];
	        Column[1] = Other[1];
	        Column[2] = Other[2];
	        Column[3] = Other[3];
         }
	DECL CMatrix44           &operator =  (const CMatrix33 &Other){
         	Column[0] = Other[0];
            Column[1] = Other[1];
	        Column[2] = Other[2];
	        Column[3].Set(0.0, 0.0, 0.0, 1.0);
	        return *this;
         }
	DECL CMatrix44           &operator += (const CMatrix44 &Other){
         	Column[0] += Other[0];
            Column[1] += Other[1];
	        Column[2] += Other[2];
	        Column[3] += Other[3];
	        return *this;
         }
	DECL CMatrix44           &operator -= (const CMatrix44 &Other){
         	Column[0] -= Other[0];
	        Column[1] -= Other[1];
	        Column[2] -= Other[2];
	        Column[3] -= Other[3];
	        return *this;
         }
	DECL CMatrix44           &operator *= (const CMatrix44 &Other){
         	CMatrix44 t;
	        for (unsigned int r = 0; r < 4; r++)
		    {
		        for (unsigned int c = 0; c < 4; c++)
			    {
			    float f = 0;

			    f += (Column[0][r] * Matrix[c][0]);
		     	f += (Column[1][r] * Matrix[c][1]);
			    f += (Column[2][r] * Matrix[c][2]);
		      	f += (Column[3][r] * Matrix[c][3]);
			    t[c][r] = f;
			}
		}
	*this = t;
	return *this;
         }
	DECL CMatrix44           &operator *= (float Float){
         	Column[0] *= Float;
	        Column[1] *= Float;
	        Column[2] *= Float;
         	Column[3] *= Float;
          	return *this;
            }
	DECL CMatrix44           &operator /= (float Float){
         	Column[0] /= Float;
	        Column[1] /= Float;
	        Column[2] /= Float;
	        Column[3] /= Float;
	        return *this;
         }

	// Operadores externos
	friend DECL bool         operator == (const CMatrix44 &V1, const CMatrix44 &V2){
           	return((V1[0] == V2[0]) && (V1[1] == V2[1]) &&(V1[2] == V2[2]) && (V1[3] == V2[3]));
           }
	friend DECL bool         operator != (const CMatrix44 &V1, const CMatrix44 &V2){
           	return((V1[0] != V2[0]) || (V1[1] != V2[1]) ||(V1[2] != V2[2]) || (V1[3] != V2[3]));
           }
	friend DECL CMatrix44    operator + (const CMatrix44 &V1, const CMatrix44 &V2){
           	CMatrix44 Return(V1);
	        Return += V2;
	        return Return;
           }
	friend DECL CMatrix44    operator - (const CMatrix44 &V1, const CMatrix44 &V2){
           	CMatrix44 ret(V1);
	        ret -= V2;
	        return ret;
           }
	friend DECL CMatrix44    operator * (const CMatrix44 &V1, const CMatrix44 &V2){
           	CMatrix44 ret(V1);
	        ret *= V2;
         	return ret;
           }
	friend DECL CVector3     operator * (const CMatrix44 &Other, const CVector3 &V1){
           	CVector4 ret(V1);
	        ret = Other * ret;
         	return CVector3(ret.X, ret.Y, ret.Z);
           }
	friend DECL CVector3     operator * (const CVector3 &V1, const CMatrix44 &Other){
           CVector4 ret(V1);
	       ret = ret * Other;
	       return CVector3(ret.X, ret.Y, ret.Z);
           }
	friend DECL CVector4     operator * (const CMatrix44 &Other, const CVector4 &V1){
           	CVector4 ret;
	        ret.X = V1.X * Other[0][0] + V1.Y * Other[1][0] + V1.Z * Other[2][0] + V1.W * Other[3][0];
	        ret.Y = V1.X * Other[0][1] + V1.Y * Other[1][1] + V1.Z * Other[2][1] + V1.W * Other[3][1];
         	ret.Z = V1.X * Other[0][2] + V1.Y * Other[1][2] + V1.Z * Other[2][2] + V1.W * Other[3][2];
          	ret.W = V1.X * Other[0][3] + V1.Y * Other[1][3] + V1.Z * Other[2][3] + V1.W * Other[3][3];
           	return ret;
           }
	friend DECL CVector4     operator * (const CVector4 &V1, const CMatrix44 &Other){
           	CVector4 ret;
	        ret.X = DotProduct(Other[0], V1);
	        ret.Y = DotProduct(Other[1], V1);
	        ret.Z = DotProduct(Other[2], V1);
         	ret.W = DotProduct(Other[3], V1);
	        return ret;
           }
	friend DECL CMatrix44    operator * (const CMatrix44 &Other, float f){
           	CMatrix44 ret(Other);
            ret *= f;
	        return ret;
           }
	friend DECL CMatrix44    operator * (float f, const CMatrix44 &Other){
           	CMatrix44 ret(Other);
            ret *= f;
            return ret;
           }

	DECL CMatrix44           &Identity(void){
         	Column[0].Set(1.0, 0.0, 0.0, 0.0);
	        Column[1].Set(0.0, 1.0, 0.0, 0.0);
	        Column[2].Set(0.0, 0.0, 1.0, 0.0);
         	Column[3].Set(0.0, 0.0, 0.0, 1.0);
	        return *this;
         }
	DECL CMatrix44           &Transpose(void){
         float t;

	     for (unsigned int c = 0; c < 4; c++)
	     	{
	      	for (unsigned int r = c + 1; r < 4; r++)
	       		{
		     	t = Column[c][r];
		      	Column[c][r] = Column[r][c];
		       	Column[r][c] = t;
			} 
		} 

	return *this;
         }
	DECL CMatrix44           &Invert(void){
         	CMatrix44 V1(*this);
	CMatrix44 V2(IdentityMatrix44());

	unsigned int r, c;
	unsigned int cc;
	unsigned int RowMax; // Points to max abs value row in this column
	unsigned int row;
	float tmp;

	// Go through columns
	for (c=0; c<4; c++)
		{
		// Find the row with max value in this column
		RowMax = c;
		for (r=c+1; r<4; r++)
			{
			if (fabs(V1[c][r]) > fabs(V1[c][RowMax]))
				{
				RowMax = r;
				}
			}

		// If the max value here is 0, we can't invert.  Return identity.
		if (V1[RowMax][c] == 0.0F)
		return(Identity());

		// Swap row "RowMax" with row "c"
		for (cc=0; cc<4; cc++)
			{
			tmp = V1[cc][c];
			V1[cc][c] = V1[cc][RowMax];
			V1[cc][RowMax] = tmp;
			tmp = V2[cc][c];
			V2[cc][c] = V2[cc][RowMax];
			V2[cc][RowMax] = tmp;
			}

		// Now everything we do is on row "c".
		// Set the max cell to 1 by dividing the entire row by that value
		tmp = V1[c][c];
		for (cc=0; cc<4; cc++)
			{
			V1[cc][c] /= tmp;
			V2[cc][c] /= tmp;
			}

		// Now do the other rows, so that this column only has V1 1 and 0's
		for (row = 0; row < 4; row++)
			{
			if (row != c)
				{
				tmp = V1[c][row];
				for (cc=0; cc<4; cc++)
					{
					V1[cc][row] -= V1[cc][c] * tmp;
					V2[cc][row] -= V2[cc][c] * tmp;
					}
				}
			}
		}

	*this = V2;

	return *this;
         }
	};