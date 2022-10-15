package service;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;

public class ReadService {
    private static ReadService INSTANCE = null;

    private ReadService() { }

    public static ReadService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new ReadService();
        }

        return INSTANCE;
    }

    public String readFromFile(String fileName){
        try {
            BufferedReader fileReader = Files.newBufferedReader(Paths.get(fileName));
            String fileText = "";
            String fileLine = "";
            while((fileLine = fileReader.readLine()) != null) {
                fileText += fileLine + "\n";
            }
            return fileText;
        } catch (NoSuchFileException e) {
            System.out.println("There is no file named " + fileName + ".");
        } catch (IOException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }
        return "";
    }
}
