package service;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Paths;

public class WriteService {
    private static WriteService INSTANCE = null;

    private WriteService() { }

    public static WriteService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new WriteService();
        }

        return INSTANCE;
    }

    public void writeToFile(String fileName, String info){
        try {
            FileWriter fileWriter = new FileWriter(String.valueOf(Paths.get(fileName)), true);
            fileWriter.write(info + "\n");
            fileWriter.close();
        } catch (IOException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }
    }
}
