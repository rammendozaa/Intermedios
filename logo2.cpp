#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

// Punto en 2D.
struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }

    //Sumar los vectores actual y q.
    Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
    //Restar los vectores (o trasladarlos), tomando p como el origen.
    Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
    //Obtener el vector opuesto.
    Punto operator -() const { return Punto(-x, -y); }
    //Obtener el vector por un escalar.
    Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
    //Obtener el vector dividido por un escalar.
    Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
    //Magnitud del vector.
    Double Abs() const { return hypot(x, y); }
    //Magnitud elevada al cuadrado del vector.
    Double Norm() const{ return x*x + y*y; }
    //Distancia entre el punto actual y q.
    Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
    //Distancia elevada al cuadrado entre el punto actual y q.
    Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
    //Producto punto entre el punto actual y q.
    Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
    //Producto cruz entre el punto actual y q.
    Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

    //Rotar 90 grados en CCW.
    Punto rot90() const { return Punto(-y, x); }

    //Rotar t radianes en cw respecto al origen.
    Punto RotarCW(const Double& t) const {
      return Punto( x*cos(t) + y*sin(t),
              y*cos(t) - x*sin(t));
}

//Rotar t radianes en ccw respecto al origen.
Punto RotarCCW(const Double& t) const {
  return Punto( x*cos(t) - y*sin(t),
          y*cos(t) + x*sin(t));
}
};

//Conversion de grados a radianes.
Double GradARad(Double grd) {
return (grd * M_PI) / 180.0;
}

// Conversion de radianes a grados.
Double RadAGrad(Double rad) {
return (rad * 180.0) / M_PI;
}


int main(void)
{
    int cases, gradosAux, auxI, instruI;
    string auxS, instruS;
    cin >> cases;
    while(cases--)
    {
        Punto inicial = Punto(0,0), recorrido = Punto(0,0), dondeMuere, anterior = Punto(0,0);
        cin >> auxI;
        int distancia1, distancia2;
        bool soloDis = true;
        while(auxI--)
        {
            cin >> auxS;
            if(auxS[0] == 'f')
            {
                cin >> instruS;
                if(instruS[0] == '?')
                    instruI = 0;
                else
                    instruI = stoi(instruS);
                recorrido = recorrido + Punto(instruI,0);
            }
            else if(auxS[0] == 'l')
            {
                cin >> instruS;
                if(instruS[0] == '?')
                {
                    instruI = 0;
                    soloDis = false;
                }
                else
                    instruI = stoi(instruS);
                recorrido = recorrido.RotarCCW(GradARad(instruI));
            }
            else if(auxS[0] == 'r')
            {
                cin >> instruS;
                if(instruS[0] == '?')
                {
                    finstruI = 0;
                    soloDis = false;
                }
                else
                    instruI = stoi(instruS);
                recorrido = recorrido.RotarCW(GradARad(instruI));
            }
            else if(auxS[0] == 'b')
            {
                cin >> instruS;
                if(instruS[0] == '?')
                    instruI = 0;
                else
                    instruI = stoi(instruS);
                recorrido = recorrido - Punto(instruI,0);
            }
        }
        if(soloDis)
            cout << (int)round(recorrido.Dist(inicial)) << "\n";
        else
            cout << 180 - (RadAGrad(Angulo(recorrido, dondeMuere, Punto(0,0)))) << "\n";



        //ya esta para cuando ? aparece despues de una distancia, solo es el resultado
        //falta para encontrar el angulo
        if(fabs(recorrido.x) < ERROR)
            recorrido.x = 0;
        if(fabs(recorrido.y) < ERROR)
            recorrido.y = 0;
        int distancia3 = (int)round(recorrido.Dist(Punto(0,0)));
        cout << recorrido.x << " " << recorrido.y << "\n";
        cout << distancia3 << "\n";
    }

}
