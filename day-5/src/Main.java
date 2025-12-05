import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

class Range {
    long start, end;

    Range(long s, long e) {
        start = s;
        end = e;
    }
}

public class Main {

    public static List<String> readData() {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the data file name: ");

        String fileName = scanner.nextLine();

        File dataFile = new File(fileName);
        List<String> lines = new ArrayList<String>();

        try (Scanner reader = new Scanner(dataFile)) {
            while (reader.hasNextLine()) {
                String data = reader.nextLine();
                lines.add(data);
            }
        } catch (FileNotFoundException e) {
            System.out.println("An error occured.");
            e.printStackTrace();
        }

        scanner.close();

        return lines;

    }

    public static void main(String[] args) {
        List<String> data = readData();

        List<Range> ranges = new ArrayList<>();
        List<String> ids = new ArrayList<>();
        boolean PARSING_IDS = false;

        Set<String> acceptedIds = new HashSet<>();
        List<Range> combined = new ArrayList<>();
        long total = 0;

        for (int i = 0; i < data.size(); i++) {
            System.out.println(data.get(i));
            if (data.get(i) == "") {
                PARSING_IDS = true;
                continue;
            }

            if (PARSING_IDS) {
                ids.add(data.get(i));
            } else {
                String[] parts = data.get(i).split("-");
                long start = Long.parseLong(parts[0]);
                long end = Long.parseLong(parts[1]);
                ranges.add(new Range(start, end));
            }
        }

        ranges.sort(Comparator.comparingLong(range -> range.start));

        for (int i = 0; i < ranges.size(); i++) {
            long start = ranges.get(i).start;
            long end = ranges.get(i).end;

            for (int j = 0; j < ids.size(); j++) {
                long currentId = Long.parseLong(ids.get(j));
                if (currentId >= start && currentId <= end) {
                    acceptedIds.add(Long.toString(currentId));
                }
            }
        }

        for (int i = 0; i < ranges.size(); i++) {
            if (combined.isEmpty()) {
                combined.add(ranges.get(i));
            } else {
                Range last = combined.get(combined.size() - 1);
                if (ranges.get(i).start <= last.end) {
                    last.end = Math.max(last.end, ranges.get(i).end);
                } else {
                    combined.add(ranges.get(i));
                }
            }
        }

        for (int i = 0; i < combined.size(); i++) {
            total += (combined.get(i).end - combined.get(i).start + 1);
        }

        System.out.println(acceptedIds.size() + " of the available ingredient IDs are fresh.");
        System.out.println(total + " are considered to be fresh.");
    }
}