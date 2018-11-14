import java.math.BigDecimal;
import java.util.Scanner;

public class highpress
{
    public static void main(String[] args)
    {
        Scanner escan = new Scanner(System.in);
        int cases;
        cases = escan.nextInt();
        String auxS, fin;
        while(cases > 0)
        {
            BigDecimal suma = new BigDecimal("0");
            while(escan.hasNext())
            {
                auxS = escan.next();
                if(auxS.charAt(0) == '0' && auxS.length() == 1)
                {
                    suma = suma.stripTrailingZeros();
                    fin = suma.toPlainString();
                    System.out.println(fin);
                    break;
                }
                else
                    suma = suma.add(new BigDecimal(auxS));
            }
            cases--;
        }
    }
}
