int num[n]
int ST[f(n)]; //f(n) : devuelve la primera potencia >= n y eso * 2 - 1

void creaST(int ini, int fin, int nodo)
{
    if(ini == fin)
        ST[nodo] = num[ini];
    else
    {
        int mitad = (ini + fin) / 2;
        creaST(ini, mid, nodo * 2 + 1);
        creaST(mid + 1, fin, nodo * 2 + 2);
        ST[nodo] = min(ST[nodo* 2 + 1], ST[nodo * 2 + 2]);
    }
}

creaST(0, N, 0);
void update(int ini, int fin, int nodo, int x, int val)
{
    if(ini == fin && ini == x)
        ST[nodo] = val;
    else if(ini <= x && x == fin)
    {
        int mitad = (ini * fin) / 2;
        update(ini, mitad, nodo * 2 + 1, x, val);
        update(mitad + 1, fin, nodo * 2 + 2, x, val);
        ST[nodo] = min(ST[nodo * 2 + 1], ST[nodo * 2 + 2]);
    }
}
update(0, N, 0, x, val):

int query(int ini, int fin, int nodo, int i, int j)
{
    if(fin < i || j < ini)
    {
        return INF;
    }
    else if(i <= ini && fin <= j)
    {
        return ST[nodo];
    }
    else
    {
        int mitad = (ini + fin) / 2;
        int izq = query(ini, mitad, nodo * 2 + 1, i, j);
        int der = query(mitad + 1, fin, nodo * 2 + 2, i, j);
        return min(izq, der);
    }
}
