import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
    public static final String MOVE = "move";
    public static final String PILE = "pile";
    public static final String OVER = "over";
    public static final String ONTO = "onto";
    public static final String QUIT = "quit";
    public static final int MAX_NUMBER = 25;
    private static LinkedList<LinkedList<Integer>> blocks;
    private static int []indices;
    private static int blocksNumber;

    public static void moveAOntoB(int a, int b) {
        LinkedList<Integer> aList = blocks.get( indices[a] );
        LinkedList<Integer> bList = blocks.get( indices[b] );
        int posa, posb, nb;
        //move all blocks that are on top of a to their initial position
        posa = aList.indexOf(a);
        posb = bList.indexOf(b);

        while((nb = aList.removeLast()) != a) {
            blocks.get(nb).add(nb);
            indices[nb] = nb;
        }

        while((nb = bList.removeLast()) != b) {
            blocks.get(nb).add(nb);
            indices[nb] = nb;
        }
        bList.add(b);
        bList.add(a);
        indices[a] = indices[b];
    }

    public static void moveAOverB(int a, int b) {
        LinkedList<Integer> aList = blocks.get( indices[a] );
        LinkedList<Integer> bList = blocks.get( indices[b] );
        int posa, posb, nb;

        while((nb = aList.removeLast()) != a) {
            blocks.get(nb).add(nb);
            indices[nb] = nb;
        }
        bList.add(a);
        indices[a] = indices[b];
    }

    public static void pileAOntoB(int a, int b) {
        LinkedList<Integer> aList = blocks.get( indices[a] );
        LinkedList<Integer> bList = blocks.get( indices[b] );
        int i;
        int posa, posb, nb;

        while((nb = bList.removeLast()) != b) {
            blocks.get(nb).add(nb);
            indices[nb] = nb;
        }
        bList.add(b);

        posa = aList.indexOf(a);
        posb = aList.size();
        for(i=posa; i<posb; i++) {
            nb = aList.remove(posa);
            bList.add(nb);
            indices[nb] = indices[b];
        }
    }

    public static void pileAOverB(int a, int b) {
        LinkedList<Integer> aList = blocks.get( indices[a] );
        LinkedList<Integer> bList = blocks.get( indices[b] );
        int i, j;
        int posa, posb, nb;

        posa = aList.indexOf(a);
        posb = aList.size();

        for(i=posa; i<posb; i++) {
            nb = aList.remove(posa);
            bList.add(nb);
            indices[nb] = indices[b];
        }
    }

    public static void readInput() {
        String line;
        int i, j=0;
        Pattern pattern;
        Matcher matcher;

        try {
            BufferedReader bis = new BufferedReader(new InputStreamReader(System.in));
            line = bis.readLine();
            if(line.contains(QUIT))
                return;
            else {
                blocksNumber = Integer.parseInt(line);
                for(i=0; i<blocksNumber; i++) {
                    indices[i] = i;
                    LinkedList aux = new LinkedList();
                    aux.add(i);
                    blocks.add(aux);
                }
            }

            while((line = bis.readLine()) != null) {
                if(line.contains(QUIT))
                    break;

                pattern = Pattern.compile("\\d+");
                matcher = pattern.matcher(line);
                matcher.find();
                i = Integer.parseInt( matcher.group() );
                matcher.find();
                j = Integer.parseInt( matcher.group() );

                if((i != j) && (indices[i] != indices[j])) {
                    if(line.contains(MOVE)) {
                        if(line.contains(ONTO)) {
                            moveAOntoB(i, j);
                        } else
                            moveAOverB(i, j);
                    }
                    if(line.contains(PILE)) {
                        if(line.contains(ONTO)) {
                            pileAOntoB(i, j);
                        } else {
                            pileAOverB(i, j);
                        }
                    }
                }
            }
        } catch(Exception ex) {
            ex.printStackTrace();
        }
        print();
    }

    public static void print() {
        int i = 0;
        for(LinkedList<Integer> list : blocks) {
            System.out.print(i + ":");
            for(int in =0; in<list.size(); in++) {
                System.out.print(" " + list.get(in));
            }
            System.out.println();
            i++;
        }
    }

	
	public static void main(String []args) {
        blocks = new LinkedList<LinkedList<Integer>>();
        indices = new int[MAX_NUMBER];
        readInput();
    }
}
