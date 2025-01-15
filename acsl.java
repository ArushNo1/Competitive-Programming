import java.util.*;

public class acsl{
    //mapping between every ring sequence and score
    public static final TreeMap<String, Integer> ringScores = new TreeMap<>();
    static{
        ringScores.put("A", 1);
        ringScores.put("R", 1);
        ringScores.put("O", 3);
        ringScores.put("G", 3);
        ringScores.put("B", 6);
        ringScores.put("AO", 5);
        ringScores.put("OA", 5);
        ringScores.put("BO", 10);
        ringScores.put("OB", 10);
        ringScores.put("BG", 10);
        ringScores.put("GB", 10);
        ringScores.put("RG", 5);
        ringScores.put("GR", 5);
    };

    //reads in the tosses of one player and returns the score and the number of tosses
    public static Pair scoreToss(String toss){
        String[] tosses = toss.split(" ");
        int total = 0;
        for(String t : tosses){
            if(t.charAt(t.length() - 1) == '+'){
                //Check the extra distance case
                t = t.substring(0, t.length() - 1);
                total += 2;
            }
            total += ringScores.get(t);
            //read from the map above and get the corresponding score
        }
        return new Pair(total, tosses.length);
    }

    //final ACSL method
    public String scoreToss(int numPlayers, ArrayList<String> tosses){
        ArrayList<PlayerScore> playerScores = new ArrayList<>();
        //getting scoreinfo for each toss
        for(int i = 0; i < numPlayers; i++){
            PlayerScore ps = new PlayerScore();
            ps.index = i + 1;
            Pair result = scoreToss(tosses.get(i));
            ps.score = result.first;
            ps.numtosses = result.second;
            playerScores.add(ps);
        }

        //sorting the players by their scores, and then number of tosses if equal
        Collections.sort(playerScores);
        StringBuilder sb = new StringBuilder();
        for(PlayerScore ps : playerScores){
            sb.append(ps.index).append("-").append(ps.score).append(" ");
            //faster string concatenation, since java strings are immutable
        }
        return sb.toString();
    }

    public static class Pair{
        public int first;
        public int second;
        public Pair(int a, int b){
            first = a;
            second = b;
        }
    }

    class PlayerScore implements Comparable<PlayerScore>{
        public int index;
        public int score;
        public int numtosses;
        public PlayerScore(){
            index = 0;
            score = 0;
            numtosses = 0;
        }
        @Override
        public int compareTo(PlayerScore o){
            if(this.score != o.score) return o.score - this.score; // Descending order for second element
            if(this.numtosses != o.numtosses) return this.numtosses - o.numtosses; // Ascending order for third element
            return this.index - o.index; // Ascending order for first element
        }

    }
}