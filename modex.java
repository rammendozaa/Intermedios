import java.math.BigInteger;
import java.util.Scanner;

public class modex
{
    public static void main(String[] args)
    {
        int casos,igno;
        String base, exp, modu, res;
        Scanner escan = new Scanner(System.in);
        casos = escan.nextInt();
        while(casos > 0)
        {
            base = escan.next();
            exp = escan.next();
            modu = escan.next();
            BigInteger x = new BigInteger(base);
            BigInteger y = new BigInteger(exp);
            BigInteger n = new BigInteger(modu);
            BigInteger z = new BigInteger("1");
            z = x.modPow(y, n);
            System.out.println(z);
            casos--;
        }
        igno = escan.nextInt();
    }
}
