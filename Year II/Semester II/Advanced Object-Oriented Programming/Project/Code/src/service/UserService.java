package service;

import interfaces.ReportInterface;
import model.Seller;
import model.User;
import repository.UserRepository;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class UserService implements ReportInterface {
    private static UserService INSTANCE = null;
    private final ReadService readService = ReadService.getInstance();
    private final WriteService writeService = WriteService.getInstance();

    private final UserRepository userRepository = new UserRepository();

    private final String fileName = "src/csvFiles/Users.csv";
//    private List<User> users = new ArrayList<>();

    private UserService() { }

    public static UserService getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new UserService();
        }

        return INSTANCE;
    }

    public void addUser(User user) {
        userRepository.addUser(user);
    }

    public User getUserById(Integer idUser) {
        return userRepository.getUserById(idUser);
    }

    public User getUserByUsername(String username) {
        return userRepository.getUserByUsername(username);
    }

    public List<User> getAllUsers() {
        return userRepository.getAllUsers();
    }

    public List<User> getUsersSortedByUsername() {
        return userRepository.getAllUsers().stream()
                .sorted(Comparator.comparing(User::getUsername))
                .collect(Collectors.toList());
    }

    public void updateUserById(Integer idUser, String field, String value) {
        userRepository.updateUserById(idUser, field, value);
    }

    public void deleteUserById(Integer idUser) {
        userRepository.deleteUserById(idUser);
    }

//    public User getUserById(Integer idUser) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (User user : users) {
//                if (user.getIdUser().equals(idUser)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return users.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public User getUserByUsername(String username) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (User user : users) {
//                if (user.getUsername().equals(username)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            return users.get(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//            return null;
//        }
//    }
//
//    public List<User> getAllUsers() { return users; }
//
//    public List<User> getUsersSortedByUsername() {
//        return users.stream()
//                .sorted(Comparator.comparing(User::getUsername))
//                .collect(Collectors.toList());
//    }
//
//    public void addUser(User user) {
//        users.add(user);
//    }
//
//    public void updateUserById(Integer idUser) {
//
//    }
//
//    public void deleteUserById(Integer idUser) {
//        try {
//            int currentPosition = 0, index = -1;
//            for (User user : users) {
//                if (user.getIdUser().equals(idUser)) {
//                    index = currentPosition;
//                    break;
//                }
//                ++currentPosition;
//            }
//            users.remove(index);
//        } catch (IndexOutOfBoundsException e) {
//            System.out.println(e.getClass() + " " + e.getMessage());
//        }
//    }

    @Override
    public void getReportInfo() {
        String[] users = readService.readFromFile(this.fileName).split("\n");

        try {
            for (String user : users) {
                String[] userInfo = user.split(",");
                System.out.println(String.join(" | ", userInfo));
//                if (userInfo[1].equalsIgnoreCase("seller")) {
//                    Seller seller = new Seller(Integer.parseInt(userInfo[0]), userInfo[1], userInfo[2], userInfo[3], userInfo[4], userInfo[5], userInfo[6], userInfo[7], userInfo[8]);
//                    this.users.add(seller);
//                } else if (userInfo[1].equalsIgnoreCase("buyer")) {
//                    Buyer buyer = new Buyer(Integer.parseInt(userInfo[0]), userInfo[1], userInfo[2], userInfo[3], userInfo[4], userInfo[5], userInfo[6]);
//                    this.users.add(buyer);
//                }
            }
        } catch (ArrayIndexOutOfBoundsException | NumberFormatException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }
    }

    @Override
    public void writeToReport() {
        // Deleting file contents
        try {
            new FileOutputStream(this.fileName).close();
        } catch (IOException e) {
            System.out.println(e.getClass() + " " + e.getMessage());
        }

        List<User> users = getAllUsers();

        String fileHeader = "Id,Type,First Name,Last Name,Username,Email,Password,Description,Phone Number";
        writeService.writeToFile(fileName, fileHeader);
        for (User user : users) {
            String userInfo =
                    user.getIdUser() + "," + user.getType() + "," + user.getFirstName() + "," +
                            user.getLastName() + "," + user.getUsername() + "," +
                            user.getEmail() + "," + user.getPassword();
            if (user.getType().equalsIgnoreCase("seller")) {
                userInfo += "," + ((Seller) user).getDescription() + "," + ((Seller) user).getPhoneNumber();
            }

            writeService.writeToFile(fileName, userInfo);
        }
    }
}
