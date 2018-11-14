import java.math.BigInteger;
import java.util.Scanner;

public class vE
{
    public static void main(String[] args)
    {
        String lim, base;
        int limI;
        Scanner escan = new Scanner(System.in);
        while(escan.hasNextInt())
        {
            limI = escan.nextInt();
            base = escan.next();
            lim = String.valueOf(limI);
            BigInteger N = new BigInteger(lim);
            BigInteger A = new BigInteger(base);
            BigInteger res = new BigInteger("0");
            BigInteger uno = new BigInteger("1");
            int un = 1;
            while(un <= limI)
            {
                res = res.add(uno.multiply(A.pow(un)));
                un++;
                uno = uno.add(new BigInteger("1"));
            }
            System.out.println(res);
        }
    }
}
