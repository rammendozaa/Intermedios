import java.util.Scanner;
import java.math.BigInteger;

public class integerin
{
    public static void main(String[] args)
    {
        Scanner escan = new Scanner(System.in);
        String auxS;
        BigInteger suma = new BigInteger("0");
        while(escan.hasNext())
        {
            auxS = escan.next();
            suma = suma.add(new BigInteger(auxS));
        }
        System.out.println(suma);
    }
}
