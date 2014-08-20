// globalna wartość PI
const double PI = 3.141592;
const double T_PI = PI * 2.0;
const double EPSILON = 0.001;

/**
 * @struct vector2f
 * @brief Struktura przechowująca współrzędne wektora w 2d
 */
class vector2f
{
    ///wspolrzedna x
    GLfloat x;
    ///wspolrzedna y
    GLfloat y;

public:
    /**
     * @brief Domyslny konstruktor
     * Ustawia wszystkie wspolrzedne na ( 0, 0, 0 )
     */
    vector2f( void ) 
		: x( .0f ), y( .0f ) {}

    /**
     * @brief Konstruktor ustawiajacy wspolrzedne
     * @param in_x wspolrzedna x
     * @param in_y wspolrzedna y
     * @param in_z wspolrzedna z
     */
    vector2f( GLfloat in_x, GLfloat in_y )
        : x( in_x ), y( in_y ) {}
};


/**
 * @struct vector3f
 * @brief Struktura przechowująca współrzędne wektora
 */
struct vector3f
{

    /**
     * @brief Domyslny konstruktor
     * Ustawia wszystkie wspolrzedne na ( 0, 0, 0 )
     */
    vector3f( void ) : x( .0f ), y( .0f ), z( .0f )
    {
    }

    /**
     * @brief Konstruktor ustawiajacy wspolrzedne
     * @param in_x wspolrzedna x
     * @param in_y wspolrzedna y
     * @param in_z wspolrzedna z
     */
    vector3f( GLfloat in_x, GLfloat in_y, GLfloat in_z )
        : x( in_x ), y( in_y ), z( in_z )
    {
    }

    /**
     * @brief normalizacja wektora
     * @return znormalizowany wektor
     */
    vector3f normalize( void ) const
    {
        GLfloat len = length();
        assert( len > 0 );

        GLfloat one_div_len = 1.0f / len;

        return vector3f(
            x * one_div_len,
            y * one_div_len,
            z * one_div_len );
    }

    /**
     * @brief obliczanie iloczynu skalarnego
     */
    float dot( const vector3f& in ) const
    {
        return x * in.x + y * in.y + z * in.z;
    }

    /**
     * @brief operator -
     */
    vector3f operator-( const vector3f& in ) const
    {
        return vector3f( x - in.x, y - in.y, z - in.z );
    }

    /**
     * @brief operator +
     */
    vector3f operator+( const vector3f& in ) const
    {
        return vector3f( x + in.x, y + in.y, z + in.z );
    }

    /**
     * @brief operator -
     */
    vector3f operator-( float scalar ) const
    {
        return vector3f( x - scalar, y - scalar, z - scalar );
    }

    /**
     * @brief operator +
     */
    vector3f operator+( float scalar ) const
    {
        return vector3f( x + scalar, y + scalar, z + scalar );
    }

    /**
     * @brief operator *
     */
    vector3f operator*( float scalar ) const
    {
        return vector3f( x * scalar, y * scalar, z * scalar );
    }

    /**
     * @brief operator /
     */
    vector3f operator/( float scalar ) const
    {
        return vector3f( x / scalar, y / scalar, z / scalar );
    }

    /**
     * @brief operator -
     */
    vector3f operator-( void ) const
    {
        return vector3f( -x, -y, -z );
    }

    /**
     * @brief operator -=
     */
    vector3f& operator-=( const vector3f& in )
    {
        x -= in.x;
        y -= in.y;
        z -= in.z;
        return *this;
    }

    /**
     * @brief operator +=
     */
    vector3f& operator+=( const vector3f& in )
    {
        x += in.x;
        y += in.y;
        z += in.z;
        return *this;
    }

    /**
     * @brief liczenie dlugosci wektora
     * @return dlugosc wektora
     */
    GLfloat length( void ) const
    {
        return sqrtf( x * x + y * y + z * z );
    }

    /**
     * @brief odbicie wektora względem podanego wektora normalnego
     */
    vector3f reflect( const vector3f normal )
    {
        vector3f ret( *this );
        ret = *this - normal * 2 * ( normal.dot( *this ) );
        return ret;
    }

    ///wspolrzedna x
    GLfloat x;
    ///wspolrzedna y
    GLfloat y;
    ///wspolrzedna z
    GLfloat z;
};

/**
 * @struct vector4f
 * @brief Struktura przechowująca współrzędne wektora ( czterowymiarowego )
 */
struct vector4f
{

    /**
     * @brief Domyslny konstruktor
     * Ustawia wszystkie wspolrzedne na ( 0, 0, 0, 0 )
     */
    vector4f( void ) : x( .0f ), y( .0f ), z( .0f ), w( .0f )
    {
    }

    /**
     * @brief Konstruktor ustawiajacy wspolrzedne
     * @param in_x wspolrzedna x
     * @param in_y wspolrzedna y
     * @param in_z wspolrzedna z
     * @param in_w wspolrzedna w
     */
    vector4f( GLfloat in_x, GLfloat in_y, GLfloat in_z, GLfloat in_w )
        : x( in_x ), y( in_y ), z( in_z ), w( in_w )
    {
    }

    ///wspolrzedna x
    GLfloat x;
    ///wspolrzedna y
    GLfloat y;
    ///wspolrzedna z
    GLfloat z;
    ///wspolrzedna w
    GLfloat w;
};

/**
 * @struct vertex3f
 * @brief Struktura opisujaca wierzchołek w przestrzeni 3d
 */
class vertex3f
{
public:
	typedef vector3f position_type;
    typedef vector3f normal_type;
    
    ///pozycja wierzchołka
    position_type position;

    ///normalna w wierzchołku
    normal_type normal;

    /**
     * @brief Domyslny konstruktor
     * Ustawia wszystkie wektory na ( 0, 0, 0 )
     */
    vertex3f( void ) {}

    /**
     * @brief Konstruktor ustawiajacy wspolrzedne
     * @param pos pozycja wierzchołka w przestrzeni
     * @param n normalna wierzcholka
     */
    explicit vertex3f( const position_type& pos, const normal_type& n  )
        : position( pos ), normal( n ) {}
};

/**
 * @struct vertex3f
 * @brief Struktura opisujaca oteksturowany wierzchołek w przestrzeni 3d
 */
class texvertex3f
{
public:
	typedef vector3f position_type;
    typedef vector2f texture_type;
    typedef vector3f normal_type;
    
	///pozycja wierzchołka
    position_type position;

	/// wspolrzedne tekstury
	texture_type texture;
	
    ///normalna w wierzchołku
    normal_type normal;   

    /**
     * @brief Domyslny konstruktor
     * Ustawia wszystkie wektory na ( 0, 0, 0 )
     */
    texvertex3f( void ) {}

    /**
     * @brief Konstruktor ustawiajacy wspolrzedne
     * @param pos pozycja wierzchołka w przestrzeni
     * @param n normalna wierzcholka
     */
    explicit texvertex3f( const position_type& pos, const texture_type &tex, const normal_type& n  )
		: position( pos ), texture( tex ), normal( n ) {}

};
