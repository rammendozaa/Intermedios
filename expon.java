import java.math.BigDecimal;
import java.util.Scanner;

public class expon
{
  public static void main(String[] args)
  {
    String base, fin;
    int exp;
    Scanner escan = new Scanner(System.in);
    while(escan.hasNext())
    {
        base = escan.next();
        exp = escan.nextInt();
        BigDecimal este = new BigDecimal(base);
        BigDecimal res = new BigDecimal("1");
        res = este.pow(exp);
        res = res.stripTrailingZeros();
        fin = res.toPlainString();
        if(fin.charAt(0) == '0' && fin.charAt(1) == '.')
            System.out.println(fin.substring(1,fin.length()));
        else
            System.out.println(fin);
    }
    return;
  }
}
