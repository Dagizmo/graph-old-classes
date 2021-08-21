

class CVector2
	{
	public:
	float X, Y;

	public:
	CVector2(void): X(0),Y(0) {};
	CVector2(float NewX, float NewY): X(NewX), Y(NewY) {}
	CVector2(const CVector2 &Other): X(Other.X), Y(Other.Y) {}

	public:
	// Operadores internos
	float &operator [] (unsigned int Position){
            return *(&X+Position);
            }

	const float &operator [] (unsigned int Position) const {
	        return *(&X+Position);
          }

	CVector2 &operator += (const CVector2 &Other){
	         X += Other.X;
         	 Y += Other.Y;
             return *this;
             }
	CVector2 &operator -= (const CVector2 &Other) {
 	         X -= Other.X;
	         Y -= Other.Y;
	         return *this;
             }
	CVector2 &operator *= (float Value) {
             X *= Value;
	         Y *= Value;
	         return *this;
             }
	CVector2 &operator /= (float Value){
	         X /= Value;
	         Y /= Value;
             return *this;
             }

	bool operator == (const CVector2 &Other) {
             return ((X == Other.X) && (Y == Other.Y));
             }
	bool operator != (const CVector2 &Other){
             return((X != Other.X) || (Y != Other.Y));
             }
	CVector2 operator - (void){
             return CVector2(-X, -Y);
             }
	CVector2 operator + (const CVector2 &Other){
             CVector2 Return(*this);
             Return += Other;
             return Return;
             }
	CVector2 operator - (const CVector2 &Other){
 	         CVector2 ReturnValue(*this);
	         ReturnValue -= Other;
	         return ReturnValue;
             }
	CVector2 operator * (float Value){
             return CVector2(Value * X, Value * Y);
             }
	CVector2 operator / (float Value){
             return CVector2(X / Value, Y / Value);
             }


	// externos
	friend bool operator == (const CVector2 &V1, const CVector2 &V2) {
	       return ((V1.X == V2.X) && (V1.Y == V2.Y));
           }
	friend bool operator != (const CVector2 &V1, const CVector2 &V2){
           return((V1.X != V2.X) || (V1.Y != V2.Y));
           }
	friend CVector2 operator - (const CVector2 &V1){
           return CVector2(-V1.X, -V1.Y);
           }
	friend CVector2 operator + (const CVector2 &V1, const CVector2 &V2){
           	CVector2 Return(V1);
	        Return += V2;
	        return Return;
           }
	friend CVector2 operator - (const CVector2 &V1, const CVector2 &V2){
           	CVector2 ReturnValue(V1);
	        ReturnValue -= V2;
	        return ReturnValue;
           }
	friend CVector2 operator * (const CVector2 &V1, float Value){
           return CVector2(Value * V1.X, Value * V1.Y);
           }
	friend CVector2 operator * (float Value, const CVector2 &V1){
           return CVector2(Value * V1.X, Value * V1.Y);
           }
	friend CVector2 operator / (const CVector2 &V1, float Value){
           return CVector2(V1.X / Value, V1.Y / Value);
           }

	// Funções
	void Set(float NewX, float NewY){
           X = NewX;
	       Y = NewY;
                             }
	float Length(void) const {
           return(float) sqrt(X*X + Y*Y);
           }
	float LengthSqr(void) const{
          return(X*X + Y*Y);
          }
	bool IsZero(void) const {
            return((X == 0.0F) && (Y == 0.0F));
            }
	CVector2 &Normalize(void){
            float Temp = Length();
	        if (Temp > 0.0F)
	        	Temp = 1.0F / Temp;
	         else
	         	Temp = 0.0F;
	          X *= Temp;
	          Y *= Temp;
	          return *this;
	          }
	};
