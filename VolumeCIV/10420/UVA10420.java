import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeSet;


public class Main {

    public static void main(String[] args) {
        String line, countryName, ladyName;
        Integer countryNumber;
        int n, spaceIndex;
        int nbLines = 0;
        HashMap<String, Integer> conquests = new HashMap<String, Integer>();
        BufferedReader bis = null;

        try {
            bis = new BufferedReader(new InputStreamReader(System.in));
            /*bis = new BufferedReader(new FileReader("input.txt"));*/
            line = bis.readLine();                              /* read the number of names */
            n = Integer.valueOf(line);
            /*check limits*/
            if (n<0 || n>2000)
                return;

            while (nbLines < n) {
                nbLines++;
                line = bis.readLine();
                spaceIndex = line.indexOf(" ");                 /* space index */
                countryName = line.substring(0, spaceIndex);    /* country name */
                ladyName = line.substring(spaceIndex+1);        /* lady name */

                countryNumber = conquests.get(countryName);
                if (countryNumber == null)
                    conquests.put(countryName, 1);              /* no entry in the hashmap */
                else                                            /* increase the number of conquests */
                    conquests.put(countryName, countryNumber.intValue()+1);
            }

            TreeSet<String> keys = new TreeSet<String>(conquests.keySet());
            for (String key : keys) {
                Integer value = conquests.get(key);
                System.out.println(key + " " + value);
                // do something
            }
            bis.close();
        } catch (IOException ex) {
        }
    }

}
