import java.math.BigInteger;
import java.util.Scanner;

public class pseudoprime
{
    public static void main(String[] args)
    {
        String pe, aaa;
        int p,a;
        Scanner escan = new Scanner(System.in);
        while(escan.hasNext())
        {
            pe = escan.next();
            aaa = escan.next();
            if(pe.charAt(0) == '0' && aaa.charAt(0) == '0')
                System.exit(0);
            else
            {
                p = Integer.parseInt(pe);
                BigInteger PE = new BigInteger(pe);
                BigInteger AA = new BigInteger(aaa);
                int pseudo;
                BigInteger MO = new BigInteger("1");
                MO = AA.modPow(PE, PE);
                pseudo = MO.compareTo(AA);
                if(!isPrime(p) && pseudo == 0)
                    System.out.println("yes");
                else
                    System.out.println("no");
            }
        }
    }

    public static boolean isPrime(int n)
    {
        int root = (int)Math.sqrt((double)n);
        for(int i = 2 ; i <= root ; i++)
            if(n % i == 0)
                return false;
        return true;
    }
}
